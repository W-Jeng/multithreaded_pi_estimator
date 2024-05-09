#include <iostream>
#include "pi_estimator.h"
#include "monte_carlo.h"
#include "multithreading_monte_carlo.h"
#include <chrono>

int main() {
    const double RADIUS = 1.0;
    long MONTE_CARLO_RUNS = 100000000;
    int THREADS = 10;

    auto start_time1 = std::chrono::high_resolution_clock::now();
    PiEstimator pi_estimator(RADIUS);
    MonteCarlo monte_carlo;
    double pi_estimation;
    monte_carlo.run(pi_estimator, MONTE_CARLO_RUNS, pi_estimation);
    auto end_time1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> runtime1 = end_time1 - start_time1;
    std::cout << "Single threaded Pi Estimation: " << pi_estimation << std::endl;;
    std::cout << "Single threaded runtime: " << runtime1.count() << " seconds\n";
    
    
    auto start_time2 = std::chrono::high_resolution_clock::now();
    MultithreadingMonteCarlo mmc(MONTE_CARLO_RUNS,THREADS);
    auto end_time2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> runtime2 = end_time2 - start_time2;
    std::cout << "Multithreaded runtime: " << runtime2.count() << " seconds\n";
    
    return 0;
}
