#include <iostream>
#include "ExplicitUpwindScheme.h"
#include "ImplicitUpwindScheme.h"
#include "Lax_Wendroff.h"
#include "Richtmyer_MultiStep.h"
#include "Crank_Nicolson.h"
#include "Crank_Nicolson_Thomas.h"
#include "ImplicitUpwind_Thomas.h"
#include "Functions.h"
#include "FileHandler.h"
#include "Norms.h"
#include <vector>
#include <chrono>

using namespace equation;

int main() {/*
	string  pathInput,pathOutput;
	double LowerBoundary, UpperBoundary, u, CFL;
	int Time_Level, GridSize, Left_BoundaryValue, Right_BoundaryValue;
	pathInput = "../Inputs/inputs.csv";
	
	std::vector<scheme::AbstractScheme*> instances;

	for (int i = 1; i <= FileHandler::NumberOfLines(pathInput); i++) {
	
		FileHandler::ReadCVS(pathInput, LowerBoundary, UpperBoundary, Time_Level, GridSize, u, CFL, Left_BoundaryValue, Right_BoundaryValue, i);
		if (Right_BoundaryValue == 1) {
		
		scheme::ExplicitScheme* ExplicitUpwindScheme = new scheme::ExplicitUpwindScheme(Functions::Signum_Initial, Functions::Signum
		, LowerBoundary, UpperBoundary, Time_Level, GridSize, u, CFL, Left_BoundaryValue, Right_BoundaryValue);
		scheme::ExplicitScheme* LaxWendroff = new scheme::Lax_Wendroff(Functions::Signum_Initial, Functions::Signum
		, LowerBoundary, UpperBoundary, Time_Level, GridSize, u, CFL, Left_BoundaryValue, Right_BoundaryValue);
		scheme::ExplicitScheme* RichtmyerMultiStep = new scheme::Richtmyer_MultiStep(Functions::Signum_Initial, Functions::Signum
		, LowerBoundary, UpperBoundary, Time_Level, GridSize, u, CFL, Left_BoundaryValue, Right_BoundaryValue);
		scheme::ImplicitScheme*  ImplicitUpwindScheme = new scheme::ImplicitUpwindScheme(Functions::Signum_Initial, Functions::Signum
		, LowerBoundary, UpperBoundary, Time_Level, GridSize, u, CFL, Left_BoundaryValue, Right_BoundaryValue);

		instances.push_back(ExplicitUpwindScheme);
		instances.push_back(LaxWendroff);
		instances.push_back(RichtmyerMultiStep);
		instances.push_back(ImplicitUpwindScheme);

		for (int counter = 0; counter < instances.size(); counter++)
		{
			instances[counter]->Solve_Scheme();
			pathOutput = "../Results/" + instances[counter]->getName() + "_" + "Signum Function.csv";
			FileHandler::WriteResults(pathOutput, instances[counter]->getNumericalValues(), instances[counter]->getAnalyticalValues(),
			instances[counter]->Calculate_Norms_1(), instances[counter]->Calculate_Norms_2(), instances[counter]->Calculate_Norms_MAX(), CFL, GridSize, Time_Level, LowerBoundary, UpperBoundary,
				instances[counter]->get_DeltaTime());
		}

		instances.clear();
			
			delete ExplicitUpwindScheme;
			delete LaxWendroff;
			delete RichtmyerMultiStep;
			delete ImplicitUpwindScheme;

		}
		if (Right_BoundaryValue == 0) {

				scheme::ExplicitScheme* ExplicitUpwindScheme = new scheme::ExplicitUpwindScheme(Functions::Exponential_Initial, Functions::Exponential
					, LowerBoundary, UpperBoundary, Time_Level, GridSize, u, CFL, Left_BoundaryValue, Right_BoundaryValue);
				scheme::ExplicitScheme* LaxWendroff = new scheme::Lax_Wendroff(Functions::Exponential_Initial, Functions::Exponential
					, LowerBoundary, UpperBoundary, Time_Level, GridSize, u, CFL, Left_BoundaryValue, Right_BoundaryValue);
				scheme::ExplicitScheme* RichtmyerMultiStep = new scheme::Richtmyer_MultiStep(Functions::Exponential_Initial, Functions::Exponential
					, LowerBoundary, UpperBoundary, Time_Level, GridSize, u, CFL, Left_BoundaryValue, Right_BoundaryValue);
				scheme::ImplicitScheme*  ImplicitUpwindScheme = new scheme::ImplicitUpwindScheme(Functions::Exponential_Initial, Functions::Exponential
					, LowerBoundary, UpperBoundary, Time_Level, GridSize, u, CFL, Left_BoundaryValue, Right_BoundaryValue);

				instances.push_back(ExplicitUpwindScheme);
				instances.push_back(LaxWendroff);
				instances.push_back(RichtmyerMultiStep);
				instances.push_back(ImplicitUpwindScheme);

				for (int counter = 0; counter < instances.size(); counter++)
				{
					instances[counter]->Solve_Scheme();
					pathOutput = "../Results/" + instances[counter]->getName() + "_" + "Exponential Function.csv";
					FileHandler::WriteResults(pathOutput, instances[counter]->getNumericalValues(), instances[counter]->getAnalyticalValues(),
						instances[counter]->Calculate_Norms_1(), instances[counter]->Calculate_Norms_2(), instances[counter]->Calculate_Norms_MAX(), CFL, GridSize, Time_Level
						, LowerBoundary, UpperBoundary, instances[counter]->get_DeltaTime());
				}

				instances.clear();

				delete ExplicitUpwindScheme;
				delete LaxWendroff;
				delete RichtmyerMultiStep;
				delete ImplicitUpwindScheme;

		}
	}
	*/
	chrono::high_resolution_clock::time_point t_start = chrono::high_resolution_clock::now();
	string pathOutput = "./Crank_Nicolson_Exponential Function.csv";
	scheme::ImplicitScheme* rich = new scheme::Crank_Nicolson(Functions::Exponential_Initial, Functions::Exponential, -50, 50, 10, 1000, 1.75, 0.1, 0, 0);
	rich->Solve_Scheme();
	chrono::high_resolution_clock::time_point t_end = chrono::high_resolution_clock::now();
	//FileHandler::WriteResults(pathOutput, rich->getNumericalValues(), rich->getAnalyticalValues(),
	//rich->Calculate_Norms_1(), rich->Calculate_Norms_2(), rich->Calculate_Norms_MAX(), 0.99, 1000, 10, -50, 50, rich->get_DeltaTime());
	//rich->show();
	auto duration = chrono::duration_cast<chrono::milliseconds>(t_end - t_start).count();
	std::cout << duration;
	system("pause");
	return 0;
}