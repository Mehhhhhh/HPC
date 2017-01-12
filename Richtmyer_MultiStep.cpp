#include "Richtmyer_MultiStep.h"
#include <cmath>

using namespace equation::scheme;

Richtmyer_MultiStep::Richtmyer_MultiStep(double(*_Initial_Function)(double x, double u), double(*_Analytical_Function)(double x, double t, double u),
	double _LowerBoundary, double _UpperBoundary, double _Time_Level, int _GridSize, double _u, double _CFL, int _Left_BoundaryValue,
	int _Right_BoundaryValue) : ExplicitScheme(_Initial_Function, _Analytical_Function, "Richtmyer MultiStep scheme", _LowerBoundary, _UpperBoundary, _Time_Level
		, _GridSize, _u, _CFL, _Left_BoundaryValue, _Right_BoundaryValue)
{

}

void Richtmyer_MultiStep::GetExplicitValue() {
	double temp1, temp2;
	Next_step.push_back(Left_BoundaryValue);
	Next_step.push_back(Left_BoundaryValue);
	for (int i = 2; i < GridSize - 2; i++) {
		temp1 = 1.0 / 2.0*(This_step[i + 2] + This_step[i]) - (u*DeltaTime / (4.0 * DeltaSpace))*(This_step[i + 2] - This_step[i]);
		temp2 = 1.0 / 2.0*(This_step[i - 2] + This_step[i]) - (u*DeltaTime / (4.0 * DeltaSpace))*(This_step[i] - This_step[i - 2]);
		Next_step.push_back(This_step[i] - (u*DeltaTime / (2.0 * DeltaSpace))*(temp1 - temp2));
	}
	Next_step.push_back(Right_BoundaryValue);
	Next_step.push_back(Right_BoundaryValue);
	NumericalValues = Next_step;
	This_step = Next_step;
	Next_step.clear();
}

