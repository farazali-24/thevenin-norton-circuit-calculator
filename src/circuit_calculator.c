/*
 * Thevenin and Norton Equivalent Circuit Calculator
 * Two predefined circuit configurations: voltage-source divider and
 * current-source parallel resistors.
 */
#include <stdio.h>
#include <stdlib.h>

static int read_positive(const char *prompt, float *result) {
    char line[128];
    char extra;
    for (;;) {
        printf("%s", prompt);
        if (!fgets(line, sizeof line, stdin)) return 0;
        if (sscanf(line, " %f %c", result, &extra) == 1 && *result > 0.0f)
            return 1;
        puts("Error: enter a positive number.");
    }
}

/* Circuit 1: voltage divider. The output is taken across R1. */
static float calculate_vt(float v, float r1, float r2) {
    return v * (r1 / (r1 + r2));
}

/* Source set to zero: R1 and R2 are in parallel as seen at the output. */
static float calculate_rt(float r1, float r2) {
    return (r1 * r2) / (r1 + r2);
}

static float calculate_in(float vt, float rt) {
    return vt / rt;
}

/* Circuit 2: current source feeding two parallel resistors. */
static void calculate_circuit2(float current, float r1, float r2,
                               float *vt, float *rt, float *in, float *rn) {
    *rt = (r1 * r2) / (r1 + r2);
    *vt = current * *rt;
    *in = current;
    *rn = *rt;
}

int main(void) {
    char line[128];
    int choice;
    float v, current, r1, r2, vt, rt, in, rn;
    for (;;) {
        puts("\nThevenin / Norton Equivalent Calculator");
        puts("1. Voltage-source circuit");
        puts("2. Current-source circuit");
        puts("0. Exit");
        printf("Enter your choice: ");
        if (!fgets(line, sizeof line, stdin)) break;
        char extra;
        if (sscanf(line, " %d %c", &choice, &extra) != 1 ||
            (choice != 0 && choice != 1 && choice != 2)) {
            puts("Invalid choice. Enter 1, 2 or 0.");
            continue;
        }
        if (choice == 0) break;
        if (choice == 1) {
            if (!read_positive("Voltage V (volts): ", &v) ||
                !read_positive("Resistance R1 (ohms): ", &r1) ||
                !read_positive("Resistance R2 (ohms): ", &r2)) break;
            rt = calculate_rt(r1, r2);
            vt = calculate_vt(v, r1, r2);
            in = calculate_in(vt, rt);
            rn = rt;
        } else {
            if (!read_positive("Current I (amperes): ", &current) ||
                !read_positive("Resistance R1 (ohms): ", &r1) ||
                !read_positive("Resistance R2 (ohms): ", &r2)) break;
            calculate_circuit2(current, r1, r2, &vt, &rt, &in, &rn);
        }
        printf("\nVt: %.3f V\nRt: %.3f ohms\nIn: %.3f A\nRn: %.3f ohms\n",
               vt, rt, in, rn);
    }
    return 0;
}
