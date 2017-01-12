#pragma once
#ifndef _NORMS_H
#define _NORMS_H

#include <cmath>
#include <vector>

/**
* Namespace for all elements involved in linear advection equation
*/
namespace equation {
	/**
	* Class privides static functions to calculate different norms of a vector
	*/
	class Norms {
	public :
		/**
		* public static method calculate the L_1 norm of a vector
		* @param vec const std::vector<double>& - the vector of which we want to calculate the L_1 norm.
		*/
		static double Norms_1(const std::vector<double>& vec);
		/**
		* public static method calculate the L_2 norm of a vector
		* @param vec const std::vector<double>& - the vector of which we want to calculate the L_2 norm.
		*/
		static double Norms_2(const std::vector<double>& vec);
		/**
		* public static method calculate the L_MAX norm of a vector
		* @param vec const std::vector<double>& - the vector of which we want to calculate the L_MAX norm.
		*/
		static double Norms_Max(const std::vector<double>& vec);
	};
}
#endif