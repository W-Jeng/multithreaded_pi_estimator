#pragma once

#include "pi_estimator.h"
#include <random>
#include <iostream>
#include <chrono>

class MonteCarlo {
public:
    MonteCarlo();
    void run(PiEstimator& pi_estimator, const long num_of_runs, double& pi_estimation);
// private:
    // double random_number_generator(const double& lower_limit,const double& upper_limit);
};