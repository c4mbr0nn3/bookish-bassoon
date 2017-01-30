// Tut1_1.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include<iostream>
#include "product.h"

using namespace std;

int main()
{
	int people;
	cin >> people;

	cout << "Hello world to all " << people << " you!" << endl;

	char date[] = "2010-11-27";

	product *product1 = new product("CuloVibrante", "Pinotto", date);

	// double culo = product1->getAge();


	cout << product1->getName() << endl;
	cout << product1->getNickname() << endl;
	cout << product1->getAge() << endl;
	product1->printAge();
	product1->printName();

	system("pause");
	return 0;
}

