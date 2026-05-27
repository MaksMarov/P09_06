#include <stdio.h>
#include <stdlib.h>

#include "data_process.h"
#include "data_io.h"

int main() {
    double *data = NULL;
    int n;

    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("n/a");
        return 1;
    }

    data = malloc(n * sizeof(double));
    if (!data) {
        printf("n/a");
        return 1;
    }

    input(data, n);

    if (normalization(data, n))
        output(data, n);
    else
        printf("ERROR");

    free(data);
    return 0;
}