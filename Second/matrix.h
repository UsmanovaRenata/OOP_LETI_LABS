#include"number.h"
#include<iostream>

using namespace std;

class Matrix {
public:
	Matrix();
	Matrix(int size);
	Matrix(const Matrix& m_new);
	Matrix& operator=(const Matrix& m_new);
	~Matrix();
	void print();
	void transposition();
	void rank();
	number determinant();
private:
	int size;
	number** m;
};
