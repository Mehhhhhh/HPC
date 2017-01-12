#include "Lax_Wendroff.h"
#include <cmath>

using namespace equation::scheme;

Lax_Wendroff::Lax_Wendroff(double(*_Initial_Function)(double x, double u), double(*_Analytical_Function)(double x, double t, double u),
	double _LowerBoundary, double _UpperBoundary, double _Time_Level, int _GridSize, double _u, double _CFL, int _Left_BoundaryValue,
	int _Right_BoundaryValue) : ExplicitScheme(_Initial_Function, _Analytical_Function, "Lax-wandroff scheme", _LowerBoundary, _UpperBoundary, _Time_Level
		, _GridSize, _u, _CFL, _Left_BoundaryValue, _Right_BoundaryValue)
{

}

void Lax_Wendroff::GetExplicitValue() {
	Next_step.push_back(Left_BoundaryValue);
	for (int i = 1; i < GridSize - 1; i++) {
		Next_step.push_back(u*(DeltaTime / (2 * DeltaSpace))*(This_step[i - 1] - This_step[i + 1]) + pow(u, 2)*(pow(DeltaTime, 2) / (2 * pow(DeltaSpace, 2)))
			*(This_step[i - 1] + This_step[i + 1] - 2 * This_step[i]) + This_step[i]);
	}
	Next_step.push_back(Right_BoundaryValue);
	NumericalValues = Next_step;
	This_step = Next_step;
	Next_step.clear();
}

