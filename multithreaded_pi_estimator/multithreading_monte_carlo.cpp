#include "multithreading_monte_carlo.h"

MultihreadingMonteCarlo::MultihreadingMonteCarlo(const long& temp_num_of_runs,const int& temp_num_of_threads): 
    num_of_runs(temp_num_of_runs),num_of_threads(temp_num_of_threads) {

    const int thread_splits_lower = num_of_runs/num_of_threads;

    for (int i = 0; i < num_of_threads; ++i) {
        thread_runs.push_back(thread_splits_lower);
    }
};