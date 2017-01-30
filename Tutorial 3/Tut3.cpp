// Tut3.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include<iostream>
#include<ctime>
#include<fstream>
#include <vector>
#include<string>
#include<sstream>
#include<typeinfo>
#include<algorithm>

using namespace std;
// ritchie kerninghan

void ClearScreen()
{
	cout << string(100, '\n');
}

class Tool
{
protected:
	int id;
	bool available;
	double rentalCost;
	char type[20]="\0";


public:
	Tool(){}
	Tool(const Tool& myObject) {
		id = myObject.id;
		available =myObject.available;
		rentalCost = myObject.rentalCost;
	}
	Tool(bool a, double r, int i) {
		id = i;
		available = a;
		rentalCost = r;
	}
	int getID() {
		return id;
	}
	void setID(int number)
	{
		id=number;
	}
	double getCost() {
		return rentalCost;
	}
	virtual void setCost(double c) {
		rentalCost = c;
	}
	bool getAv() {
		return available;
	}
	void setAv(bool a) {
		available = a;
	}
	void switchAv() {
		if (available==true)
		{
			available = false;
		}
		else {
			available = true;
		}
	}
	char* getType() {
		return type;
	}
	virtual void addTool(char *file) {
		ofstream myfile;
		myfile.open(file, ios_base::app);
		myfile << id << "\t" << rentalCost << "\t" << type << "\t" <<boolalpha<< available << endl;
		myfile.close();
	}
	virtual char* name() { return "0"; }
	void load(){} // non so cosa faccia
};

class Hammer : public Tool
{
private:
	//char type[20];
public:
	Hammer() {}
	Hammer(Hammer& myObject) {
		id = myObject.id;
		rentalCost = myObject.rentalCost;
		strcpy_s(type, myObject.type);
		available = myObject.available;
	}
	Hammer(int i, double p, char* t, bool a) {
		id = i;
		rentalCost = p;
		strcpy_s(type, t);
		available = a;
	}
	Hammer(bool a, double r, int t) {
		if (t == 1) {
			id = 1719110;
			strcpy_s(type, "Normal");
		}
			
		else if (t == 2) {
			id = 1719112;
			strcpy_s(type, "Jack");
		}
		else
		{
			cout << "You must input 1 (Normal) or 2 (Jack) as type of Hammer" << endl;
			return;
		}
		available = a;
		rentalCost = r;
	}
	void setType(char* name) {
		strcpy_s(type, name);
	}
	virtual void addTool(char *file) {
		ofstream myfile;
		myfile.clear();
		myfile.open(file, ios_base::app);
		myfile << "hammer" << "\t" << id << "\t" << rentalCost << "\t" << type << "\t" << boolalpha << available << endl;
		myfile.close();
	}
	virtual char* name() { return"Hammer"; }
};

class Screwdriver : public Tool
{
private:
	//char type[20];
public:
	Screwdriver() {}
	Screwdriver(Screwdriver& myObject) {
		id = myObject.id;
		rentalCost = myObject.rentalCost;
		strcpy_s(type, myObject.type);
		available = myObject.available;
	}
	Screwdriver(int i, double p, char* t, bool a) {
		id = i;
		rentalCost = p;
		strcpy_s(type, t);
		available = a;
	}
	Screwdriver(bool a, double r, int t) {
		if (t == 1) {
			id = 1516180;
			strcpy_s(type, "Manual");
		}

		else if (t == 2) {
			id = 1516182;
			strcpy_s(type, "Electric");
		}
		else
		{
			cout << "You must input 1 (Manual) or 2 (Electric) as type of Screwdriver" << endl;
			return;
		}
		available = a;
		rentalCost = r;
	}
	void setType(char* name) {
		strcpy_s(type, name);
	}
	virtual void addTool(char *file) {
		ofstream myfile;
		myfile.clear();
		myfile.open(file, ios_base::app);
		myfile << "screwD" << "\t" << id << "\t" << rentalCost << "\t" << type << "\t" << boolalpha << available << endl;
		myfile.close();
	}
	virtual char* name() { return"ScrewD"; }
};

