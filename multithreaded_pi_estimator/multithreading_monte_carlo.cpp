#include "multithreading_monte_carlo.h"


MultithreadingMonteCarlo::MultithreadingMonteCarlo(const long& temp_num_of_runs,const int& temp_num_of_threads):
    num_of_runs(temp_num_of_runs),num_of_threads(temp_num_of_threads) {

    // PiEstimator pi_estimator(1.0);
    std::vector<PiEstimator> pi_estimators(num_of_threads,PiEstimator(1.0));
    const int thread_num_of_runs = num_of_runs/num_of_threads;
    int leftover_mc_runs = num_of_runs;
    int target_runs_per_thread;
    std::vector<double*> pi_estimation_list;
    std::vector<double> pi_estimations(num_of_threads);

    for(int i = 0; i < num_of_threads; ++i) {
        if(i != num_of_threads-1) {
            target_runs_per_thread = thread_num_of_runs;
            leftover_mc_runs -= thread_num_of_runs;
        } else {
            target_runs_per_thread = leftover_mc_runs;
        }

        MonteCarlo monte_carlo;
        mc_vec.push_back(monte_carlo);
        std::thread mc_thread(&MonteCarlo::run,mc_vec.back(),std::ref(pi_estimators[i]),target_runs_per_thread,std::ref(pi_estimations[i]));
        threads.push_back(std::move(mc_thread));
        pi_estimation_list.push_back(&pi_estimations[i]);
    }

    for(auto& thread : threads) {
        thread.join();
    }

    double pi_estimation = 0;

    for(int i = 0; i < pi_estimation_list.size(); ++i) {
        pi_estimation += *pi_estimation_list[i];
        // std::cout << "mem address: " << pi_estimation_list[i] << ", mem val: " << *pi_estimation_list[i] << "\n";
    }
    pi_estimation = pi_estimation/pi_estimation_list.size();
    std::cout << "Multithreaded pi estimation: " << pi_estimation << "\n";

};