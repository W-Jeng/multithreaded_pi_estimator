#pragma once

#include "pi_estimator.h"
#include <random>
#include <iostream>

class MonteCarlo {
public:
    MonteCarlo(const long& temp_num_of_runs);
    void run(PiEstimator& pi_estimator);
private:
    double random_number_generator(const double& lower_limit,const double& upper_limit);
    const long& num_of_runs;
};