class Saw : public Tool
{
private:
	//char type[20];
public:
	Saw() {}
	Saw(Saw& myObject) {
		id = myObject.id;
		rentalCost = myObject.rentalCost;
		strcpy_s(type, myObject.type);
		available = myObject.available;
	}
	Saw(int i, double p, char* t, bool a) {
		id = i;
		rentalCost = p;
		strcpy_s(type, t);
		available = a;
	}
	Saw(bool a, double r, int t) {
		if (t == 1) {
			id = 1780200;
			strcpy_s(type, "Hand");
		}

		else if (t == 2) {
			id = 1780202;
			strcpy_s(type, "Chain");
		}
		else
		{
			cout << "You must input 1 (Hand) or 2 (Chain) as type of Saw" << endl;
			return;
		}
		available = a;
		rentalCost = r;
	}
	void setType(char* name) {
		strcpy_s(type, name);
	}
	virtual void addTool(char *file) {
		ofstream myfile;
		myfile.clear();
		myfile.open(file, ios_base::app);
		myfile << "saw" << "\t" << id << "\t" << rentalCost << "\t" << type << "\t" << boolalpha << available << endl;
		myfile.close();
	}
	virtual char* name() { return"Saw"; }
};

class Trolley : public Tool
{
public:
	using Tool::Tool;
	virtual void addTool(char *file) {
		ofstream myfile;
		myfile.clear();
		myfile.open(file, ios_base::app);
		myfile << "trolley" << "\t" << id << "\t" << rentalCost << "\t" << type << "\t" << boolalpha << available << endl;
		myfile.close();
	}
	virtual char* name() { return"Trolley"; }
}; 

class Ladder : public Tool
{
public:
	using Tool::Tool;
	virtual void addTool(char *file) {
		ofstream myfile;
		myfile.clear();
		myfile.open(file, ios_base::app);
		myfile << "ladder" << "\t" << id << "\t" << rentalCost << "\t" << type << "\t" << boolalpha << available << endl;
		myfile.close();
	}
	virtual char* name() { return"Ladder"; }
}; 

class Secateur : public Tool
{
public:
	using Tool::Tool;
	virtual void addTool(char *file) {
		ofstream myfile;
		myfile.clear();
		myfile.open(file, ios_base::app);
		myfile << "secat" << "\t" << id << "\t" << rentalCost << "\t" << type << "\t" << boolalpha << available << endl;
		myfile.close();
	}
	virtual char* name() { return"Secat"; }
};

class Wheelbarrow : public Tool
{
public:
	using Tool::Tool;
	virtual void addTool(char *file) {
		ofstream myfile;
		myfile.clear();
		myfile.open(file, ios_base::app);
		myfile << "wheelB" << "\t" << id << "\t" << rentalCost << "\t" << type << "\t" << boolalpha << available << endl;
		myfile.close();
	}
	virtual char* name() { return"WheelB"; }
};

class Shovel : public Tool
{
public:
	using Tool::Tool;
	virtual void addTool(char *file) {
		ofstream myfile;
		myfile.clear();
		myfile.open(file, ios_base::app);
		myfile << "shovel" << "\t" << id << "\t" << rentalCost << "\t" << type << "\t" << boolalpha << available << endl;
		myfile.close();
	}
	virtual char* name() { return"Shovel"; }
};

class Rental
{
private:
int id;
Tool *type;
char customer[50];
tm date;
int rentalDays;
double deposit;
double cost;
public:
Rental(){}
Rental(int i, Tool* t, char* c, char* d, int rD, double dep) {
	id = i;
	type = t;
	strcpy_s(customer, c);

	int dd, mth, yy;

	sscanf_s(d, "%d-%d-%d", &yy, &mth, &dd);
	date.tm_year = yy - 1900;
	date.tm_mon = mth - 1;
	date.tm_mday = dd;
	date.tm_hour = 12;
	date.tm_min = 0;
	date.tm_sec = 0;
	date.tm_isdst = -1;

	rentalDays = rD;
	deposit = dep;
	cost = rentalDays*type->getCost();
}
};

struct sortID
{
	bool operator()(Tool* A,Tool* BI)const {
		return A->getID() < BI->getID();
	}
};

