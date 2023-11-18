// OOP Assn1
#include<iostream>
using namespace std;

class Complex
{
	double real, imag;
	public:
		Complex();
		friend istream & operator >> (istream &, Complex &);
		friend ostream & operator << (ostream &, const Complex &);
		Complex operator +(Complex);
		Complex operator *(Complex);
};

Complex::Complex()
{
	real = 0;
	imag = 0;
}

istream & operator >> (istream &, Complex & i)
{
	cin >> i.real >> i.imag;
	return cin;
}

ostream & operator << (ostream &, const Complex & d)
{
	cout << d.real << "+" << d.imag << "i" << endl;
	return cout;
}

Complex Complex::operator +(Complex c1)
{
	Complex temp;
	temp.real = real + c1.real;
	temp.imag = imag + c1.imag;
	return temp;
}

Complex Complex::operator *(Complex c2)
{
	Complex temp1;
	temp1.real = real * c2.real - imag * c2.imag;
	temp1.imag = real * c2.imag + imag * c2.real;
	return temp1;
}

int main()
{
	Complex c1, c2, c3, c4;
	int ch;
	cout << "Enter first complex number: ";
	cin >> c1;
	cout << "Enter second complex number: ";
	cin >> c2;
	cout << c1;
	cout << c2;
	c3 = c1 + c2;
	cout << "Addition = " << c3;		
	c4 = c1 * c2;
	cout << "Multiplication = " << c4;
	return 0;
		
	
}