#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include "matrix.h"
#include<vector>
template <class number>
class SquareMatrix : public Matrix<number>
{
public:
    SquareMatrix(int size, number **values) : Matrix<number>(size, size, values){};
    int rank();
    number determinant();
};

#endif // SQUAREMATRIX_H
template <class number>
int SquareMatrix<number>::rank()
{
    const double EPS = 1E-9;
    SquareMatrix<number> a = *this;
    const int n = a.columns;

     int rank = n;
     vector<char> line_used (n);
     for (int i=0; i<n; ++i) {
         int j;
         for (j=0; j<n; ++j)
             if (!line_used[j] && a.m[j][i] > EPS)
                 break;
         if (j == n)
             --rank;
         else {
             line_used[j] = true;
             for (int p=i+1; p<n; ++p)
                 a.m[j][p] = a.m[j][p] / a.m[j][i];
             for (int k=0; k<n; ++k)
                 if (k != j && a.m[k][i] > EPS)
                     for (int p=i+1; p<n; ++p)
                         a.m[k][p] = a.m[k][p] - a.m[j][p] * a.m[k][i];
         }
     }
     return rank;
}

template <class number>
number SquareMatrix<number>::determinant()
{
    SquareMatrix<number> a = *this;
    int n = a.columns;
    number tmp, d;

    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            tmp = a.m[i][k]*(-1) / a.m[k][k];
            for (int j = 0; j < n; j++) {
                a.m[i][j] = a.m[i][j] + a.m[k][j] * tmp;
            }
        }
    }
    d = 1;
    for (int i = 0; i < n; i++) {
        d = d * a.m[i][i];
    }

    return d;
}