class Store
{
private:
	vector<Tool*> list;
	vector<Rental*> rentList;
public: 
	Store() {}
	void loadDB() {
		string line;
		ifstream in("store.txt");
		if (!in) {
			cout << "Store not found!" << endl;
			return;
		}
		while (getline(in, line))
		{
			stringstream linestream(line);
			char cla[50];
			int id;
			double price;
			char type[10];
			bool available;
			linestream >> cla >> id >> price >> type >> available;
			if (strcmp(cla, "hammer")==0)
			{
				Tool *newHammer=new Hammer(id, price, type, available);
				list.push_back(newHammer);
			}
			if (strcmp(cla, "screwD") == 0)
			{
				Tool *newScrew=new Screwdriver(id, price, type, available);
				list.push_back(newScrew);
			}
			if (strcmp(cla, "saw") == 0)
			{
				Tool *newSaw =new Saw(id, price, type, available);
				list.push_back(newSaw);
			}
			if (strcmp(cla, "trolley") == 0)
			{
				Tool *newTrolley = new Trolley(available, price, id);
				list.push_back(newTrolley);
			}
			if (strcmp(cla, "ladder") == 0)
			{
				Tool *newLadder = new Ladder(available, price, id);
				list.push_back(newLadder);
			}
			if (strcmp(cla, "secat") == 0)
			{
				Tool *newSecateur = new Secateur(available, price, id);
				list.push_back(newSecateur);
			}
			if (strcmp(cla, "wheelB") == 0)
			{
				Tool *newWheelbarrow = new Wheelbarrow(available, price, id);
				list.push_back(newWheelbarrow);
			}
			if (strcmp(cla, "shovel") == 0)
			{
				Tool *newShovel = new Shovel(available, price, id);
				list.push_back(newShovel);
			}
		}
	}
	void rebuildDB() {
		ofstream myfile;
		myfile.open("store.txt",ofstream::trunc);
		myfile.close();
		for (unsigned i = 0; i < list.size(); ++i)
		{
			list[i]->addTool("store.txt");
		}	
	}
	void addHammer() {
		char choice;
		double price;
		cout << "Which type of hammer do you want to add?\t[1] Normal\t[2] Jack\n";
		cin >> choice;

		if (choice == '1') {
			cout << endl << "Which price do you want to assign to it?\t";
			cin >> price;
			Tool *newHammer = new Hammer(true, price, 1);
			newHammer->addTool("store.txt");
			list.push_back(newHammer);
		}
		else if (choice == '2')
		{
			cout << endl << "Which price do you want to assign to it?\t";
			cin >> price;
			Tool *newHammer = new Hammer(true, price, 2);
			newHammer->addTool("store.txt");
			list.push_back(newHammer);
		}
		else
		{
			cout << "Wrong choice!! Must type 1 or 2!";
			return;
		}
	}
	void addScrewdriver() {
		char choice;
		double price;
		cout << "Which type of screwdriver do you want to add?\t[1] Manual\t[2] Electric\n";
		cin >> choice;
		cout << endl << "Which price do you want to assign to it?\t";
		cin >> price;

		if (choice == '1') {
			Tool *newScrewdriver=new Screwdriver(true, price, 1);
			newScrewdriver->addTool("store.txt");
			list.push_back(newScrewdriver);
		}
		else if (choice == '2')
		{
			Tool *newScrewdriver=new Screwdriver(true, price, 2);
			newScrewdriver->addTool("store.txt");
			list.push_back(newScrewdriver);
		}
		else
		{
			cout << "Wrong choice!! Must type 1 or 2!";
			return;
		}
	}
	void addSaw() {
		char choice;
		double price;
		cout << "Which type of Saw do you want to add?\t[1] Hand\t[2] Chain\n";
		cin >> choice;
		cout << endl << "Which price do you want to assign to it?\t";
		cin >> price;

		if (choice == '1') {
			Tool *newSaw=new Saw(true, price, 1);
			newSaw->addTool("store.txt");
			list.push_back(newSaw);
		}
		else if (choice == '2')
		{
			Tool *newSaw=new Saw(true, price, 2);
			newSaw->addTool("store.txt");
			list.push_back(newSaw);
		}
		else
		{
			cout << "Wrong choice!! Must type 1 or 2!";
			return;
		}
	}
	void addTrolley() {
		double price;
			cout << endl << "Which price do you want to assign to it?\t";
			cin >> price;
			Tool *newTrolley=new Trolley(true, price, 1718494);
			newTrolley->addTool("store.txt");
			list.push_back(newTrolley);
	}
	void addLadder() {
		double price;
		cout << endl << "Which price do you want to assign to it?\t";
		cin >> price;
		Tool *newLadder=new Ladder(true, price, 1617980);
		cout << newLadder->name();
		newLadder->addTool("store.txt");
		list.push_back(newLadder);
	}
	void addSecateur() {
		double price;
		cout << endl << "Which price do you want to assign to it?\t";
		cin >> price;
		Tool *newSecateur=new Secateur(true, price, 1818922);
		newSecateur->addTool("store.txt");
		list.push_back(newSecateur);
	}
	void addWheelbarrow() {
		double price;
		cout << endl << "Which price do you want to assign to it?\t";
		cin >> price;
		Tool *newWheelbarrow=new Wheelbarrow(true, price, 1763810);
		newWheelbarrow->addTool("store.txt");
		list.push_back(newWheelbarrow);
	}
	void addShovel() {
		double price;
		cout << endl << "Which price do you want to assign to it?\t";
		cin >> price;
		Tool *newShovel=new Shovel(true, price, 1291837);
		newShovel->addTool("store.txt");
		list.push_back(newShovel);
	}
	int storeSize() {
		return list.size();
	}
	void showTools() {
		for (unsigned i = 0; i < list.size(); ++i)
		{
			cout <<"["<< i<<"]" << "\t" << list[i]->name() << "\t" << list[i]->getID() << "\t" << list[i]->getCost() << "\t" << boolalpha << list[i]->getAv()<< "\t"<< list[i]->getType() << endl;
		}
	}
	Tool* search() {} // da fare
	void sortByID() {
		sort(list.begin(), list.end(),sortID());
	}
	void changeAv(int i) {
		list[i]->switchAv();

		string line;
		ifstream myfile;
		myfile.open("store.txt");
		ofstream temp;
		temp.open("temp.txt");
		int count = 0;
		while (getline(myfile, line))
		{
			if (count !=i )
			{
				temp << line << endl;
			}
			++count;
		}
		temp.close();
		myfile.close();
		remove("store.txt");
		rename("temp.txt", "store.txt");
		list[i]->addTool("store.txt");
	}
	void addRent(){}
};

