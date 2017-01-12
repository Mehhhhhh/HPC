#pragma once
#ifndef _RICHTMYER_MULTISTEP_H
#define _RICHTMYER_MULTISTEP_H
#endif 

#include "ExplicitScheme.h"

/**
* Namespace for all elements involved in linear advection equation
*/
namespace equation {
	/**
	* Namespace for all elements related to different schemes
	*/
	namespace scheme {
		/**
		* Class representing Richtmyer MultiStep schemes.It extends class ExplicitScheme
		* Implementing the virtual functions from class AbstractScheme and class ExplicitScheme
		* to get the numerical values with the particular expression of Richtmyer MultiStep scheme.
		*/
		class Richtmyer_MultiStep : public ExplicitScheme {
		public:
			/**
			* Constructor to create an instance of Richtmyer MultiStep Scheme
			* @param *Initial_Function double - The initial condition when t=0
			* @param *Analytical_Function double - The function provided to calculate analytical solutions
			* @param LowerBoundary double - start point of the space grid
			* @param UpperBoundary double - end point of the space grid
			* @param Time_Level double - The time that the approximation should stop.
			* @param GrdiSize int - The number of points in the space dimension
			* @param u double - The velocity of the wave
			* @param CFL double - The CFL number
			* @param Left_BoundaryValue int - The value of the left point(first point) in the space dimension for any time.
			* @param Right_BoundaryValue int - The value of the right point(last point) in the space dimension for any time.
			*/
			explicit Richtmyer_MultiStep(double(*Initial_Function)(double x, double u), double(*Analytical_Function)(double x, double t, double u),
				double LowerBoundary, double UpperBoundary, double Time_Level, int GridSize, double u, double CFL, int Left_BoundaryValue,
				int Right_BoundaryValue);
		private:
			/**
			* Override the pure virtual function, using the particular expression of Richtmyer MultiStep scheme to get all points  
			* for next time level based on known values from this time level.
			*/
			void GetExplicitValue() override;
		};
	}
}
