#pragma once
#include "Iingredient.h"
#include <string>
#include <vector>

using namespace std;

class Recipe{

    string partsName;
	int n;
	int ingCurrent;
	Iingredient *ing;
	
public:
	Recipe(): ing(NULL), ingCurrent(0), n(0){}
	~Recipe(){ delete [] ing; }

	//Set possition
	void toFirstIng() {ingCurrent = 0;}
	void toNextIng() {if(ingCurrent < n)ingCurrent++;}
	bool notLastIng() {return ingCurrent < n;}

	//Container management
	void expandIng(int kiek){
	  Iingredient *NIng = new Iingredient[kiek];
	  for (int i = 0; i < n; i++)
			NIng[i] = ing[i];
	    delete [] ing;
		ing = NIng;
		n = kiek;
	}

	void addIng(string name, double amount){
	  expandIng(n+1);
	  ing[n-1].setIng(name, amount);
	  ingCurrent = n;
	}
	void setIng(string name, double amount){
		if(ingCurrent+1<=n){
			ing[ingCurrent].setIng(name, amount);
		}else{
			addIng(name, amount);
		}
	}
 
	//Get
	string getRName		()	{ return partsName;						}
	string getIngName	()	{ return ing[ingCurrent].getName();		}
	double getIngAmount	()	{ return ing[ingCurrent].getAmount();	}
	int getN			()	{ return n;								}

	//Set
	void setRName	(string a)	{ partsName = a; }


};