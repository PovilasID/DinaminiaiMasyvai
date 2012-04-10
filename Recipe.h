#pragma once
#include "Iingredient.h"
#include <string>
#include <vector>

using namespace std;

class Recipe{
	struct Ingredient{
		Iingredient I;
		Ingredient * next;
	};
    string partsName;
	Ingredient *ing;
	Ingredient *temp;
	
public:
	Recipe():ing(NULL), temp(NULL), partsName(""){}
	~Recipe(){ Destroy(); }
	
	void toStart()	{ temp = ing;					}
	void toNext()	{ if(temp) temp = temp->next;	}
	bool notLast()	{ return temp != NULL;			}

	void Destroy(){
		while(ing){
			temp = ing;
			ing = ing->next;
			delete temp;
		}
	}

	void addIng(Iingredient i){
		Ingredient * temp = new Ingredient;
		temp->I = i;
		temp->next = ing;
		ing = temp;
	}


	Iingredient getIng(){ return temp->I; }

	void Sort(){
		Iingredient iTemp;
		for(Ingredient * temp1 = ing; temp1!=NULL; temp1=temp1->next){
			for(Ingredient * temp2 = ing; temp2!=NULL; temp2=temp2->next){
				if(temp2->I < temp1->I){
					iTemp = temp1->I;
					temp1->I = temp2->I;
					temp2->I = iTemp;
					
				}
			}
		}

	}

	void delTo(double a){
		Sort();

		while(ing->I.getAmount() > a){
			if(ing->next != NULL){
				Ingredient *trash = ing;
				ing = ing->next;
				delete trash;
			}else{
				ing = NULL;
				break;
			}
		}
	}

	//void addIng(string name, double amount){
	//	Ingredient *temp = new Ingredient;
	//	temp->iName = name;
	//	temp->iAmount = amount;
	//	temp->next = NULL;
	//	if(ing == NULL){
	//		ing = temp;
	//	}else{
	//		for(Ingredient *temp2= ing; temp2->next; temp2 = temp2->next){
	//			temp2->next = temp;
	//		}
	//	}
	//	delete temp;
	//}
 
	//Get
	string getRName		()	{ return partsName;						}
	vector<Iingredient> getIngs() {
		vector<Iingredient> ret;
		Iingredient tempStruct;
		for (Ingredient *temp = ing; temp != NULL; temp = temp->next) {
			ret.push_back(temp->I);
		}
		return ret;
	}
	//string getIngName	()	{ return ing[ingCurrent].getName();		}
	//double getIngAmount	()	{ return ing[ingCurrent].getAmount();	}}

	//Set
	void setRName	(string a)	{ partsName = a; }


};