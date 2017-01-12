#pragma once
#ifndef _IMPLICITSCHEME_H
#define _IMPLICITSCHEME_H

#include "AbstractScheme.h"
#include "Matrix.h"

/**
* Namespace for all elements involved in linear advection equation
*/
namespace equation {
	/**
	* Namespace for all elements related to different schemes
	*/
	namespace scheme {
		/**
		* Class representing all Implicit schemes.It extends class AbstractScheme
		* It provides the interface for all implicit schemes to get the value of
		* next time level in an implicit way(getting several unknown value for next time level based on several known values from this time level)
		*/
		class ImplicitScheme : public AbstractScheme {
		public :
				/**
				* Constructor to generically create an instance of implicit scheme
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
				ImplicitScheme(double(*Initial_Function)(double x, double u), double(*Analytical_Function)(double x, double t, double u),
				std::string name, double LowerBoundary, double UpperBoundary, double Time_Level, int GridSize, double u, double CFL,
				int Left_BoundaryValue, int Right_BoundaryValue);
		protected :
			Matrix matrix, matrix_L, matrix_U;
			/**
			* Virtual void function to calculate one unknown value for next time level based on several known values from this time level.
			* Implemented in exact explicit schemes
			*/
			virtual void GetImplicitValue() = 0;
			/**
			* Virtual double function to get the vector b for linear Equation Ax=b, where x is the vector for next time level
			* and b is the vector for this time level
			* @param this_time std::vector<double>& - the reference of the vector b we want to get
			*/
			virtual void Generate_Vector(std::vector<double>& this_time) = 0;
			/**
			* generic function to calculate the next time step.
			*/
			void GetValues() override;
		};
	}
}
#endif 