//#pragma once
//#include "Iingredient.h"
//#include "Recipe.h"
//#include <string>
//#include <vector>
//
//using namespace std;
//
//class List{
//
//	int n;
//	int rCurrent;
//	int nmax;
//	Recipe *r;
//	
//public:
//	List(): r(NULL), nmax(0), rCurrent(0), n(0){}
//	~List(){ delete [] r; }
//
//	//Set possition
//	void toFirstR() {rCurrent = 0;}
//	void toNextR() {if(rCurrent < n)rCurrent++;}
//	bool notLastR() {return rCurrent < n;}
//
//	//Container management
//	void expandR(int kiek){
//	  Recipe *NR = new Recipe[kiek];
//	  for (int i = 0; i < n; i++)
//			NR[i] = r[i];
//	    delete [] r;
//		r = NR;
//		nmax = kiek;
//	}
//
//	//void addRecipe(string name, vector<string> ingNames, vector<double> ingAmounts){
//	//	if(n >= nmax){
//	//		expandR(n+1);
//	//		r[n].setReName(name);
//	//		r[n].toFirstIng();
//	//		for(int i = 0; i < int(ingNames.size()); i++){
//	//			r[n].addIng(ingNames[i], ingAmounts[i]);
//	//		}
//	//	}
//	//  rCurrent = n;
//	//  n++;
//	//}
//
//	//Get	
//	string	getRName		()	{ return r->getRName();		}
//	string	getRIngName		()	{ return r->getIngName();		}
//	double	getRIngAmount	()	{ return r->getIngAmount();	}
//
//	//Set	
//	void	setRName	(string a)				{ r->setReName(a);		}
//	void	addRIng		(string a, double b)	{ r->addIng(a,b);		}
//
//	//First container class possition manipulation
//	void toFirstRIng	()	{ r->toFirstIng();			}
//	void toNextRIng		()	{ r->toNextIng();			}
//	bool notLastRIng	()	{ return r->notLastIng();	}
//
//
//};