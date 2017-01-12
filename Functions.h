#pragma once 
#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H
#include <cmath>

/**
* Namespace for all elements involved in linear advection equation
*/
namespace equation {
		/**
		* Class privides all the necessary functions such as initial functions and functions to get analytical solutions.
		*/
		class Functions {
		private: 
			/**
			* private function used in Signum functions.
			* @param x double - the input value.
			* @return int - If x > 0, then return 1, if x=0, then return 0, if x < 0, then return -1.
			*/
			static int Sign(double x); 
		public:
			/**
			* public function used to get analytical solutions
			* @param x double - the point in space
			* @param t double - the point in time
			* @param u double - the velocity of the wave
			* @return double - the analytical value.
			*/
			static double Signum(double x, double t, double u); 
			/**
			* public function used to get analytical solutions
			* @param x double - the point in space
			* @param t double - the point in time
			* @param u double - the velocity of the wave
			* @return double - the analytical value.
			*/
			static double Exponential(double x, double t, double u);
			/**
			* public function used to calculate initial conditions for Signum function
			* @param x double - the point in space
			* @param u double - the velocity of the wave
			* @return double - the initial condition for space point x.
			*/
			static double Signum_Initial(double x,  double u);
			/**
			* public function used to calculate initial conditions for Exponential function
			* @param x double - the point in space
			* @param u double - the velocity of the wave
			* @return double - the initial condition for space point x.
			*/
			static double Exponential_Initial(double x, double u);
		};
}
#endif 