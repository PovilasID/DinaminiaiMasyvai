#pragma once

#include "Recipe.h"
#include "Order.h"
#include "List.h"
#include "Iingredient.h"
#include "functions.h"

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
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ComboBox^  comboBox1;
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
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
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
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Lucida Console", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(12, 41);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(556, 290);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(220, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Surikiuoti";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(493, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Uþdaryti";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Pasirinkite tavrka...", L"Didejimo", L"Mazejimo"});
			this->comboBox1->SelectedIndex = 0;
			this->comboBox1->Location = System::Drawing::Point(93, 14);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(580, 343);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);

		}

#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
					vector<Iingredient> c;
					bool dup;
					
					getData(c, dup);
					if(!dup){
						MessageBox::Show("Receptu faile yra receptu su vienodai pavadinimais. \nPrasome ivesti receptus su unikaliais pavadinimais ir pasalinti kopijas",
							"KLAIDA! Apskaiciavimas negalimas",MessageBoxButtons::OK,MessageBoxIcon::Stop);
						Close();					
					}else{
						writeData(c);
						richTextBox1->LoadFile("Rezults.txt", RichTextBoxStreamType::PlainText);
					}

			 }//End of button1_Click
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
					vector<Iingredient> c;
					bool dup;
					
					getData(c, dup);
					if(!dup){
						MessageBox::Show("Recuptu faile yra receptu su vienodai pavadinimais. \nPrasome ivesti receptus su unikaliais pavadinimais ir pasalinti kopijas",
							"KLAIDA! Surykiavimas negalimas",MessageBoxButtons::OK,MessageBoxIcon::Stop);
						Close();					
					}else{
						if(comboBox1->SelectedIndex == 0){
							MessageBox::Show("Prasome pasirinkti rusiavimo metoda",
								"Nepasrinktas rusiavimo metodas",MessageBoxButtons::OK,MessageBoxIcon::Warning);
						}else if(comboBox1->SelectedIndex == 1){
							sortDataAsc(c);
							writeData(c);
							richTextBox1->LoadFile("Rezults.txt", RichTextBoxStreamType::PlainText);
						}else if(comboBox1->SelectedIndex == 2){
							sortDataDesc(c);
							writeData(c);
							richTextBox1->LoadFile("Rezults.txt", RichTextBoxStreamType::PlainText);
						}
					}
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 Close();
		 }
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(comboBox1->SelectedIndex != 0){ button2->Enabled = true;}else{ button2->Enabled = false; }

		 }
};
}
