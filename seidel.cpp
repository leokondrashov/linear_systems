#include "gauss.h"
#include "vector.h"
#include "matrix.h"

#include <fstream>
#include <string>

class seidel_solver {
	matrix A;
	vector f;
	int n;
	std::ofstream log;

	void print_residual(const vector& u_k, int k);

public:
	seidel_solver(matrix A, vector f, const char *residual_log);
	~seidel_solver();

	vector solve();
};

seidel_solver::seidel_solver(matrix A, vector f, const char *residual_log) : 
	A(A), 
	f(f),
	log(residual_log)
{
	n = A.height();
}

seidel_solver::~seidel_solver() {
	
	log.close();
}

vector solve_seidel(matrix A, vector f, const char *log) {
	seidel_solver ss(A, f, log);

	return ss.solve();
}

vector seidel_solver::solve() {
	matrix LD = {n}, U = {n};
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			U[i][j] = A[i][j];

	LD = A - U;
	matrix LD1 = LD.inverse();

	matrix B = -1 * LD1 * U;
	vector F = LD1 * f;

	vector u_k = {n}, u_k_1 = {n};
	double r_k = (A * u_k - f).norm3();
 	double r_k_1 = r_k + 1;
	int k = 0;

	print_residual(u_k, k);
	while (r_k > 1e-5 && r_k < r_k_1) {
		k++;
		u_k_1 = u_k;
		u_k = B * u_k + F;
		r_k_1 = r_k;
		r_k = (A * u_k - f).norm3();
		print_residual(u_k, k);
	}

	return u_k;
}

void seidel_solver::print_residual(const vector& u_k, int k) {
	log << k << "th residual: ";
	vector r = A * u_k - f;
	log << r.norm3() << std::endl;

	log << "u_k = [ ";
	for (int i = 0; i < n; i++)
		log << u_k[i] << " ";
	log << "]" << std::endl;
}
