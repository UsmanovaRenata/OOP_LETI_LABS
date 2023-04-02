#include"rational.h"

Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

Rational::Rational(int a, unsigned b)
{
        numerator = a;
        denominator = b;
}

Rational::Rational(int a)
{
    numerator = a;
    denominator = 1;
}


Rational Rational::operator+(Rational const& num)
{
    int numer = numerator;
    unsigned den = denominator;
    if (den != num.denominator) {
        numer = numer * num.denominator + den * num.numerator;
        den *= num.denominator;
    }
    else {
        numer += num.numerator;
    }
    return Rational(numer,den);
}

Rational Rational::operator-(Rational const& num)
{
    int numer = numerator;
    unsigned den = denominator;
    if (den != num.denominator) {
        numer = numer * num.denominator - den * num.numerator;
        den *= num.denominator;
    }
    else {
        numer -= num.numerator;
    }
    return Rational(numer, den);
}

Rational Rational::operator*(Rational const& num)
{
    int numer = numerator;
    unsigned den = denominator;
    numer *= num.numerator;
    den *= num.denominator;
    return Rational(numer,den);
}

Rational Rational::operator/(Rational const& num)
{
    int numer = numerator;
    unsigned den = denominator;
    if (num.numerator != 0) {
        numer *= num.denominator;
        den *= num.numerator;
        return Rational(numer, den);
    }
    else {
        cout << "division by zero\n";
        std::exit(0);
    }
}

Rational& Rational::operator*(int const& num)
{
    if (num == 0) {
        *this = Rational(0);
    }
    numerator *= num;
    return *this;
}

Rational& Rational::operator/(int const& num)
{
    if (num != 0) {
        denominator *= num;
    }
    else {
        cout << "division by zero\n";
    }
    return *this;
}

bool Rational::operator>(int const& num)
{
    if (numerator / denominator - num > 0) {
        return true;
    }
    else {
        return false;
    }
}

Rational& Rational::operator=(Rational const& num)
{
    numerator = num.numerator;
    denominator = num.denominator;
    return *this;

}

Rational& Rational::operator=(int const& num)
{
    *this = Rational(num);
    return *this;
}

Rational Rational::abs(Rational const& num)
{
    numerator = std::abs(num.numerator);
    return Rational(numerator,num.denominator);
}

void Rational::nod()
{
    unsigned n = nod(std::abs(numerator), denominator);
    numerator /= int(n);
    denominator /= n;
}

unsigned Rational::nod(int a, unsigned b)
{
    if (a % b == 0)
        return b;
    if (b % a == 0)
        return a;
    if (a > b)
        return nod(a % b, b);
    return nod(a, b % a);
}

ostream& operator<<(ostream& os, Rational & num)
{
    num.nod();
    os << num.numerator;
    if (num.denominator != 1) {
        os << '/' << num.denominator;
    }
    return os;
}

istream& operator>>(istream& is, Rational& num)
{
    is >> num.numerator >> num.denominator;
    return is;
}
