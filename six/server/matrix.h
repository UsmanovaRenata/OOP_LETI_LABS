#pragma once
#include<iostream>
#include <list>
#include "complex.h"
#include "rational.h"

using namespace std;

template <class number>
class Matrix {
public:
    Matrix();
    Matrix(int rows, int columns);
    Matrix(int rows, int columns, number **);
    Matrix(const Matrix<number>& m_new);
    Matrix& operator=(const Matrix<number>& m_new);
    ~Matrix();
    void print();
    void transposition();
private:
    int rows;
protected:
    int columns;
    number** m;
};

template <class number>
Matrix<number>::Matrix()
{
    rows = 2;
    columns = 2;
    m = new number * [rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new number[rows];
    }
}

template <class number>
Matrix<number>::Matrix(int rows, int columns)
{
    this->rows = rows;
    this->columns = columns;
    m = new number * [rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new number[columns];
    }
}

template <class number>
Matrix<number>::Matrix(int rows, int columns, number **values)
{
    this->rows = rows;
    this->columns = columns;
    m = new number * [rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new number[columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            m[i][j] = values[i][j];
        }
    }
}

template <class number>
Matrix<number>::Matrix(const Matrix<number>& m_new)
{
    rows = m_new.rows;
    columns = m_new.columns;
    m = new number * [rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new number[columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            m[i][j] = m_new.m[i][j];
        }
    }
}

template <class number>
Matrix<number>& Matrix<number>::operator=(const Matrix<number>& m_new)
{
    for (int i = 0; i < rows; i++) {
        delete[] m[i];
    }
    delete[] m;
    rows = m_new.rows;
    columns = m_new.columns;
    m = new number * [rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new number[columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            m[i][j] = m_new.m[i][j];
        }
    }
    return *this;

}

template <class number>
Matrix<number>::~Matrix()
{
    for(int i = 0; i < rows; i++) {
        delete[] m[i];
    }
    delete[] m;
}

template <class number>
void Matrix<number>::print()
{
    cout.precision(2);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout.width(8);
            cout << fixed << m[i][j] << " ";
        }
        cout << "\n";
    }
    cout << endl;
}

template <class number>
void Matrix<number>::transposition()
{
    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < columns; j++) {
            number tmp;
            tmp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = tmp;
        }
    }
}


