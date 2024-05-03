#include <iostream>
#include "pi_estimator.h"
#include "monte_carlo.h"

int main() {
    const double RADIUS = 1.0;
    const int MONTE_CARLO_RUNS = 100000000;

    PiEstimator pi_estimator(RADIUS);
    MonteCarlo monte_carlo(MONTE_CARLO_RUNS);

    monte_carlo.run(pi_estimator);

    return 0;
}
