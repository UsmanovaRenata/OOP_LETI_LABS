#include "matrix.h"

Matrix::Matrix(QByteArray &content)
{
    matrix.push_back(std::vector<qint16>());

    for(int i=0; i < content.size(); i++){
        if(content[i] == '\n'){
             matrix.push_back(std::vector<qint16>());
        }
        else if(content[i] != ' '){
            matrix.back().push_back(content[i]);
        }
    }
}

Matrix::Matrix(const Matrix &other) {
    matrix.resize(other.matrix.size());
        for (int i = 0; i < other.matrix.size(); ++i) {
            matrix[i].resize(other.matrix[i].size());
            for (int j = 0; j < other.matrix[i].size(); ++j) {
                matrix[i][j] = other.matrix[i][j];
            }
        }
}

Matrix &Matrix::operator=(const Matrix &other) {
    if (this != &other) {
        matrix = other.matrix;
    }
    return *this;
}
