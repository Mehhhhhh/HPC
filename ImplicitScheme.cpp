#include "ImplicitScheme.h"

using namespace equation::scheme;

ImplicitScheme::ImplicitScheme(double(*_Initial_Function)(double x, double u), double(*_Analytical_Function)(double x, double t, double u),
	std::string _name, double _LowerBoundary, double _UpperBoundary, double _Time_Level, int _GridSize, double _u, double _CFL, int _Left_BoundaryValue,
	int _Right_BoundaryValue) : AbstractScheme(_Initial_Function, _Analytical_Function, _name, _LowerBoundary, _UpperBoundary,
		_Time_Level, _GridSize, _u, _CFL, _Left_BoundaryValue, _Right_BoundaryValue)
{

}

void equation::scheme::ImplicitScheme::GetValues()
{
	GetImplicitValue();
}

