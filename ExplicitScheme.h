#pragma once
#ifndef _EXPLICITSCHEME_H
#define _EXPLICITSCHEME_H
#endif 

#include "AbstractScheme.h"

/**
* Namespace for all elements involved in linear advection equation
*/
namespace equation {
	/**
	* Namespace for all elements related to different schemes
	*/
	namespace scheme {
		/**
		* Class representing all explicit schemes.It extends class AbstractScheme
		* It provides the interface for all explicit schemes to get the value of 
		* next time level in an explicit way(getting one unknown value for next time level based on several known values from this time level)
		*/
		class ExplicitScheme : public AbstractScheme {
		public :
			/**
			* Constructor to generically create an instance of explicit scheme
			* @param *Initial_Function double- The initial condition when t=0
			* @param *Analytical_Function double - The function provided to calculate analytical solutions
			* @param name std::string - The name of the scheme
			* @param LowerBoundary double - start point of the space grid
			* @param UpperBoundary double - end point of the space grid
			* @param Time_Level double - The time that the approximation should stop.
			* @param GrdiSize int - The number of points in the space dimension
			* @param u double - The velocity of the wave
			* @param CFL double - The CFL number
			* @param Left_BoundaryValue int - The value of the left point(first point) in the space dimension for any time.
			* @param Right_BoundaryValue int - The value of the right point(last point) in the space dimension for any time.
			*/
			 ExplicitScheme(double(*Initial_Function)(double x, double u), double(*Analytical_Function)(double x, double t, double u),
				std::string name, double LowerBoundary, double UpperBoundary, double Time_Level, int GridSize, double u, double CFL,
				int Left_BoundaryValue, int Right_BoundaryValue);
		protected :
			/**
			* Virtual double function to calculate one unknown value for next time level based on several known values from this time level.
			* return the numerical value in time step t and space point i
			* @param i int - The number of space point 
			* @param t int - The number of time step 
			* Implemented in exact explicit schemes
			*/
			virtual void GetExplicitValue() = 0;
			/**
			* generic function to calculate the next time step.
			*/
			void GetValues() override;
		};
	}
}