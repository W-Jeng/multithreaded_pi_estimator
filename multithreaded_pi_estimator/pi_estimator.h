#pragma once

class PiEstimator {
public:
				PiEstimator(const double& temp_radius);
				void refine_estimation(const double x,const double y);
				const double get_pi_estimation();
				const double& get_upper_limit();
				const double& get_lower_limit();
private:
				bool is_in_circle(const double x,const double y);
				const double& radius;
				const double square_area;
				int num_of_estimator;
				int is_in_circle_count;
};