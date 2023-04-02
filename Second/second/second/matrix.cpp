#include "matrix.h"
#include <vector>

Matrix::Matrix()
{
	size = 2;
	m = new number * [size];
	for (int i = 0; i < size; i++) {
		m[i] = new number[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if ((i + j) % 2 == 0){
				m[i][j] = 1;
			}
			else {
				m[i][j] = 0;
			}
		}
	}
}

Matrix::Matrix(int size)
{	
	this->size = size;
	m = new number * [size];
	for (int i = 0; i < size; i++) {
		m[i] = new number[size];
	}

	cout << "enter a matrix values:" << endl;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			number a;
			cin >> a;
			m[i][j] = a;
		}
	}
}

Matrix::Matrix(const Matrix& m_new)
{
	size = m_new.size;
	m = new number * [size];
	for (int i = 0; i < size; i++) {
		m[i] = new number[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			m[i][j] = m_new.m[i][j];
		}
	}
}


Matrix& Matrix::operator=(const Matrix& m_new)
{
	for (int i = 0; i < size; i++) {
		delete[] m[i];
	}
	delete[] m;
	size = m_new.size;
	m = new number * [size];
	for (int i = 0; i < size; i++) {
		m[i] = new number[size];
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			m[i][j] = m_new.m[i][j];
		}
	}
	return *this;

}

Matrix::~Matrix()
{
	for(int i = 0; i < size; i++) {
		delete[] m[i];
	}
	delete[] m;
}

void Matrix::print()
{
	cout.precision(2);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout.width(8);
			cout << fixed << m[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;
}


void Matrix::transposition()
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			number tmp;
			tmp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = tmp;
		}
	}
}

void Matrix::rank () {
   const double EPS = 1E-9;
   Matrix a = *this;
   const int n = a.size;

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
	cout << "rank: " << rank << endl << endl;
}

void Matrix::determinant() {
	Matrix a = *this;
	int n = a.size;
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

	cout << d;
}

