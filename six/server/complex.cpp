#include "complex.h"



ostream& operator<<(std::ostream& os, Tcomplex& num) {
	os << num.real;
	(num.image >= 0) ? cout << " + " : cout << " ";
	os << num.image << "i";
	return os;
}

istream& operator>>(istream& is, Tcomplex& num)
{
	cout << "real part:";
	is >> num.real;
	cout << "imaginary part:";
	is >> num.image;
	return is;
}

Tcomplex::Tcomplex()
{
	real = 0;
	image = 0;
}

Tcomplex::Tcomplex(double r, double i)
{
	real = r;
	image = i;
}

Tcomplex Tcomplex::operator+(Tcomplex const& num)
{
	return Tcomplex(real+num.real, image+num.image);
}

Tcomplex Tcomplex::operator-(Tcomplex const& num)
{
	return Tcomplex(real - num.real, image - num.image);
}

Tcomplex Tcomplex::operator*(Tcomplex const& num)
{
	double r = real * num.real - image * num.image;
	double i = (real * num.image + image * num.real);
	return Tcomplex(r, i);
}

Tcomplex Tcomplex::operator/(Tcomplex const& num)
{
	Tcomplex sprg = Tcomplex(num.real, -num.image);
	Tcomplex numerator = *this * sprg;
	numerator = numerator / pow(abs(sprg),2);
	return numerator;
}

Tcomplex& Tcomplex::operator*(double const& num)
{
	real *= num;
	image *= num;
	return *this;
}

Tcomplex& Tcomplex::operator/(double const& num)
{
	real /= num;
	image /= num;
	return *this;
}

bool Tcomplex::operator>(double const& num)
{
	return (real > num) ?  true :  false;
}

Tcomplex& Tcomplex::operator=(Tcomplex const& num)
{
	image = num.image;
	real = num.real;
	return *this;
}

Tcomplex& Tcomplex::operator=(double const& num)
{
	real = num;
	return *this;
}

double Tcomplex::abs(Tcomplex const& num)
{
	return (sqrt(pow(num.real,2)+pow(num.image,2)));
}
