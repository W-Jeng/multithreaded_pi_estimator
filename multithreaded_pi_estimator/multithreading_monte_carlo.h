#pragma once

#include<vector>
#include<thread>
#include "monte_carlo.h"
#include "pi_estimator.h"

class MultithreadingMonteCarlo{
public:
    MultithreadingMonteCarlo(const long& temp_num_of_runs,const int& temp_num_of_threads);

private:
    const long num_of_runs;
    const int num_of_threads;
    std::vector<std::thread> threads;
    std::vector<MonteCarlo> mc_vec;
};