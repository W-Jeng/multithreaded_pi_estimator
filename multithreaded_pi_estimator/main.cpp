#include <iostream>
#include "pi_estimator.h"
#include "monte_carlo.h"
#include "multithreading_monte_carlo.h"

int main() {
    const double RADIUS = 1.0;
    long MONTE_CARLO_RUNS = 1000;
    int THREADS = 5;
    // PiEstimator pi_estimator(RADIUS);
    // MonteCarlo monte_carlo(MONTE_CARLO_RUNS);

    // monte_carlo.run(pi_estimator);

    MultithreadingMonteCarlo mmc(MONTE_CARLO_RUNS,THREADS);

    return 0;
}
