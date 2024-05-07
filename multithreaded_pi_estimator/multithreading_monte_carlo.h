#pragma once

#include<vector>
#include<thread>
#include "monte_carlo.h"

class MultihreadingMonteCarlo{
public:
    MultihreadingMonteCarlo(const long& temp_num_of_runs, const int& num_of_threads);

private:
    const long& num_of_runs;
    const int& num_of_threads;
    std::vector<std::thread> thread_list;
    std::vector<int> thread_runs;
};