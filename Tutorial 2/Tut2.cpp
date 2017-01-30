// Tut2.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include "complex.h"
#include<iostream>
using namespace std;


int main()
{
	complex z(65, 439);
	complex a(5739, 2);

	complex k;
	k = z + a;
	cout << k.getReal() << endl;
	cout << k.getImg() << endl;

	system("pause");
	return 0;
}

