#pragma once

#include "Recipe.h"
#include "Order.h"
#include "List.h"
#include "Iingredient.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
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
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
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
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(580, 343);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}




#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 List* L;
				 L = new List;
				 vector<Order> o;
				 vector<Iingredient> c;

				  const char DELIM = '>' ;
				  ifstream fileR("Receptai.txt"); //DO NOT FORGET THIS
				
				  string sTemp; 
				  int i = 0;
				  getline(fileR, sTemp);
				  do {
					if(!sTemp.empty() && sTemp[0]==DELIM){
						L->expandR(i);
						L->setRName(trim(sTemp.substr(1)));
						i++;
					}else{
						do {
							if(!sTemp.empty() && sTemp[0] != DELIM){
								string::const_iterator pos = find(sTemp.begin(), sTemp.end(), '|');
								string name(sTemp.begin(), pos);
								string a_raw(pos + 1, sTemp.end());
								a_raw = trim(a_raw);
								double amount(atof(a_raw.c_str()));
								L->addRIng(trim(name), amount);
							}else{
								break;
							}
						}while(getline(fileR, sTemp));
					}
				  }while(getline(fileR, sTemp));

				  ifstream fileO("Orders.txt"); //DO NOT FORGET THIS
			
				  while(getline(fileO, sTemp)) {
						string::const_iterator pos = find(sTemp.begin(), sTemp.end(), '|');
						string nameO(sTemp.begin(), pos);
						string a_rawO(pos + 1, sTemp.end());
						int units(atoi(trim(a_rawO).c_str()));
						o.push_back(Order(nameO, units));
				  }
					
					int ri=0;
					int j = 0;
					int k = 0;
					int sr = -1;
					int sc = -1;
					double currentAmount;
					L->toFirstR();
					L->toFirstRIng();
					for(int i = 0; i < int(o.size()); i++){ //Sukami visi  uzsakymai
						while(L->notLastR()){ //Surandamas uzsakyma atitinkantis receptas
							if(L->getRName() == o[i].getName()){ sr = i; }
							j++;
							L->toNextR();
						}
						if(sr != -1){
							while(L->notLastRIng()){//Sukamas ciklas per visus rasto recepto ingridientus
								for(int k = 0; k < int(c.size()); k++){
									if(c[k].getIName() == L->getRIngName()){ sc = i; }
								}
								currentAmount = L->getRIngAmount()*o[i].getUnits();
								if(sc == -1){
									c.push_back(Iingredient(L->getRIngName(), currentAmount));
								}else{
									c[sc].setAmount(c[sc].getAmount()+currentAmount);			
								}
								L->toNextRIng();
							}
							L->toFirstRIng();
						}
					}
					L->toFirstR();

				  ofstream fileRez ("Rezults.txt"); //DO NOT FORGET THIS
				  if (fileRez.is_open())  {
					fileRez << Line(50) << endl;
					fileRez << left << "|" <<setw(28)<< "Medziagos pavadinimas" << "|" << setw(19) << "KIEKIS" << "|" << endl;
					fileRez << Line(50) << endl;
					for(int i = 0; i < int(c.size()); i++){
						fileRez << left << "|" <<setw(28)<< c[i].getIName() << "|" << setw(19) << right << c[i].getAmount() << "|" << endl;
					}
					fileRez << Line(50) << endl;
					fileRez.close();
				  }

				  richTextBox1->LoadFile("Rezults.txt", RichTextBoxStreamType::PlainText);

			 }//End of button1_Click
	};
}
