#ifndef _CRANK_NICOLSON_THOMAS_H
#define _CRANK_NICOLSON_THOMAS_H


#include "ImplicitScheme.h"
#include "LU.h"

/**
* Namespace for all elements involved in linear advection equation
*/
namespace equation {
	/**
	* Namespace for all elements related to different schemes
	*/
	namespace scheme {
		/**
		* Class representing implicit upwind schemes.It extends class ImplicitScheme
		* Implementing the virtual functions from class AbstractScheme and class ImplicitScheme
		* to get the numerical values of implicit upwind scheme.
		*/
		class Crank_Nicolson_Thomas : public ImplicitScheme {
		public:
			/**
			* Constructor to create an instance of Implicit Upwind Scheme
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
			Crank_Nicolson_Thomas(double(*Initial_Function)(double x, double u), double(*Analytical_Function)(double x, double t, double u),
				double LowerBoundary, double UpperBoundary, double Time_Level, int GridSize, double u, double CFL, int Left_BoundaryValue,
				int Right_BoundaryValue);
		protected:
			/**
			* Override the pure virtual function, using Thomas algorithm and solve the linear equation Ax=b
			* to obtain the vector of all points in space for next time level based on this time level.
			*/
			void GetImplicitValue() override;
			/**
			* Override the pure virtual function to get the vector b for linear Equation Ax=b
			* @param this_time std::vector<double>& - the reference of the vector b we want to get
			*/
			void Generate_Vector(std::vector<double>& this_time) override;
		private:
			std::vector<double> coefficient_a, coefficient_b, coefficient_c, coefficient_d, coefficient_e;
			double Alpha;
			/**
			* private method to initialise different vectors of coefficients for the Thomas algorithm.
			* Each implicit scheme is related to one particular matrix A
			*/
			void Initialise_Matrix();
		};
	}
}
#endif 
