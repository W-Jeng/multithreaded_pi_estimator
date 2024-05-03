#include "monte_carlo.h"

MonteCarlo::MonteCarlo(const long& temp_num_of_runs): num_of_runs(temp_num_of_runs) {};

void MonteCarlo::run(PiEstimator& pi_estimator) {
    // generate random numbers
    double x_coordinate;
    double y_coordinate;

    static const double pi_lower_limit = pi_estimator.get_lower_limit();
    static const double pi_upper_limit = pi_estimator.get_upper_limit();

    for (long i = 0; i < num_of_runs; ++i) {
        x_coordinate = random_number_generator(pi_lower_limit, pi_upper_limit);
        y_coordinate = random_number_generator(pi_lower_limit,pi_upper_limit);
        pi_estimator.refine_estimation(x_coordinate, y_coordinate);
    }
    std::cout << "pi estimation: " <<  pi_estimator.get_pi_estimation() << "\n";
};

double MonteCarlo::random_number_generator(const double& lower_limit, const double& upper_limit) {
    static std::default_random_engine random_generator;
    static std::uniform_real_distribution<float> distribution (lower_limit, upper_limit);

    return distribution(random_generator);
};