#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "matrix.h"
#include<vector>
class SquareMatrix : public Matrix
{
public:
    SquareMatrix(int size, number **values) : Matrix(size, size, values){};
    int rank();
    number determinant();
};

#endif // SQUAREMATRIX_H
