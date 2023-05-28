#pragma once
#include<iostream>

using namespace std;

class Rational {
public:
	Rational();
	Rational(int a, unsigned b);
	Rational(int a);
	Rational operator+(Rational const& num);
	Rational operator-(Rational const& num);
	Rational operator*(Rational const& num);
	Rational operator/(Rational const& num);
	Rational& operator*(int const& num);
	Rational& operator/(int const& num);
	bool operator>(int const& num);
	Rational& operator=(Rational const& num);
	Rational& operator=(int const& num);
	Rational abs(Rational const& num);
	void nod();
	friend ostream& operator<<(ostream& os, Rational& num);
	friend istream& operator>>(istream& is, Rational& num);
private:
	int numerator;
	unsigned denominator;
	unsigned nod(int a, unsigned b);
};