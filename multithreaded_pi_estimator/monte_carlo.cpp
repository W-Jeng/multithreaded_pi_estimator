#include "monte_carlo.h"
#include <chrono>

MonteCarlo::MonteCarlo(){};

void MonteCarlo::run(PiEstimator& pi_estimator,const long num_of_runs,double& pi_estimation) {
    // generate random numbers

    double x_coordinate;
    double y_coordinate;

    static const double pi_lower_limit = pi_estimator.get_lower_limit();
    static const double pi_upper_limit = pi_estimator.get_upper_limit();

    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::default_random_engine random_generator(seed);
    std::uniform_real_distribution<float> distribution (pi_lower_limit,pi_upper_limit);


    for(long i = 0; i < num_of_runs; ++i) {
        x_coordinate = distribution(random_generator);
        y_coordinate = distribution(random_generator);
        pi_estimator.refine_estimation(x_coordinate,y_coordinate);
    }
    pi_estimation = pi_estimator.get_pi_estimation();
    // std::cout << "pi estimation: " << pi_estimator.get_pi_estimation() << "\n";
    return;
};
/*
double MonteCarlo::random_number_generator(const double& lower_limit,const double& upper_limit) {

    static unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    static std::default_random_engine random_generator(seed);
    static std::uniform_real_distribution<float> distribution (lower_limit,upper_limit);

    return distribution(random_generator);
};
*/