#pragma once

class PiEstimator {
public:
				PiEstimator(const double& temp_radius);
				bool is_in_circle(const double& x, const double& y);

private:
				const double radius;
				const double square_area;

};