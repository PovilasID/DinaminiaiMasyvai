#include "Recipe.h"
#include "Order.h"
#include "List.h"
#include "Iingredient.h"
#include "CodeToadTongue.h"
#include "Form1.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <msclr\marshal.h>
#include <fstream>
#include <vector>
#include <algorithm> 
#include <functional> 
#include <locale>
#include <sstream>


using namespace std;
using namespace System;
using namespace System::Runtime::InteropServices;

const char static DELIM = '>' ;
const char*  RECIPES = "Receptai.txt";
const char*  ORDERS = "Orders.txt";
extern const char*  RESULTS = "Rezults.txt";

	//IntPtr strptr = (Marshal::StringToHGlobalAnsi(getOrdersFile()));
	//const char* str = (const char*)strptr.ToPointer();
	//Marshal::FreeHGlobal(strptr);


void readRecipes(Recipe* &R,const char* rFilePath, int n){
  string sTemp; 

  ifstream fileR(rFilePath); //DO NOT FORGET THIS
  int i = 0;
  bool read =  true;
  for(int i = 0; i<n; i++) {
	if(read){getline(fileR, sTemp);}else{ read = true; }
	if(!sTemp.empty() && sTemp[0]==DELIM){
		R[i].setRName(sTemp.substr(1));
		i--;
	}else{
		do {
			if(!sTemp.empty() && sTemp[0] != DELIM){
				string::const_iterator pos = find(sTemp.begin(), sTemp.end(), '|');
				string name(sTemp.begin(), pos);
				string a_raw(pos + 1, sTemp.end());
				a_raw = trim(a_raw);
				double amount(atof(a_raw.c_str()));
				R[i].addIng(Iingredient(trim(name), amount));
			}else{
				read = false;
				break;
			}
		}while(getline(fileR, sTemp));
	}
  }
}

void readOrders(vector<Order> & o, const char* oPath, int & error){
	string sTemp;
  ifstream fileO(oPath); //DO NOT FORGET THIS

  while(getline(fileO, sTemp)) {
		string::const_iterator pos = find(sTemp.begin(), sTemp.end(), '|');
		if(pos._Myptr[0] == '|'){
			string nameO(sTemp.begin(), pos);
			string a_rawO(pos + 1, sTemp.end());
			int units(atoi(trim(a_rawO).c_str()));
			o.push_back(Order(trim(nameO), units));
		}else{
			error = 7;
			break;
		}
  }
}

void calculateResults(Recipe* R, vector<Order> o, vector<Iingredient> & c, int n){
	int ri=0;
	int j = 0;
	int k = 0;
	int l = 0;
	int kk = 0;
	int ll = 0;
	int sr = -1;
	int sc = -1;
	double currentAmount = 0;
	for(int i = 0; i < int(o.size()); i++){ //Sukami visi  uzsakymai
		for(l = ll; l < n; l++){ //Surandamas uzsakyma atitinkantis receptas
			if(R[l].getRName() == o[i].getName()){ sr = l; break; }
		}
		ll = l++;
		if(sr != -1){
			for(int z = 0; z<int(R[sr].getIngs().size()); z++ ){//Sukamas ciklas per visus rasto recepto ingridientus
				for(k = kk; k < int(c.size()); k++){
					if(c[k].getName() == R[sr].getIngs()[z].getName()){ sc = i; break;}
				}
				kk = k++;
				currentAmount = R[sr].getIngs()[z].getAmount()*o[i].getUnits();
				if(sc == -1){
					c.push_back(Iingredient(R[sr].getIngs()[z].getName(), currentAmount));
				}else{
					c[sc].setAmount(c[sc].getAmount()+currentAmount);			
				}
			}
		}
	}
}
void checkAgainstDuplicates(bool & noDuplicates, Recipe* R, int n){
	int d = 0;
	noDuplicates = true;
	for (int i = 0; i < n ; i++){
		d = 0;
		for(int j = 0; j < n ; j++ ){
			if(R[i].getRName() == R[j].getRName() && d>=1){ noDuplicates = false; break; }else if (R[i].getRName() == R[j].getRName()){d++;}
		}
	}
}


