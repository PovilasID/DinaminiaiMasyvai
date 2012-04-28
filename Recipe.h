#pragma once
#include "Iingredient.h"
#include <string>
#include <vector>

using namespace std;

class Recipe{
	class Ingredient{
	private:
		Iingredient I;
		Ingredient * next;
		Ingredient * back;
	public:
		Ingredient(Iingredient ii = Iingredient(), Ingredient *n = NULL, Ingredient *b = NULL ): I(ii), next(n), back (b){}
		~Ingredient(){}
		//Set
		void setI	(const Iingredient & a)	{ I = a;	}
		void setNext(Ingredient * a)		{ next = a; }
		void setBack(Ingredient * a)		{ back = a; }
		//Get
		Iingredient getI()		{ return I; }
		Ingredient	*getNext()	{ return next; }
		Ingredient	*getBack()	{ return back; }
	};
    string partsName;
	Ingredient *ing;
	Ingredient *gin;
	Ingredient *temp;
	
public:
	Recipe(){
		ing = new Ingredient; 
		ing->setNext(NULL);
		ing->setBack(NULL);
		gin = ing;	
		gin->setNext(new Ingredient);
		gin->getNext()->setBack(gin);
		gin = gin->getNext();
		gin->setNext(NULL);
		partsName = "";

	}
	~Recipe(){ Destroy(); }
	
	void toStart()	{ temp = ing;						}
	void toNext()	{ if(temp) temp = temp->getNext();	}
	bool notLast()	{ return temp != NULL;				}

	void Destroy(){
		while(ing){
			temp = ing;
			ing = ing->getNext();
			delete temp;
		}
		while(gin){
			temp = gin;
			gin = gin->getBack();
			delete temp;
		}
		ing = gin = NULL;
	}

	void addIng(Iingredient i){
		Ingredient * temp = new Ingredient;
		temp->setI(i);
		Ingredient *pos = new Ingredient;
		pos = gin->getBack();
		temp->setBack(pos);
		temp->setNext(pos->getNext());
		pos->setNext(temp);
		temp->getNext()->setBack(temp);
	}


	Iingredient getIng(){ return temp->getI(); }

	void Sort(){
		Iingredient iTemp;
		for(Ingredient * temp1 = ing; temp1!=NULL; temp1=temp1->getNext()){
			for(Ingredient * temp2 = ing; temp2!=NULL; temp2=temp2->getNext()){
				if(temp2->getI() < temp1->getI()){
					iTemp = temp1->getI();
					temp1->setI(temp2->getI());
					temp2->setI(iTemp);
					
				}
			}
		}

	}

	void del(Ingredient * delet){
		delet->getNext()->setBack(delet->getBack());
		delet->getBack()->setNext(delet->getNext());
		delete delet;
	}

	//I6rina ingridientus kuriu kiekis yra didesnis nei nurodytas (yra klaidu) 
	void delTo(double a){
		for (Ingredient *temp2 = ing->getNext(); temp2->getNext() != NULL; temp2 = temp2->getNext()) {
			if(temp2->getI().getAmount() > a && temp2->getI().getAmount() != 0){
				temp2 = temp2->getNext(); 
				del(temp2->getBack()); 
			}
		}
	}


 
	//Get
	string getRName		()	{ return partsName;						}
	vector<Iingredient> getIngs() {
		vector<Iingredient> ret;
		Iingredient tempStruct;
		for (Ingredient *temp = ing->getNext(); temp->getNext() != NULL; temp = temp->getNext()) {
			ret.push_back(temp->getI());
		}
		return ret;
	}


	//Set
	void setRName	(string a)	{ partsName = a; }


};