#pragma once
#ifndef _FILEHANDLER_H
#define _FILEHANDLER_H

#include <string>
#include <vector>
using namespace std;

/**
* Namespace for all elements involved in linear advection equation
*/
namespace equation {
		/**
		* Class providing static methods to handle files 
		*/
		class FileHandler {
		public:
			/**
			* public static method to read a .CSV file according to the path of the file. Load all the important parametres.
			* Then convert the string type to double or int.
			* In this case, parametres like LowerBoundary, UpperBoundary, valocity of wave are fixed,
			* however, for others situations, they might be setted differently.
			* @param path std::string - The path of the file to read.
			* @param LowerBoundary double - start point of the space grid
			* @param UpperBoundary double - end point of the space grid
			* @param Time_Level int - The time that the approximation should stop.
			* @param GrdiSize int - The number of points in the space dimension
			* @param u double - The velocity of the wave
			* @param CFL double - The CFL number
			* @param Left_BoundaryValue int - The value of the left point(first point) in the space dimension for any time.
			* @param Right_BoundaryValue int - The value of the right point(last point) in the space dimension for any time.
			*/
			static void ReadCVS(string path, double& LowerBoundary, double& UpperBoundary, int& Time_Level, int& GridSize, double& u, double& CFL,
				int& Left_BoundaryValue, int& Right_BoundaryValue, int Nbline);
			/**
			* public static method to write results to a .csv file according to the path of the file.
			* Write numberical, analytical solutions, three different norms and points in space into the file
			* @param path std::string - The path of the file to write.
			* @param Numericalresults const std::vector<double>& - The 2-dimensional vector of numerical solutions
			* @param Analyticalresults const std::vector<double>& - The 2-dimensional vector of analytical solutions
			* @param Errornorms_1 const double& - The 1-dimensional vector of errors' L_1 norms for each time step
			* @param Errornorms_2 const double& - The 1-dimensional vector of errors' L_2 norms for each time step
			* @param Errornorms_max const double& - The 1-dimensional vector of errors' L_MAX norms for each time step
			* @param cfl double - the CFL number
			* @param gridsize int - the number of points in space 
			* @param time_level int - time level that we want to calculate
			* @param lowerboundary double - the left side of space points
			* @param upperboundary double - the right side of space points
			* @param timesize int - the number of points in time.
			*/
			static void WriteResults(std::string path, const vector<double>& Numericalresults, const vector<double>& Analyticalresults, 
				const double& Errornorms_1, const double& Errornorms_2, const double& Errornorms_max, double cfl, int gridsize, int time_level, 
				double lowerboundary, double upperboudary, double deltatime);
			/**
			* public static method to calculate the number of lines of the file.
			* @param path std::string - The path of the file.
			* @return int - Number of lines
			*/
			static int NumberOfLines(std::string path);
		};
}
#endif 