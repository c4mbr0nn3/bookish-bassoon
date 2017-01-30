// TUT7.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include <string>
using namespace std;

template<class T> T& max( T& a,T& b)
{
	if (a < b)
		return b;
	else
		return a;
}

template<class T> T& min(T& a, T& b)
{
	if (a < b)
		return a;
	else
	{
		return b;
	}
}

template<class T>
class Complex
{
public:
	Complex() 
	{
		culo = NULL;
	}
	~Complex() {}
	Complex(T&  a, T& b)
	{
		culo.push_back(a);
		culo.push_back(b);
	}
	void setA(T& a) {
		T temp = culo.push_back();
		culo.erase(culo.back());
		culo.push_back(a);
		culo.push_back(temp);
	}
	void setB(T& a) {
		culo.erase(culo.back());
		culo.push_back(a);
	}
	T& getA() {
		return culo[0];
	}
	T& getB() {
		return culo[1];
	}
	T& getMax() {
		return max(culo[0], culo[1]);
	}
	T& getMin() {
		return min(culo[0], culo[1]);
	}
private:
	vector<T> culo;
};

int main()
{
	string alb = "Alberto";
	string gian = "Gianfranco";

	Complex<string> nomi(gian,alb);
	cout << nomi.getA() << " " << nomi.getB() << endl;

	cout << "Max: "<< nomi.getMax() << endl;
	cout << "Min: " << nomi.getMin() << endl;

	system("pause");
	return 0;
}

