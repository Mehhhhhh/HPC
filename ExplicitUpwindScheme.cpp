#include "ExplicitUpwindScheme.h"

using namespace equation::scheme;

ExplicitUpwindScheme::ExplicitUpwindScheme(double(*_Initial_Function)(double x, double u), double(*_Analytical_Function)(double x, double t, double u),
	double _LowerBoundary, double _UpperBoundary, double _Time_Level, int _GridSize, double _u, double _CFL, int _Left_BoundaryValue,
	int _Right_BoundaryValue) : ExplicitScheme(_Initial_Function, _Analytical_Function, "Explicit Upwind scheme", _LowerBoundary, _UpperBoundary, _Time_Level, _GridSize
		, _u, _CFL, _Left_BoundaryValue, _Right_BoundaryValue)
{

}

void ExplicitUpwindScheme::GetExplicitValue() {
	Next_step.push_back(Left_BoundaryValue);
	for (int i = 1; i < GridSize-1; i++) {
		Next_step.push_back(This_step[i] - CFL*(This_step[i] - This_step[i - 1]));
	}
	Next_step.push_back(Right_BoundaryValue);
	NumericalValues = Next_step;
	This_step = Next_step;
	Next_step.clear();
}

