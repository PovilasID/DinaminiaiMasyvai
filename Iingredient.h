#pragma once
#include <string>

using namespace std;

class Iingredient{
private:
	string materialName;
	double materialAmoutn;
public:
	Iingredient(): materialName(""), materialAmoutn(0){}
	Iingredient(string n, double a): materialName(n), materialAmoutn(a){}

	//Set
	void setName	(string a)				{ materialName = a;		}
	void setAmount	(double a)				{ materialAmoutn = a;	}
	void setIng		(string a, double b)	{ materialName = a;	materialAmoutn = b;	}
	//Get
	string getName()	{ return materialName;		}
	double getAmount()  { return  materialAmoutn;	}
};

