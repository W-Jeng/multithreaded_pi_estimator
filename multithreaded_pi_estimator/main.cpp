#include <iostream>
#include "pi_estimator.h"
#include "monte_carlo.h"

int main() {
    PiEstimator pi_estimator(1.0);
    MonteCarlo monte_carlo(100000000);

    monte_carlo.run(pi_estimator);

    return 0;
}
