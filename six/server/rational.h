#ifndef RATIONAL_H
#define RATIONAL_H

#pragma once
#include<iostream>

using namespace std;

class Rational {
public:
    int numerator;
    int denominator;
    Rational();
    Rational(int a, int b);
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

    int nod(int a, int b);
};

#endif // RATIONAL_H
