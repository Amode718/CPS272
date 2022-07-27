#pragma once
#pragma once
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

// Class given to start
class Complex
{
	friend ostream& operator<<(ostream& out, const Complex& rhs);
	friend istream& operator>>(istream& in, Complex& obj);
	friend Complex operator+(const Complex& lhs, const Complex& rhs);
	friend Complex operator-(const Complex& lhs, const Complex& rhs);
	friend Complex operator*(const Complex& lhs, const Complex& rhs);
	friend Complex operator/(const Complex& lhs, const Complex& rhs);
public:
	
	Complex(double r=0.0, double i=0.0);
	void setReal(int r);
	void setImag(int i);
	double getReal()const;
	double getImag()const;
	void convertStringToComplex(const string& complex);

private:
	double real;
	double imag;
};
Complex::Complex(double r, double i) { real = r; imag = i; }
void Complex::setReal(int r) { real = r; }
void Complex::setImag(int i) { imag = i; }
double Complex::getReal()const { return real; }
double Complex::getImag()const { return imag; }

inline void Complex::convertStringToComplex(const string& complex)
{
	string temp = "";
	double a;
	for (int a = 0; a < complex.length(); a++)
	{
		if (isdigit(complex[a])||complex[a]==46)
			temp += complex[a];
		else
		{
			if (complex[a] == 'i')
				imag = stof(temp);
			else
			{
				real = stof(temp);
				temp = "";
			}
		}
	}
	
}


ostream& operator<<(ostream& out, const Complex& rhs)
{
	out << rhs.real << "+" << rhs.imag << "i";
	return out;
}
istream& operator>>(istream& in, Complex& obj)
{
	string temp;
	cout << "enter complex number : ";
	in >> temp;
	obj.convertStringToComplex(temp);
	return in;
}
Complex operator+(const Complex& lhs, const Complex& rhs)
{

	Complex temp;
	temp.real = rhs.real + lhs.real;
	temp.imag = lhs.imag + rhs.imag;
	return temp;
}
Complex operator-(const Complex& lhs, const Complex& rhs)
{

	Complex temp;
	temp.real = rhs.real - lhs.real;
	temp.imag = lhs.imag - rhs.imag;
	return temp;
}

inline Complex operator*(const Complex& lhs, const Complex& rhs)
{
	Complex temp;
	temp.real = lhs.real * rhs.real - lhs.imag * rhs.imag;
	temp.imag = lhs.imag * rhs.real + rhs.imag * lhs.real;
	return temp;
}

inline Complex operator/(const Complex& lhs, const Complex& rhs)
{
	Complex temp;
	double a= rhs.real*rhs.real + rhs.imag*rhs.imag;
	temp.real = (rhs.real * lhs.real + rhs.imag * lhs.imag)/a;
	temp.imag= (lhs.imag * rhs.real - lhs.real * rhs.imag) /a;
	return temp;
}
