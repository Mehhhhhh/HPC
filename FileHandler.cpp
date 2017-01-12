#include "FileHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>


using namespace equation;
using namespace std;

void FileHandler::ReadCVS(string path, double& LowerBoundary, double& UpperBoundary, int& Time_Level, int& GridSize, double& u, double& CFL,
	int& Left_BoundaryValue, int& Right_BoundaryValue, int Nbline)
{	
	string _LowerBoundary, _UpperBoundary, _Time_Level, _GridSize, _u, _CFL, _Left_BoundaryValue, _Right_BoundaryValue;
	ifstream in;
	string line;
	in.open(path,ios::in);
		for (int i = 0; i < Nbline; i++) {
			in.clear();
			line = "";
			getline(in, line);
		}
		stringstream linestream(line);
		getline(linestream, _LowerBoundary, ',');
		getline(linestream, _UpperBoundary, ',');
		getline(linestream, _Time_Level, ',');
		getline(linestream, _GridSize, ',');
		getline(linestream, _u, ',');
		getline(linestream, _CFL, ',');
		getline(linestream, _Left_BoundaryValue, ',');
		getline(linestream, _Right_BoundaryValue, ',');
		LowerBoundary = std::stod(_LowerBoundary);
		UpperBoundary = std::stod(_UpperBoundary);
		u = std::stod(_u);
		CFL = std::stod(_CFL);
		Time_Level = std::stoi(_Time_Level);
		GridSize = std::stoi(_GridSize);
		Left_BoundaryValue = std::stoi(_Left_BoundaryValue);
		Right_BoundaryValue = std::stoi(_Right_BoundaryValue);
		in.close();
}

void FileHandler::WriteResults(std::string path, const vector<double>& Numericalresults, const vector<double>& Analyticalresults,
	const double& Errornorms_1, const double& Errornorms_2, const double& Errornorms_max, double cfl, int gridsize, int time_level ,double lowerboundary,
	double upperboundary, double deltatime)
{
	ofstream out;
	out.open(path,std::ios::out|std::ios::app);

	out << "t=" << time_level << endl;
	out << "x=" << gridsize << endl;
	out << "cfl=" << cfl << endl;
	out << "Numerical solutions" << endl;
	for (int i = 0; i < Numericalresults.size(); i++) {
		if (i != Numericalresults.size() - 1) {
			out << Numericalresults[i] << ",";
		}
		else {
			out << Numericalresults[i];
		}
	}
	out << endl;

	out << "Analytical solutions" << endl;
	for (int i = 0; i < Analyticalresults.size(); i++) {
		if (i != Analyticalresults.size() - 1) {
			out << Analyticalresults[i] << ",";
		}
		else {
			out << Analyticalresults[i];
		}
	}
	out << endl;

	out << "L_1 norms" << endl;
	out << Errornorms_1;
	out << endl;

	out << "L_2 norms" << endl;
	out << Errornorms_2;
	out << endl;

	out << "L_MAX norms" << endl;
	out << Errornorms_max;
	out << endl;

	out << "X" << endl;
	for (int i = 0; i < gridsize; i++) {
		if (i != gridsize - 1) {
			out << (upperboundary - lowerboundary) / (gridsize - 1)*i + lowerboundary << ",";
		}
		else {
			out << (upperboundary - lowerboundary) / (gridsize - 1)*i + lowerboundary;
		}
	}
	out << endl;

	out << "time steps" << endl;
	for (double i = 0; i <= time_level; i+=deltatime) {
		if(i <=time_level-deltatime ){
			out << i << ",";
		}
		else {
			out << i;
		}
	}

	out << endl << endl;
	out.close();
}


/**
* At the end of last line, in.eof() is still true, it will execute one more time,
* so nblines is initialised as -1
*/
int equation::FileHandler::NumberOfLines(std::string path)
{
	ifstream in;
	int nblines = -1;
	string line;
	in.open(path);
	while (!in.eof()) {
		nblines++;
		line = "";
		getline(in, line);
	}
	in.close();
	return nblines;
}
