#include <iostream>

#include "vector.h"
#include "matrix.h"
#include "gauss.h"

int main() {
	matrix A(3, 3);
	A[0][0] = 2;
	A[0][1] = -4;
	A[0][2] = 1;
	A[1][0] = 4;
	A[1][1] = -2;
	A[1][2] = 1;
	A[2][0] = 1;
	A[2][1] = -4;
	A[2][2] = 6;

	vector f(3);
	f[0] = -3;
	f[1] = 3;
	f[2] = 11;

	vector u = solve_gauss(A, f);

//	u.dump();
	
	std::cout << "Solution: \n";
	for (int i = 0; i < 3; i++) {
		std::cout << "u_" << i << " = " << u[i] << std::endl;
	}
}
