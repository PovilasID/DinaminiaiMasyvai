#pragma once

#include "Recipe.h"
#include "Order.h"
#include "List.h"
#include "Iingredient.h"

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


namespace DinaminaiMasyvai {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	//* STRIGN MANIPULATION */
	//TRIMMING
	// trim from end
	static inline string &rtrim(string &s) {
			s.erase(find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(), s.end());
			return s;
	}
	//// trim from start
	static inline string &ltrim(string &s) {
			s.erase(s.begin(), find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));
			return s;
	}
	//// trim from both ends
	static inline std::string &trim(std::string &s) {
			return ltrim(rtrim(s));
	}

	double string_to_double( const std::string& s ) {
	   std::istringstream i(s);
	   double x;
	   if (!(i >> x))
		 return 0;
	   return x;
	 }
	string Line(int a){
		string l = "*";
		for(int i = 0; i < a-2; i++) l+="-";
		return l+"*";
	}

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  button2;
	protected: 


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Surasti";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 41);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(556, 290);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(93, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Surikiuoti";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(580, 343);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}

	private: void getData(vector<Iingredient> & c){
			 	 Recipe* R;
				 vector<Order> o;
				 //vector<Iingredient> c;
				 const char DELIM = '>' ;


				  ifstream fileN("Receptai.txt"); //DO NOT FORGET THIS
				  string sTemp; 
				  int n = 0;
				  while(!fileN.eof()){getline(fileN,sTemp); if(sTemp[0] == DELIM)n++;}
				  fileN.close();
				
				  R = new Recipe[n];
				  for(int i = 0; i<n; i++) R[i].expandIng(0);

				  ifstream fileR("Receptai.txt"); //DO NOT FORGET THIS
				
				  int i = 0;
				  bool read =  true;
				  for(int i = 0; i<n; i++) {
					if(!sTemp.empty() && sTemp[0]==DELIM){
						if(read){getline(fileR, sTemp);}
						R[i].setRName(sTemp.substr(1));
					}else{
						R[i].toFirstIng();
						do {
							if(!sTemp.empty() && sTemp[0] != DELIM){
								string::const_iterator pos = find(sTemp.begin(), sTemp.end(), '|');
								string name(sTemp.begin(), pos);
								string a_raw(pos + 1, sTemp.end());
								a_raw = trim(a_raw);
								double amount(atof(a_raw.c_str()));
								R[i].setIng(trim(name), amount);
								R[i].toNextIng();
							}else{
								bool read = false;
								break;
							}
						}while(getline(fileR, sTemp));
					}
				  }
				  //for(int i = 0; i< 2; i++){
					 // R[i].setRName("Velenas");
					 // for(int j = 0; j<2; j++){
						//  R[i].setIng("ingrediento vardas", 15.5);
						//  R[i].toNextIng();
					 // }
				  //}

				  ifstream fileO("Orders.txt"); //DO NOT FORGET THIS
			
				  while(getline(fileO, sTemp)) {
						string::const_iterator pos = find(sTemp.begin(), sTemp.end(), '|');
						string nameO(sTemp.begin(), pos);
						string a_rawO(pos + 1, sTemp.end());
						int units(atoi(trim(a_rawO).c_str()));
						o.push_back(Order(trim(nameO), units));
				  }
					
					int ri=0;
					int j = 0;
					int k = 0;
					int sr = -1;
					int sc = -1;
					double currentAmount;
					for(int i = 0; i < int(o.size()); i++){ //Sukami visi  uzsakymai
						for(int l = 0; l < n; l++){ //Surandamas uzsakyma atitinkantis receptas
							if(R[l].getRName() == o[i].getName()){ sr = l; break; }
						}
						if(sr != -1){
							R[sr].toFirstIng();
							while(R[sr].notLastIng()){//Sukamas ciklas per visus rasto recepto ingridientus
								for(int k = 0; k < int(c.size()); k++){
									if(c[k].getName() == R[sr].getIngName()){ sc = i; break;}
								}
								currentAmount = R[sr].getIngAmount()*o[i].getUnits();
								if(sc == -1){
									c.push_back(Iingredient(R[sr].getIngName(), currentAmount));
								}else{
									c[sc].setAmount(c[sc].getAmount()+currentAmount);			
								}
								R[sr].toNextIng();
							}
						}
					}
				
			 }
			 private: void writeData(vector<Iingredient> c){
				  ofstream fileRez ("Rezults.txt"); //DO NOT FORGET THIS
				  if (fileRez.is_open())  {
					fileRez << Line(150) << endl;
					fileRez << left << "|" <<setw(28)<< "Medziagos pavadinimas" << "|" << setw(19) << "KIEKIS" << "|" << endl;
					fileRez << Line(150) << endl;
					for(int i = 0; i < int(c.size()); i++){
						fileRez << left << "|" <<setw(28)<< c[i].getName() << "|" << setw(19) << right << c[i].getAmount() << "|" << endl;
					}
					fileRez << Line(50) << endl;
					fileRez.close();
				  }
			 }
			 //private: void sortData(vector<Iingredient> & c){
			 //   double b;
				//string d;
				//int max;
				//for (i=0; i<(n/2);i++){
				//min=i; max=i; nn=n-i-1;
				//for (j=i+1; j<=nn; j++){
				//	if (c[j].getAmount()<c[min].getAmount()) min=j;
				//	else if (c[j].getAmount()>c[max].getAmount()) max=j;
				//}
				//d=c[i].getName();c[i].setName(c[min].getName()); c[min].setName(b);
				//b=c[i].getAmount();c[i].setAmount(c[min].getAmount()); c[min].setAmount(b);
				//if (max != i){
				//d=c[nn].getName();c[nn].setName(c[max].getName()); c[max].setName(b);
				//b=c[nn].getAmount();c[nn].setAmount(c[max].getAmount()); c[max].setAmount(b);
				//}else{
				//d=c[nn].getName();c[nn].setName(c[min].getName()); c[min].setName(b);
				//b=c[nn].getAmount();c[nn].setAmount(c[min].getAmount()); c[min].setAmount(b);
				//
			 //}


#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
					vector<Iingredient> c;
					getData(c);
					writeData(c);

				  richTextBox1->LoadFile("Rezults.txt", RichTextBoxStreamType::PlainText);

			 }//End of button1_Click
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
					vector<Iingredient> c;
					getData(c);
					//sortData(c);
					writeData(c);

				  richTextBox1->LoadFile("Rezults.txt", RichTextBoxStreamType::PlainText);
			 }
};
}