void getData(vector<Iingredient> & c, String^ recipesFilePath, String^ orderFilePath, int & error){
 Recipe* R;
 vector<Order> o;
 string sTemp;
 error = -1;
 int n = 0;

 
	if(String::IsNullOrEmpty(recipesFilePath)){ 
		error = 0; 
	}else if(error == -1){
		const char* rFilePath = (const char*)(void*)Marshal::StringToHGlobalAnsi(recipesFilePath);

		ifstream fileN(rFilePath); //DO NOT FORGET THIS
		if(fileN.good()){
		  while(!fileN.eof()){getline(fileN,sTemp); if(sTemp[0] == DELIM)n++;}
		  fileN.close();
		}else{
		  error = 1;
		}

		if(n != 0){
			R = new Recipe[n];
			readRecipes(R, rFilePath, n);
			bool noDuplicates;
			checkAgainstDuplicates(noDuplicates, R, n);
			if(!noDuplicates){
				error = 3;
			}
		}else{
			error = 2;
		}
	}

	if(String::IsNullOrEmpty(orderFilePath) && error == -1){
		error = 5;
	}else if(String::IsNullOrEmpty(orderFilePath) && error == 0){
		error = 10;
	}else if(error == -1){
		const char* oFilePath = (const char*)(void*)Marshal::StringToHGlobalAnsi(orderFilePath);
		readOrders(o, oFilePath, error);
		if(int(o.size()) == 0 || error != -1){
			error = 7;
		}
	}

	if(error == -1){
		calculateResults(R, o, c, n);
	}
	

}

void writeData(vector<Iingredient> c){
  ofstream fileRez (RESULTS); //DO NOT FORGET THIS
  if (fileRez.is_open())  {
	fileRez << Line(53) << endl;
	fileRez << left << "|" <<setw(5) << " " <<setw(25) << "Medziagos pavadinimas" << "|" << setw(7) << " " << setw(13) << "KIEKIS" << "|" << endl;
	fileRez << Line(53) << endl;
	for(int i = 0; i < int(c.size()); i++){
		fileRez << left << "|" <<setw(10)<< " " <<setw(20)<< c[i].getName() << "|"  << right << setw(13) << c[i].getAmount() << " " << setw(7) << "|" << endl;
	}
	fileRez << Line(53) << endl;
	fileRez.close();
  }
}

void sortDataAsc(vector<Iingredient> & c){
	double b;
	string d;
	int max, min, nn;
	int n = int(c.size());

	for (int i = 0; i<(n/2);i++){
		min=i;  max=i; nn=n-i-1;
		for (int j=i+1; j<=nn; j++){
			if (c[j]<c[min]) min=j;
			else if (c[j]>c[max]) max=j;
		}
		d=c[i].getName();c[i].setName(c[min].getName()); c[min].setName(d);
		b=c[i].getAmount();c[i].setAmount(c[min].getAmount()); c[min].setAmount(b);
		if (max != i){
			d=c[nn].getName();c[nn].setName(c[max].getName()); c[max].setName(d);
			b=c[nn].getAmount();c[nn].setAmount(c[max].getAmount()); c[max].setAmount(b);
		}else{
			d=c[nn].getName();c[nn].setName(c[min].getName()); c[min].setName(d);
			b=c[nn].getAmount();c[nn].setAmount(c[min].getAmount()); c[min].setAmount(b);
		}
	}
}

void sortDataDesc(vector<Iingredient> & c){
	double b;
	string d;
	int max, min, nn;
	int n = int(c.size());

	for (int i = 0; i<(n/2);i++){
		min=i;  max=i; nn=n-i-1;
		for (int j=i+1; j<=nn; j++){
			if (c[j]>c[min]) min=j;
			else if (c[j]<c[max]) max=j;
		}
		d=c[i].getName();c[i].setName(c[min].getName()); c[min].setName(d);
		b=c[i].getAmount();c[i].setAmount(c[min].getAmount()); c[min].setAmount(b);
		if (max != i){
			d=c[nn].getName();c[nn].setName(c[max].getName()); c[max].setName(d);
			b=c[nn].getAmount();c[nn].setAmount(c[max].getAmount()); c[max].setAmount(b);
		}else{
			d=c[nn].getName();c[nn].setName(c[min].getName()); c[min].setName(d);
			b=c[nn].getAmount();c[nn].setAmount(c[min].getAmount()); c[min].setAmount(b);
		}
	}
}