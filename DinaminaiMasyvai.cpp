// DinaminaiMasyvai.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"
//#include "Recipe.h"
//#include "Order.h"
//#include "List.h"
//#include "Iingredient.h"
//
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <iomanip>
//#include <msclr\marshal.h>
//#include <fstream>
//#include <vector>
//#include <algorithm> 
//#include <functional> 
//#include <locale>
//#include <sstream>
//
//using namespace std;
//using namespace System::Runtime::InteropServices;
using namespace DinaminaiMasyvai;

////* STRIGN MANIPULATION */
////TRIMMING
//// trim from end
//static inline string &rtrim(string &s) {
//        s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
//        return s;
//}
////// trim from start
//static inline string &ltrim(string &s) {
//        s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
//        return s;
//}
////// trim from both ends
//static inline std::string &trim(std::string &s) {
//        return ltrim(rtrim(s));
//}
//
//double string_to_double( const std::string& s ) {
//   std::istringstream i(s);
//   double x;
//   if (!(i >> x))
//     return 0;
//   return x;
// }

//string Line(int a){
//	string l = "*";
//	for(int i = 0; i < a-2; i++) l+="-";
//	return l+"*";
//}
//
//
//void MarshalString(String^ s, std::string& outs){
//	char *cs = (char*)Marshal::StringToHGlobalAnsi(s).ToPointer();
//	outs = cs;
//	Marshal::FreeHGlobal((IntPtr)cs);
//}

//void InputR(vector<Recipe> &r, string FILE);
//void InputO(vector<Order> & o, string FILE);
//void Calc(vector<Recipe> r, vector<Order> o, vector<Iingredient> & c);
//void Output(vector<Iingredient> c);

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());

	//vector<Recipe> r;
	//vector<Order> o;
	//vector<Iingredient> c;

	// InputR(r, "dfgdfg");
	// InputO(o, "hkhkhk");
	// Calc(r, o, c);
	//Output(c);
	return 0;
}

//void InputR(vector<Recipe> &r, string FILE){
//  const char DELIM = '>' ;
//  ifstream file("Receptai.txt"); //DO NOT FORGET THIS
//  vector<Iingredient> ing;
//
//  string sTemp; 
//  int i = 0;
//
//  while(getline(file, sTemp)) {
//	if(!sTemp.empty() && sTemp[0]==DELIM){
//		r.resize(r.size()+1);
//		r[i].setName(sTemp.substr(1)); 
//		i++;
//	}else{
//		while(getline(file, sTemp)){
//			if(!sTemp.empty() && sTemp[0] != DELIM){
//				string::const_iterator pos = find(sTemp.begin(), sTemp.end(), '|');
//				string name(sTemp.begin(), pos);
//				string a_raw(pos + 1, sTemp.end());
//				double amount(string_to_double(trim(a_raw)));
//				r[i].addIng(trim(name), amount);
//			}
//		}
//	}
//  }
//}
//
//void InputO(vector<Order> & o, string FILE){
//	  ifstream file("Orders.txt"); //DO NOT FORGET THIS
//	  string sTemp; 
//
//	  while(getline(file, sTemp)) {
//			string::const_iterator pos = find(sTemp.begin(), sTemp.end(), '|');
//			string name(sTemp.begin(), pos);
//			string a_raw(pos + 1, sTemp.end());
//			int units(atoi(trim(a_raw).c_str()));
//			o.push_back(Order(name, units));
//	  }
//}
//
//int SearchC(vector<Iingredient> c, string a){
//	for(int i = 0; i < int(c.size()); i++){
//		if(c[i].getName() == a) return i;
//	}
//	return -1;
//}
//int SearchR(vector<Recipe> r, string a){
//
//	for(int i = 0; i < int(r.size()); i++){
//		if(r[i].getName() == a) return i;
//	}
//	return -1;
//}
//
//void Calc(vector<Recipe> r, vector<Order> o, vector<Iingredient> & c){
//	int ri=0;
//	double currentAmount;
//	for(int i = 0; i < int(o.size()); i++){
//		int sr  = SearchR(r, o[i].getName());
//		if(sr != -1){
//			while(r[sr].notLastIng()){
//				int sc = SearchC(c, r[sr].getIngName());
//				currentAmount = r[sr].getIngAmount()*o[i].getUnits();
//				if(sc == -1){
//					c.push_back(Iingredient(r[sr].getIngName(), currentAmount));
//				}else{
//					c[sc].setAmount(c[sc].getAmount()+currentAmount);			
//				}
//				r[sr].toNext();
//			}
//			r[sr].toFirst();
//		}
//	}
//}
//
//void Output(vector<Iingredient> c){
//  ofstream file ("Rezults.txt"); //DO NOT FORGET THIS
//  if (file.is_open())  {
//	file << Line(50) << endl;
//	file << left << "|" <<setw(28)<< "Medziagos pavadinimas" << "|" << setw(19) << "KIEKIS" << "|" << endl;
//	file << Line(50) << endl;
//	for(int i = 0; i < int(c.size()); i++){
//		file << left << "|" <<setw(28)<< c[i].getName() << "|" << setw(19) << right << c[i].getAmount() << "|" << endl;
//	}
//	file << Line(50) << endl;
//    file.close();
//  }
//}