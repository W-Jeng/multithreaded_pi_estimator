#include "pi_estimator.h"
#include<cmath>
#include<iostream>

PiEstimator::PiEstimator(const double& temp_radius):radius(temp_radius),square_area(4*temp_radius*temp_radius),num_of_estimator(0),is_in_circle_count(0) {};

void PiEstimator::refine_estimation(const double x,const double y) {
    num_of_estimator++;
    if(PiEstimator::is_in_circle(x,y)) {
        is_in_circle_count++;
    }
    return;
};

bool PiEstimator::is_in_circle(const double x,const double y) {
    if(pow(pow(x,2) + pow(y,2),0.5) < radius*0.5)
        return true;
    else
        return false;
};

const double& PiEstimator::get_upper_limit() {
    return radius*0.5;
}

const double& PiEstimator::get_lower_limit() {
    return -radius*0.5;
}

const double PiEstimator::get_pi_estimation() {
    double area_circle = (static_cast<double>(is_in_circle_count)/num_of_estimator) * square_area;
    return area_circle/(radius*radius);
};