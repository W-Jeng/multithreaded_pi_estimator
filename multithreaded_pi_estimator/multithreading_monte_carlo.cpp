#include "multithreading_monte_carlo.h"


MultithreadingMonteCarlo::MultithreadingMonteCarlo(const long& temp_num_of_runs, const int& temp_num_of_threads):
    num_of_runs(temp_num_of_runs),num_of_threads(temp_num_of_threads) {
    
    PiEstimator pi_estimator(1.0);

    const int thread_num_of_runs = num_of_runs/num_of_threads;
    int leftover_mc_runs = num_of_runs;
    int target_runs_per_thread;

    for (int i = 0; i < num_of_threads; ++i) {
        if (i != num_of_threads-1) {
            target_runs_per_thread = thread_num_of_runs;
            leftover_mc_runs -= thread_num_of_runs;
        } else {
            target_runs_per_thread = leftover_mc_runs;
        }

        MonteCarlo monte_carlo(target_runs_per_thread);
        
        mc_vec.push_back(monte_carlo);
        // std::thread mc_thread(&MonteCarlo::run, &mc_vec.back(), pi_estimator);
        // threads.push_back(std::move(mc_thread));
        
    }
    /*
    for(auto& thread : threads) {
        thread.join();
    }
    */
};