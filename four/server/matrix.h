#pragma once
#include"number.h"
#include<iostream>
#include <list>

using namespace std;

class Matrix {
public:
    Matrix();
    Matrix(int size);
    Matrix(int size, number **);
    Matrix(const Matrix& m_new);
    Matrix& operator=(const Matrix& m_new);
    ~Matrix();
    void print();
    void transposition();
    int rank();
    number determinant();
private:
    int size;
    number** m;
};
