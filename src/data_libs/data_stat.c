#include "data_stat.h"

#include <math.h>

double max(double* data, int n) {
    double mx = data[0];

    for (int i = 1; i < n; i++) {
        if (data[i] > mx) mx = data[i];
    }

    return mx;
}

double min(double* data, int n) {
    double mn = data[0];

    for (int i = 1; i < n; i++) {
        if (data[i] < mn) mn = data[i];
    }

    return mn;
}

double mean(double* data, int n) {
    double sum = 0.0;

    for (int i = 0; i < n; i++) sum += data[i];

    return sum / n;
}

double variance(double* data, int n) {
    double m = mean(data, n);
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        double diff = data[i] - m;
        sum += diff * diff;
    }

    return sum / n;
}

static void swap(double* a, double* b) {
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

static double* partition(double* l, double* r) {
    double pivot = *(l + (r - l) / 2);

    double* i = l - 1;
    double* j = r + 1;

    while (1) {
        do {
            i++;
        } while (*i < pivot);
        do {
            j--;
        } while (*j > pivot);

        if (i >= j) return j;

        swap(i, j);
    }
}

static void quick_sort(double* l, double* r) {
    if (l >= r) return;

    double* p = partition(l, r);

    quick_sort(l, p);
    quick_sort(p + 1, r);
}

void sort(double* data, int n) {
    if (n <= 1) return;

    quick_sort(data, data + n - 1);
}