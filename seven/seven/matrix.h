#ifndef MATRIX_H
#define MATRIX_H
#include<vector>
#include<QByteArray>

class Matrix
{
public:
    Matrix(QByteArray &content);
    Matrix();
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other) {
           if (this != &other) {
               matrix = other.matrix;
           }
           return *this;
       }
    std::vector<std::vector<qint16>> matrix;
};

#endif // MATRIX_H
