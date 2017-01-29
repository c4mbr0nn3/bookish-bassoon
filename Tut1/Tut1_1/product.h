#pragma once
#include<iostream>
#include<ctime>

using namespace std;


class product
{
private:
	char Name[50];
	char Nickname[50];
	tm Date;
public:
	product(char *name, char *nickname, char *date);
	~product();
	char* getName();
	char* getNickname();
	void setNickname(char *a);
	tm getDate();
	double getAge();
	void printName();
	void printAge();
};

