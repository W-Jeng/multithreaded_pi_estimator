#include <iostream>
#include "pi_estimator.h"
#include "monte_carlo.h"

int main() {
    const double radius = 1.0;
    const int monte_carlo_runs = 100000000;

    PiEstimator pi_estimator(radius);
    MonteCarlo monte_carlo(monte_carlo_runs);

    monte_carlo.run(pi_estimator);

    return 0;
}
