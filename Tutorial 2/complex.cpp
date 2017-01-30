#include "stdafx.h"
#include "complex.h"
#include <cmath>
#include <iostream>

using namespace std;


complex::complex()
{
	Re = NULL;
	Im = NULL;
}

complex::complex(double re, double im)
{
	Re = re;
	Im = im;
}

complex::complex(complex& myObject)
{
	Re = myObject.Re;
	Im = myObject.Im;
}

complex::~complex()
{
	cout << "Free memory!" << endl;
}

double complex::getReal()
{
	return Re;
}

double complex::getImg()
{
	return Im;
}

void complex::setReal(double number)
{
	Re = number;
}

void complex::setImg(double number)
{
	Im = number;
}

complex operator+(const complex& A, const complex& B)
{
	complex result;
	result.setReal(A.Re + B.Re);
	result.setImg(A.Im + B.Im);
	return result;
}

complex operator*(const complex& A, const complex& B)
{
	complex result;
	result.setReal(A.Re*B.Re-A.Im*B.Im);
	result.setImg(A.Im*B.Re + A.Re*B.Im);
	return result;
}

complex operator*(const complex& A,const double B)
{
	complex result;
	result.setReal(A.Re*B);
	result.setImg(A.Im*B);
	return result;
}

complex operator*(const double B, const complex& A)
{
	complex result;
	result.setReal(A.Re*B);
	result.setImg(A.Im*B);
	return result;
}

complex operator-(const complex& A, const complex& B)
{
	complex result;
	result.setReal(A.Re - B.Re);
	result.setImg(A.Im - B.Im);
	return result;
}

/*void complex::add(complex *b)
{
	Re = Re + b->getReal();
	Im = Im + b->getImg();
}

void complex::multy(complex *b)
{
	double tempRe = Re*b->getReal() - Im*b->getImg();
	double tempIm = Re*b->getImg() - b->getReal()*Im;

	Re = tempRe;
	Im = tempIm;
}

void complex::conj()
{
	Im = -Im;
}

double complex::modulus()
{
	complex *z = this;
	z->conj();
	return (Re*z->getReal() - Im*z->getImg());
}

double complex::arg()
{
	return cos(Re / modulus());

}*/