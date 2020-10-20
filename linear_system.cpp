#include <iostream>

#include "vector.h"
#include "matrix.h"
#include "seidel.h"
#include "gauss.h"

int main() {
	matrix A{100};
	vector f{100};

	for (int i = 0; i < 99; i++) {
		A[i][i] = 10;
		A[i + 1][i] = 1;
		A[i][i + 1] = 1;
	}

	for (int i = 0; i < 100; i++) {
		A[99][i] = 1;
		f[i] = 1;
	}


	vector u = solve_gauss(A, f);
	std::cout << "Solution (Gauss): \n";
	for (int i = 0; i < 101; i++)
		std::cout << "u_" << i << " = " << u[i] << std::endl;
	std::cout << "residual: " << (A * u - f).norm3() << std::endl;

	u = solve_seidel(A, f, "residuals.log");
	std::cout << "Solution (Seidel): \n";
	for (int i = 0; i < 101; i++)
		std::cout << "u_" << i << " = " << u[i] << std::endl;
	std::cout << "residual: " << (A * u - f).norm3() << std::endl;
}
