﻿#include <cmath>
#include <iostream>
using namespace std;

struct Complex {
	double Re; //phần thực - real
	double Im; //phần ảo - imaginary
};

// Lấy liên hợp
Complex Conjg(Complex a)
{
	a.Im = -a.Im;
	return a;
}

// Lấy đối
Complex Neg(Complex a)
{
	a.Re = -a.Re;
	a.Im = -a.Im;
	return a;
}

Complex Add(Complex a, Complex b)
{
	Complex c;
	c.Re = a.Re + b.Re;
	c.Im = a.Im + b.Im;
	return c;
}

Complex Sub(Complex a, Complex b)
{
	return Add(a, Neg(b)); // a - b = a + (-b)
}

Complex Mul(Complex a, Complex b)
{
	Complex c;
	c.Re = a.Re * b.Re - a.Im * b.Im;
	c.Im = a.Re * b.Im + a.Im * b.Re;
	return c;
}

Complex Div(Complex a, Complex b)
{
	Complex c = Mul(a, Conjg(b));
	double d = b.Re * b.Re + b.Im * b.Im;
	c.Re /= d;
	c.Im /= d;
	return c;
}

double Modulus(Complex a)
{
	return sqrt(a.Re * a.Re + a.Im * a.Im);
}

double Argument(Complex a)
{
	return atan(a.Im / a.Re);
}

Complex SquareRoot(Complex a)
{
	Complex c;
	double delta = Modulus(a);
	if ((a.Re + delta) / 2 >= 0)
		c.Re = sqrt((a.Re + delta) / 2);
	else
		c.Re = sqrt((a.Re - delta) / 2);
	c.Im = a.Im / c.Re / 2;
	return c;
}

Complex InputComplex() {
	Complex r;
	cout << "Enter real value : ";
	cin >> r.Re;

	cout << "Enter imaginary value : ";
	cin >> r.Im;
	return r;
}

void PrintComplex(Complex a)
{
	if (a.Re != 0) cout << a.Re;
	if (a.Im != 0)
	{
		if (a.Im == -1) cout << "-i";
		else if (a.Im == 1)
		{
			if (a.Re == 0) cout << "i";
			else cout << "+i";
		}
		else
		{
			if (a.Re != 0 && a.Im > 0)
				cout << "+" << a.Im << "i" << endl;
			else
				cout << a.Im << "i" << endl;
		}
	}

	if (a.Re == 0 && a.Im == 0)
		cout << "0" << endl;
}