#include "Functions.h"

using namespace equation;

int Functions::Sign(double x) {
	if (x < 0) {
		return -1;
	}
	else if (x == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

double Functions::Signum(double x, double t, double u){
	return 1.0 / 2.0 * (Sign(x - u*t) + 1);
}

double Functions::Exponential(double x, double t, double u){
	return 1.0 / 2.0 * exp(-pow((x - u*t), 2));
}

double Functions::Signum_Initial(double x, double u) {
	return 1.0 / 2.0 * (Sign(x) + 1);
}

double Functions::Exponential_Initial(double x, double u) {
	return 1.0 / 2.0 * exp(-pow((x), 2));
}