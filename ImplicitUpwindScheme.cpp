#include "ImplicitUpwindScheme.h"

using namespace equation::scheme;

ImplicitUpwindScheme::ImplicitUpwindScheme(double (*_Initial_Function)(double x, double u), double (*_Analytical_Function)(double x, double t, double u),
	double _LowerBoundary, double _UpperBoundary, double _Time_Level, int _GridSize, double _u, double _CFL, int _Left_BoundaryValue,
	int _Right_BoundaryValue) : ImplicitScheme(_Initial_Function, _Analytical_Function, "Implicit Upwind scheme", _LowerBoundary, _UpperBoundary, 
		_Time_Level, _GridSize, _u, _CFL, _Left_BoundaryValue, _Right_BoundaryValue)
{
	Initialise_Matrix();
}


void ImplicitUpwindScheme::Initialise_Matrix() {
	matrix = Matrix(GridSize - 1, GridSize - 1);
	matrix_L = Matrix(GridSize - 1, GridSize - 1);
	matrix_U = Matrix(GridSize - 1, GridSize - 1);
	for (int i = 0; i < GridSize-1; i++) {
		for (int j = 0; j < GridSize-1; j++) {
		if(i==j){
			matrix[i][j] = 1 + CFL;
		}
		else if (i-1 == j) {
			matrix[i][j] = -CFL;
		}
		else {
			matrix[i][j] = 0;
		}
		}
	}
	LU::lu_fact(matrix, matrix_L, matrix_U, GridSize - 1);
}

void ImplicitUpwindScheme::GetImplicitValue() {
	std::vector<double> next_time(GridSize-1);
	std::vector<double> this_time;
	Generate_Vector(this_time);
	LU::lu_solve(matrix_L, matrix_U, this_time, GridSize-1, next_time);
	Next_step.push_back(Left_BoundaryValue);
	for (int i = 0; i < GridSize - 2; i++) {
		Next_step.push_back(next_time[i]);
	}
	Next_step.push_back(Right_BoundaryValue);
	NumericalValues = Next_step;
	This_step = Next_step;
	Next_step.clear();
}


void ImplicitUpwindScheme::Generate_Vector(std::vector<double>& this_time) {
	this_time.push_back(This_step[1]+CFL*Left_BoundaryValue);
	for (int i = 2; i < GridSize; i++) {
		this_time.push_back(This_step[i]);
	}
}

