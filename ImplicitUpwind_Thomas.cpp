#include "ImplicitUpwind_Thomas.h"

using namespace equation::scheme;

ImplicitUpwind_Thomas::ImplicitUpwind_Thomas(double(*_Initial_Function)(double x, double u), double(*_Analytical_Function)(double x, double t, double u),
	double _LowerBoundary, double _UpperBoundary, double _Time_Level, int _GridSize, double _u, double _CFL, int _Left_BoundaryValue,
	int _Right_BoundaryValue) : ImplicitScheme(_Initial_Function, _Analytical_Function, "Implicit Upwind", _LowerBoundary, _UpperBoundary,
		_Time_Level, _GridSize, _u, _CFL, _Left_BoundaryValue, _Right_BoundaryValue)
{
	Initialise_Matrix();
}


void ImplicitUpwind_Thomas::Initialise_Matrix() {
	coefficient_a.push_back(0);
	for (int i = 0; i < GridSize - 1; i++) {
		for (int j = 0; j < GridSize - 1; j++) {
			if (i == j) {
				coefficient_b.push_back(1+CFL);
			}
			else if (i - 1 == j) {
				coefficient_a.push_back(-CFL);
			}
			else if (i + 1 == j) {
				coefficient_c.push_back(0);
			}
		}
	}
	coefficient_c.push_back(0);
	coefficient_d.push_back(coefficient_c[0] / coefficient_b[0]);
	for (int i = 1; i < GridSize - 2; i++) {
		coefficient_d.push_back(coefficient_c[i] / (coefficient_b[i] - coefficient_a[i] * coefficient_d[i - 1]));
	}
}

void ImplicitUpwind_Thomas::GetImplicitValue() {
	std::vector<double> next_time(GridSize - 1);
	std::vector<double> this_time;
	Generate_Vector(this_time);
	coefficient_e.push_back(this_time[0] / coefficient_b[0]);
	for (int i = 1; i < GridSize - 1; i++) {
		coefficient_e.push_back((this_time[i] - coefficient_a[i] * coefficient_e[i - 1]) / (coefficient_b[i] - coefficient_a[i] * coefficient_d[i - 1]));
	}
	next_time[GridSize - 2] = coefficient_e[GridSize - 2];
	for (int i = GridSize - 3; i >= 0; i--) {
		next_time[i] = coefficient_e[i] - coefficient_d[i] * next_time[i + 1];
	}
	Next_step.push_back(Left_BoundaryValue);
	for (int i = 0; i < GridSize - 2; i++) {
		Next_step.push_back(next_time[i]);
	}
	Next_step.push_back(Right_BoundaryValue);
	coefficient_e.clear();
	NumericalValues = Next_step;
	This_step = Next_step;
	Next_step.clear();
}


void ImplicitUpwind_Thomas::Generate_Vector(std::vector<double>& this_time) {
	this_time.push_back(This_step[1] + CFL*Left_BoundaryValue);
	for (int i = 2; i < GridSize; i++) {
		this_time.push_back(This_step[i]);
	}
}