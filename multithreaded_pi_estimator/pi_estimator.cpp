#include "pi_estimator.h"
#include<cmath>

PiEstimator::PiEstimator(const double& temp_radius) :radius(temp_radius), square_area(temp_radius*temp_radius) {};

bool PiEstimator::is_in_circle(const double& x, const double& y) {
    if (pow(pow(x, 2) + pow(y, 2), 0.5) < radius)
        return true;
    else
        return false;
};

