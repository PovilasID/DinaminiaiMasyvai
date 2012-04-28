#pragma once
#include "Iingredient.h"
#include <string>
#include <vector>

using namespace std;

class Recipe{
	struct Ingredient{
		Iingredient I;
		Ingredient * next;
		Ingredient * back;
	};
    string partsName;
	Ingredient *ing;
	Ingredient *gin;
	Ingredient *temp;
	
public:
	Recipe(){
		ing = new Ingredient; 
		ing->next = NULL;
		ing->back = NULL;
		gin = ing;	
		gin->next = new Ingredient;
		gin->next->back = gin;
		gin = gin->next;
		gin->next = NULL;
		partsName = "";

	}
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
		while(gin){
			temp = gin;
			gin = gin->back;
			delete temp;
		}
	}


	void addIng(Iingredient i){
		Ingredient * temp = new Ingredient;
		temp->I = i;
		Ingredient *pos = new Ingredient;
		pos = gin->back;
		temp->back = pos;
		temp->next = pos->next;
		pos->next = temp;
		temp->next->back = temp;
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

	void del(Ingredient * delet){
		delet->next->back = delet->back;
		delet->back->next = delet->next;
		delete delet;
	}

	//I6rina ingridientus kuriu kiekis yra didesnis nei nurodytas (yra klaidu) 
	void delTo(double a){
		for (Ingredient *temp2 = ing->next; temp2->next != NULL; temp2 = temp2->next) {
			if(temp2->I.getAmount() > a && temp2->I.getAmount() != 0){
				temp2 = temp2->next; 
				del(temp2->back); 
			}
		}
	}


 
	//Get
	string getRName		()	{ return partsName;						}
	vector<Iingredient> getIngs() {
		vector<Iingredient> ret;
		Iingredient tempStruct;
		for (Ingredient *temp = ing->next; temp->next != NULL; temp = temp->next) {
			ret.push_back(temp->I);
		}
		return ret;
	}


	//Set
	void setRName	(string a)	{ partsName = a; }


};