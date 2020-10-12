#ifndef VECTOR_H
#define VECTOR_H

#include <vector>

class vector {
private:
	int n;
	std::vector<double> data;
	
public:
	void dump();

	vector(int n);
	vector(const vector& v);
	vector(vector&& v);

	vector& operator=(const vector& v);
	vector& operator=(vector&& v);

	~vector();

	double& operator[](int i);

	double norm1();
	double norm2();
	double norm3();

	void swap(int i, int j);
};

#endif // VECTOR_H
