#include "matrix.h"
#include <vector>

Matrix::Matrix()
{
    rows = 2;
    columns = 2;
    m = new number * [rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new number[rows];
    }
}

Matrix::Matrix(int rows, int columns)
{
    this->rows = rows;
    this->columns = columns;
    m = new number * [rows];
    for (int i = 0; i < rows; i++) {
        m[i] = new number[columns];
    }
}

Matrix::Matrix(int rows, int columns, number **values)
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

Matrix::Matrix(const Matrix& m_new)
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


Matrix& Matrix::operator=(const Matrix& m_new)
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

Matrix::~Matrix()
{
    for(int i = 0; i < rows; i++) {
        delete[] m[i];
    }
    delete[] m;
}

void Matrix::print()
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


void Matrix::transposition()
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


