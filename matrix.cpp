#include <iostream>
#include <cmath>

#include "matrix.h"

matrix::matrix(int n, int m) : n(n), m(m) {
	lines.resize(n, {m});
}

matrix::matrix(const matrix& oth) {
	n = oth.n;
	m = oth.m;
	lines = oth.lines;
}

matrix::matrix(matrix&& oth) {
	n = oth.n;
	oth.n = 0;
	m = oth.m;
	oth.m = 0;
	lines = std::move(oth.lines);
}

matrix& matrix::operator=(const matrix& oth) {
	n = oth.n;
	m = oth.m;
	lines = oth.lines;

	return *this;
}

matrix& matrix::operator=(matrix&& oth) {
	n = oth.n;
	oth.n = 0;
	m = oth.m;
	oth.m = 0;
	lines = std::move(oth.lines);

	return *this;
}

matrix::~matrix() {
}

matrix::matrix_line::matrix_line(int m) : m(m){
	data.resize(m);
}

matrix::matrix_line::matrix_line(const matrix_line& ml) {
	m = ml.m;
	data = ml.data;
}

matrix::matrix_line::matrix_line(matrix_line&& ml) {
	m = ml.m;
	ml.m = 0;
	data = std::move(ml.data);
}

matrix::matrix_line& matrix::matrix_line::operator=(const matrix_line& ml) {
	m = ml.m;
	data = ml.data;

	return *this;
}

matrix::matrix_line& matrix::matrix_line::operator=(matrix_line&& ml) {
	m = ml.m;
	ml.m = 0;
	data = std::move(ml.data);

	return *this;
}

matrix::matrix_line::~matrix_line() {
}

matrix::matrix_line& matrix::operator[](int i) {
	return lines[i];
}

double& matrix::matrix_line::operator[](int i) {
	return data[i];
}

void matrix::dump() {
	std::cout << "matrix [" << this << "]:" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << "[ ";
		for (int j = 0; j < m; j++) {
			std::cout << (*this)[i][j] << " ";
		}
		std::cout << "]" << std::endl;
	}
}

matrix::matrix_line& matrix::matrix_line::operator+=(const matrix_line& ml) {
	for (int i = 0; i < m; i++) {
		data[i] += ml.data[i];
	}

	return *this;
}

matrix::matrix_line& matrix::matrix_line::operator*=(double d) {
	for (int i = 0; i < m; i++) {
		data[i] *= d;
	}

	return *this;
}

matrix::matrix_line& operator+(matrix::matrix_line left, const matrix::matrix_line& right) {
	return left += right;
}

matrix::matrix_line& operator*(matrix::matrix_line left, double right) {
	return left *= right;
}

matrix::matrix_line& operator*(double left, matrix::matrix_line right) {
	return right *= left;
}

void matrix::swap_columns(int i, int j) {
	for (int k = 0; k < n; k++) {
		std::swap((*this)[k][i], (*this)[k][j]);
	}
}

void matrix::swap_rows(int i, int j) {
	std::swap((*this)[i], (*this)[j]);
}
