#pragma once
#include "Matrix.h"

/**
* Namespace for all elements involved in linear advection equation
*/
namespace equation {
	/**
	* Class which provides several static methods for LU decomposition and solving linear equation Ax=b
	*/
	class LU {
	public :
		/**
		* static function to do the LU decomposition.
		* @param a const Matrix& - the matrix A in Ax=b, determined by different implicit scheme.
		* @param l Matrix& - the lower trianglar matrix where Ly=b
		* @param u Matrix& - the upper trianglar matrix where Ux=y
		* @param n int - the size of the matrix A
		*/
		static void lu_fact(const Matrix& a, Matrix& l, Matrix& u, int n);
		/**
		* static function to solve the linear equation Ax=b.
		* @param l Matrix& - the lower trianglar matrix where Ly=b
		* @param u Matrix& - the upper trianglar matrix where Ux=y
		* @param b const std::vector<double>& - the vector of all points in space for this time level 
		* @param n int - the size of the matrix A
		* @param x std::vector<double>& - the vector of all points in space for next time level that we want to calculate.
		*/
		static void lu_solve(const Matrix& l, const Matrix& u, const std::vector<double>& b, int n, std::vector<double>& x);
	};
}