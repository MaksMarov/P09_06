#include "decision.h"

#include <math.h>

#include "data_stat.h"

int make_decision(double* data, int n) {
    double m = mean(data, n);
    double var = variance(data, n);
    double sigma = (var > 0) ? sqrt(var) : 0;

    double max_value = max(data, n);

    int decision = (max_value <= m + 3 * sigma) && (max_value >= m - 3 * sigma) && (m >= GOLDEN_RATIO);

    return decision;
}