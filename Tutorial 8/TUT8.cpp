// TUT8.cpp : definisce il punto di ingresso dell'applicazione console.
//

#include "stdafx.h"
#include <string>
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

// Method to clear the console screen
void ClearScreen()
{
	cout << string(100, '\n');
}

// Class Item
class Item
{
public:
	Item() // Empty constructor
	{
		ID = nullptr;
		Name = nullptr;
		sellPrice = NULL;
		costPrice = NULL;
		qty = NULL;
	}
	Item(string id, string name,double sellprice, double costprice, int QTY,int n) // Default constructor
	{
		ID = id;
		Name = name;
		sellPrice = sellprice;
		costPrice = costprice;
		qty = QTY;
		if (n == 1) // option variable to decide if must be added to stock.dat or not
		{
			saveToStock();
		}
		
	}
	Item(const Item& myObject) // Copy constructor
	{
		ID = myObject.ID;
		Name = myObject.Name;
		sellPrice = myObject.sellPrice;
		costPrice = myObject.costPrice;
		qty = myObject.qty;
	}
	~Item() {}

	// List of getter and setter
	void setID(string id) { ID = id; }
	void setName(string name) { Name = name; }
	void setSPrice(double price) { sellPrice = price; }
	void setCPrice(double price) { costPrice = price; }
	void setQty(int QTY) { qty = QTY; }
	string getID() { return ID; }
	string getName() { return Name; }
	double getSPrice() { return sellPrice; }
	double getCPrice() { return costPrice; }
	int getQty() { return qty; }

	// Method to store the item in a .dat file
	void saveToStock() {
		ofstream myfile;
		myfile.open("stock.dat", ios_base::app);
		myfile << ID << "\t" << Name << "\t" << sellPrice << "\t" << costPrice << "\t" << qty << endl;
	}

	// print to console every attribute of the Item
	void print() {
		cout << ID << "\t" << Name << "\t" << sellPrice << "\t" << costPrice << "\t" << qty << endl;
	}

private:
	string ID;
	string Name;
	double sellPrice;
	double costPrice;
	int qty;
};

// Method to load from stock.dat
vector<Item> loadStock() {
	vector<Item> temp;
	string line;
	ifstream in("stock.dat");
	if (!in) // file not found
	{
		cout << "Stock.dat not found!" << endl;
		return temp;
	}
	while (getline(in, line)) //read each line from the stock.dat file
	{
		stringstream linestream(line);
		string id;
		string name;
		double sellprice;
		double costprice;
		int QTY;
		linestream >> id >> name >> sellprice >> costprice >> QTY;
		Item tmpItem(id, name, sellprice, costprice, QTY,0);  // create new item
		temp.push_back(tmpItem); // push to vector
	}
	return temp;
}

//Method to find element by name in a vector
int findItem(vector<Item> items, string name)
{
	string itName = name;
	for (int i = 0; i < items.size(); ++i) // linear search: O(n)
	{
		if (items[i].getName().compare(itName)==0)
		{
			return i; // return index
		}	
	}
	return -1; // fake index "not found"
}

int main()
{	
	// turn on the program
	bool swOn = true;
	// Initialize Item vector
	vector<Item> vecItem;
	// User Interface
	while (swOn != false)
	{
		// Initialize values
		char choice1;
		string id;
		string name;
		double sell;
		double cost;
		double quantity;
		int k; // general index
		ClearScreen();
		cout << "\t*** Welcome in Item Manager***\n" << endl;
		cout << "[1]\tAdd item to item vector and stock.dat\n";
		cout << "[2]\tLoad Item from stock.dat in the item vector\n";
		cout << "[3]\tFind item by name (display information)\n";
		cout << "[4]\tShow all items in the vector\n";
		cout << "[Q]\tExit program :(\n";
		cout << "Enter your choice: ";
		cin >> choice1;
		switch (choice1)
		{
		case '1':
			ClearScreen();
			cout << "Enter the ID: ";
			cin >> id;
			cout << endl<< "Enter the Name: ";
			cin >> name;
			cout << endl << "Enter Sell Price: ";
			cin >> sell;
			cout << endl << "Enter Cost Price: ";
			cin >> cost;
			cout << endl << "Enter Quantity: ";
			cin >> quantity;
			vecItem.push_back(Item(id, name, sell, cost, quantity, 1));
			cout << "Item added!!" << endl;
			system("pause");
			break;
		case'2':
			ClearScreen();
			vecItem.clear(); // empty the vector and rebuild it
			vecItem = loadStock();
			cout << "Loaded!!" << endl;
			system("pause");
			break;
		case '3':
			ClearScreen();
			cout << "Enter the name you want to find: ";
			cin >> name;
			k = findItem(vecItem, name);
			if (k != -1)
			{
				vecItem[k].print();
			}
			else
			{
				cout << endl << "Item not found!!" << endl;
			}
			system("pause");
			break;
		case '4':
			ClearScreen();
			for (int i = 0; i < vecItem.size(); ++i)
			{
				vecItem[i].print();
			}
			system("pause");
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

