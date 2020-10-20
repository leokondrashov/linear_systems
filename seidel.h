#ifndef SEIDEL_H
#define SEIDEL_H

#include "vector.h"
#include "matrix.h"

vector solve_seidel(matrix A, vector f, const char *log);

#endif // SEIDEL_H
