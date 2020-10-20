#include "gauss.h"
#include "vector.h"
#include "matrix.h"

#include <vector>
#include <cmath>
#include <iostream>

class gaussian_solver {
	std::vector<int> dict;
	matrix A;
	vector f;
	int n;

	void direct();
	vector reverse();

public:
	gaussian_solver(matrix A, vector f);
	~gaussian_solver();

	vector solve();
};

gaussian_solver::gaussian_solver(matrix A, vector f) : A(A), f(f) {
	n = A.height();
	dict.resize(n);
	for (int i = 0; i < n; i++) {
		dict[i] = i;
	}
}

gaussian_solver::~gaussian_solver() {

}

vector solve_gauss(matrix A, vector f) {
	gaussian_solver gs(A, f);
	return gs.solve();
}

vector gaussian_solver::solve() {
	direct();
	return reverse();
}

void gaussian_solver::direct() {
	for (int i = 0; i < n; i++) {
		int row_max = -1, col_max = -1; // find the biggest element
		double abs_max = -1;
		for (int j = i; j < n; j++) {
			for (int k = i; k < n; k++) {
				if (std::abs(A[j][k]) > abs_max) {
					abs_max = std::abs(A[j][k]);
					row_max = j;
					col_max = k;
				}
			}
		}

		A.swap_rows(i, row_max);
		f.swap(i, row_max);

		A.swap_columns(i, col_max);
		std::swap(dict[i], dict[col_max]);

		for (int j = i + 1; j < n; j++) {
			double k_j = - A[j][i] / A[i][i];
			A[j] += A[i] * k_j;
			f[j] += f[i] * k_j;
		}
	}
}

vector gaussian_solver::reverse() {
	vector u(n);

	for (int i = n - 1; i >= 0; i--) {
		u[dict[i]] = f[i] / A[i][i];
		
		for (int j = i - 1; j >= 0; j--) {
			double k_j = - A[j][i] / A[i][i];
			A[j] += A[i] * k_j;
			f[j] += f[i] * k_j;
		}
	}

	return u;
}
