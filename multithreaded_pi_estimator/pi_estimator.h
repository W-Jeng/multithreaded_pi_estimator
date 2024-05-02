#pragma once

class PiEstimator {
public:
				PiEstimator(const double& temp_radius);
				bool is_in_circle(const double& x, const double& y);
				void refine_estimation(const double& x, const double& y);
				const double& get_pi_estimation();

private:
				const double radius;
				const double square_area;
				int num_of_estimator;
				int is_in_circle_count;
};