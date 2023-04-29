#pragma once
#include<iostream>

using namespace std;

class Tcomplex {
public:
	Tcomplex();
	Tcomplex(double r, double i);
	Tcomplex operator+(Tcomplex const& num);
	Tcomplex operator-(Tcomplex const& num);
	Tcomplex operator*(Tcomplex const& num);
	Tcomplex operator/(Tcomplex const& num);
	Tcomplex& operator*(double const& num);
	Tcomplex& operator/(double const& num);
	bool operator>(double const& num);
	Tcomplex& operator=(Tcomplex const& num);
	Tcomplex& operator=(double const& num);
	double abs(Tcomplex const& num);
	friend ostream& operator<<(ostream& os, Tcomplex& num);
	friend istream& operator>>(istream&, Tcomplex& num);
    double real;
    double image;
};
