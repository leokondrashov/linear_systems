#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class matrix {
public:
	class matrix_line {
	private:
		int m;
		std::vector<double> data;

	public:
		matrix_line(int m);
		matrix_line(const matrix_line& ml);
		matrix_line(matrix_line&& ml);

		matrix_line& operator=(const matrix_line& ml);
		matrix_line& operator=(matrix_line&& ml);

		~matrix_line();

		double& operator[](int i);

		matrix_line& operator+=(const matrix_line& ml);
		matrix_line& operator*=(double d);

		friend matrix_line& operator+(matrix_line left, const matrix_line& right);
		friend matrix_line& operator*(matrix_line left, double right);
		friend matrix_line& operator*(double left, matrix_line right);

	};

	matrix(int n, int m);
	matrix(const matrix& m);
	matrix(matrix&& m);

	matrix& operator=(const matrix& m);
	matrix& operator=(matrix&& m);

	~matrix();

	matrix_line& operator[](int i);

	void swap_columns(int i, int j);
	void swap_rows(int i, int j);

	void dump();

	int width() { return m; }
	int height() { return n; }

private:
	int n, m;
	std::vector<matrix_line> lines;
};

#endif // MATRIX_H

