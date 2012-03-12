#pragma once
#include "Iingredient.h"
#include <string>
#include <vector>

using namespace std;

class Recipe{

    string partsName;
	int n;
	int ingCurrent;
	int nmax;
	Iingredient *ing;
	
public:
	Recipe(): ing(NULL), nmax(0), ingCurrent(0), n(0){}
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
		nmax = kiek;
	}

	void addIng(string name, double amount){
	  if (n >= nmax) expandIng(n+1);
	  ing[n].setIng(name, amount);
	  ingCurrent = n;
	  n++;
	}

	//Get
	string getRName		()	{ return partsName;						}
	string getIngName	()	{ return ing[ingCurrent].getIName();		}
	double getIngAmount	()	{ return ing[ingCurrent].getAmount();	}
	int getN			()	{ return n;								}

	//Set
	void setName	(string a)	{ partsName = a; }


};