#include "stdafx.h"
#include "product.h"


product::product(char *name, char *nickname, char *date)
{
	/*Name = *name;
	Nickname = *nickname;*/

	strcpy_s(Name, name);
	strcpy_s(Nickname, nickname);

	int dd, mth, yy;

	sscanf_s(date, "%d-%d-%d",&yy, &mth, &dd);
	Date.tm_year = yy - 1900;
	Date.tm_mon = mth - 1;
	Date.tm_mday = dd;
	Date.tm_hour = 12;
	Date.tm_min = 0;
	Date.tm_sec = 0;
	Date.tm_isdst = -1;
}

product::~product()
{
}

char* product::getName()
{
	return Name;
}

char* product::getNickname()
{
	return Nickname;
}

void product::setNickname(char* a)
{
	//Nickname = a;
	strcpy_s(Nickname, a);
}

tm product::getDate()
{
	return Date;
}

double product::getAge()
{
	time_t now = time(0);
	time_t prodAge = mktime(&Date);
	//int time= difftime(mktime(&Date), now)/ (int)31557600;
	return floor(difftime(now, prodAge) / 31557600);
}

void product::printName()
{
	cout << "Product Name: " << getName() << endl;
}

void product::printAge()
{
	cout << "Product Age: " << getAge() << endl;
}