#include <stdio.h>
#include <stdlib.h>

#include "data_io.h"
#include "data_process.h"
#include "data_stat.h"
#include "decision.h"

int main(void) {
    double* data = NULL;
    int n;

    printf("LOAD DATA...\n");

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

    printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    if (normalization(data, n)) {
        output(data, n);
    } else {
        printf("ERROR");
        free(data);
        return 1;
    }

    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort(data, n);
    output(data, n);

    printf("\nFINAL DECISION:\n\t");
    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");

    free(data);
    return 0;
}