#include "Norms.h"

using namespace equation;

double Norms::Norms_1(const std::vector<double>& vec) {
	double sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		sum = sum + abs(vec[i]);
	}
	return sum;
}

double Norms::Norms_2(const std::vector<double>& vec) {
	double sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		sum = sum + pow(vec[i], 2);
	}
	return pow(sum, 1.0 / 2.0);
}

double Norms::Norms_Max(const std::vector<double>& vec) {
	double max = 0;
	for (int i = 0; i < vec.size(); i++) {
		max = fmax(max, abs(vec[i]));
	}
	return max;
}