#include <stdio.h>

#include "data_io.h"

void input(double *data, int n) {
    for (int i = 0; i < n; i++) {
        if (scanf("%lf", &data[i]) != 1) {
            data[i] = 0.0;
        }
    }
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f", data[i]);

        if (i < n - 1) {
            printf(" ");
        }
    }
}