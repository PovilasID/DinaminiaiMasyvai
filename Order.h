#pragma once
#include <string>

using namespace std;

class Order{
private:
	string peaceName;
	int peaceUnits;
public:
	Order(string n, int u): peaceName(n), peaceUnits(u){}

	//Set
	void setName	(string a)	{ peaceName = a;	}
	void setUnits	(int a)		{ peaceUnits = a;	}
	//Get
	string	getName	() { return peaceName;	}
	int		getUnits() { return peaceUnits;	}
};

