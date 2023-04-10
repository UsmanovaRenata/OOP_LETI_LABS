#pragma once
#include"number.h"
#include<iostream>
#include <list>

using namespace std;

class Matrix {
public:
    Matrix();
    Matrix(int rows, int columns);
    Matrix(int rows, int columns, number **);
    Matrix(const Matrix& m_new);
    Matrix& operator=(const Matrix& m_new);
    ~Matrix();
    void print();
    void transposition();
private:
    int rows;
protected:
    int columns;
    number** m;
};
