#include <stdio.h>
#include <stdlib.h>

#include "decision.h"
#include "data_io.h"

int main()
{
    double *data;
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

    
    if (make_decision(data, n))
        printf("YES"); 
    else
        printf("NO");  

    free(data);
    return 0;
}