int main()
{
	// turn on the program
	bool swOn = true;
	// initialize store
	Store *OLLO = new Store();
	// load store from db file
	OLLO->loadDB();


	// User Interface
	while (swOn != false)
	{
		char choice1;
		char choice2;
		char choice3;
		ClearScreen();
		cout << "\t*** Welcome in Store Manager***\n" << endl;
		cout << "[1]\tAdd item to your store\n";
		cout << "[2]\tShow all items in you store\n";
		cout << "[3]\tStore function\n";
		cout << "[Q]\tExit program :(\n";
		cout << "Enter your choice: ";
		cin >> choice1;
		switch (choice1)
		{
		case '1':
			ClearScreen();
			cout << "\t*** Welcome in Store Manager***\n" << endl;
			cout << "[1]\tAdd Hammer\n";
			cout << "[2]\tAdd Screwdriver\n";
			cout << "[3]\tAdd Saw\n";
			cout << "[4]\tAdd Trolley\n";
			cout << "[5]\tAdd Ladder\n";
			cout << "[6]\tAdd Secateur\n";
			cout << "[7]\tAdd Wheelbarrow\n";
			cout << "[8]\tAdd Shovel\n";
			cout << "[Q]\tGo Back\n";
			cout << "Enter your choice: ";
			cin >> choice2;
			switch (choice2)
			{
			case '1':
				OLLO->addHammer();
				break;
			case'2':
				OLLO->addScrewdriver();
				break;
			case'3':
				OLLO->addSaw();
				break;
			case '4':
				OLLO->addTrolley();
				break;
			case '5':
				OLLO->addLadder();
				break;
			case'6':
				OLLO->addSecateur();
				break;
			case'7':
				OLLO->addWheelbarrow();
				break;
			case'8':
				OLLO->addShovel();
				break;
			case'Q':
				break;
			}
			break;
		case'2':
			ClearScreen();
			if (OLLO->storeSize() == 0)
				cout << "Your store is empty!" << endl;
			else {
				OLLO->showTools();
				cout << endl;
				cout << "Items in your store: " << OLLO->storeSize() << endl;
			}
			cout << endl;			
			system("pause");
			break;
		case '3':
			ClearScreen();
			cout << "\t*** Welcome in Store Manager***\n" << endl;
			cout << "[1]\tSort your store by ID\n";
			cout << "[2]\tChange availability\n";
			cout << "[Q]\tGo Back\n";
			cout << "Enter your choice: ";
			cin >> choice3;
			switch (choice3)
			{
			case'1':
				OLLO->sortByID();
				OLLO->rebuildDB();
				break;
			case'2':
				cout << "hello world";
				int i;
				cout << "posizione: ";
				cin >> i;
				OLLO->changeAv(i);
				break;
			case'Q':
				break;
			}
			break;

		case'Q':
			swOn = false;
			break;
		}
	}
	cout << endl;
	system("pause");
	return 0;
}