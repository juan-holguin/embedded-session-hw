#include "sensor.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

static double *values = NULL;
static size_t n_values = 0;
static size_t idx = 0;
static int use_csv = 0;

void sensor_init(void) {
    const char *fname = "tests/sensor_feed.csv";
    FILE *f = fopen(fname, "r");
    if (f) {
        char line[256];
        /* primera pasada: contar */
        size_t count = 0;
        while (fgets(line, sizeof(line), f)) {
            char *s = line;
            while (*s == ' ' || *s == '\t') s++;
            if (*s == '\0' || *s == '\n' || *s == '#') continue;
            count++;
        }
        if (count > 0) {
            values = malloc(sizeof(double) * count);
            if (values) {
                rewind(f);
                size_t i = 0;
                while (fgets(line, sizeof(line), f)) {
                    double v;
                    if (sscanf(line, "%lf", &v) == 1) {
                        values[i++] = v;
                    }
                }
                n_values = i;
                if (n_values > 0) use_csv = 1;
            }
        }
        fclose(f);
    }
    if (!use_csv) {
        /* si no hay CSV, usar RNG */
        srand((unsigned)time(NULL));
    }
}

double sensor_read(void) {
    if (use_csv && n_values > 0) {
        double v = values[idx % n_values];
        idx++;
        return v;
    } else {
        /* valor aleatorio entre 0 y 100 */
        return ((double)rand() / (double)RAND_MAX) * 100.0;
    }
}
