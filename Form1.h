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
		public: System::String^ getRecipesFile(){ return RecipesFile; }
		public: System::String^ getOrdersFile(){ return OrdersFile; }

		public: void setRecipesFile(System::String^ a){ RecipesFile = a; }
		public: void setOrdersFile(System::String^ a){ OrdersFile = a; }
	private: System::String^ RecipesFile;
	private: System::String^ OrdersFile;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::ComponentModel::IContainer^  components;


	protected: 


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


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
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(174, 12);
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
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(382, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Surikiuoti";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
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
			this->comboBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->comboBox1->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->comboBox1->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
			this->comboBox1->Enabled = false;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Pasirinkite tavrka...", L"Didejimo", L"Mazejimo"});
			this->comboBox1->Location = System::Drawing::Point(255, 14);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 4;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 12);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Receptai...";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(93, 12);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 6;
			this->button5->Text = L"Uþsakymai...";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(580, 343);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Name = L"Form1";
			this->Text = L"Buhalterio padejejas";
			this->ResumeLayout(false);

		}

#pragma endregion
		static String^ resultsSysString = gcnew String(RESULTS);
	private: bool fileCheck(int error){
				 bool write = false;
					switch(error){
						case 0:
							MessageBox::Show("Nepasirinkas receptu failas",
								"Failo klaida",MessageBoxButtons::OK,MessageBoxIcon::Warning);
							break;
						case 1:
							MessageBox::Show("Pasirinktas negalimas receptu failas",
								"Failo klaida",MessageBoxButtons::OK,MessageBoxIcon::Warning);
							break;
						case 2:
							MessageBox::Show("Pasrinkas netinkamai aprasytas receptu failas",
								"Failo klaida",MessageBoxButtons::OK,MessageBoxIcon::Warning);
							break;
						case 3:
							MessageBox::Show("Receptu faile yra receptu su vienodai pavadinimais. \nPrasome ivesti receptus su unikaliais pavadinimais ir pasalinti kopijas",
								"KLAIDA! Apskaiciavimas negalimas",MessageBoxButtons::OK,MessageBoxIcon::Stop);
							Close();
							break;
						case 5:
							MessageBox::Show("Nepasirinkas uzsakymu fails",
								"Failo klaida",MessageBoxButtons::OK,MessageBoxIcon::Warning);
							break;
						case 6:
							MessageBox::Show("Pasirinktas negalimas uzsakymu fails ",
								"Failo klaida",MessageBoxButtons::OK,MessageBoxIcon::Warning);
							break;
						case 7:
							MessageBox::Show("Pasrinkas netinkamas arba netinkamai aprasytas receptu failas",
								"Failo klaida",MessageBoxButtons::OK,MessageBoxIcon::Warning);
							break;
						case 10:
							MessageBox::Show("Nepasirinkas nei receptu, nei uzsakymu failas",
								"Failo klaida",MessageBoxButtons::OK,MessageBoxIcon::Warning);
							break;
						case -1:
							write = true;
					}
					return write;
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
					vector<Iingredient> c;
					int error;
					getData(c, getRecipesFile(), getOrdersFile(), error);
					if(fileCheck(error)){
						writeData(c);
						richTextBox1->LoadFile(resultsSysString, RichTextBoxStreamType::PlainText);
					}

			 }//End of button1_Click
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
					vector<Iingredient> c;
					int error;
					
					getData(c, getRecipesFile(), getOrdersFile(), error);
					if(fileCheck(error)){
							switch(comboBox1->SelectedIndex){
								case 0:
									MessageBox::Show("Prasome pasirinkti rusiavimo metoda",
										"Nepasrinktas rusiavimo metodas",MessageBoxButtons::OK,MessageBoxIcon::Warning);
								case 1:
									sortDataAsc(c);
									writeData(c);
									richTextBox1->LoadFile(resultsSysString, RichTextBoxStreamType::PlainText);
								case 2:
									sortDataDesc(c);
									writeData(c);
									richTextBox1->LoadFile(resultsSysString, RichTextBoxStreamType::PlainText);
							}
					}
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 Close();
		 }
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(comboBox1->SelectedIndex != 0 && getRecipesFile() != nullptr && getOrdersFile() != nullptr){ 
				 button2->Enabled = true;
			 }else{
				 button2->Enabled = false; 
			 }

		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			  IO::Stream^ myStream;
			  OpenFileDialog^ openFileDialogRecipes = gcnew OpenFileDialog;

			  openFileDialogRecipes->InitialDirectory = "c:\\";
			  openFileDialogRecipes->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
			  openFileDialogRecipes->FilterIndex = 2;
			  openFileDialogRecipes->RestoreDirectory = true;

			  if ( openFileDialogRecipes->ShowDialog() == System::Windows::Forms::DialogResult::OK ){
				if ( (myStream = openFileDialogRecipes->OpenFile()) != nullptr ){
					setRecipesFile(openFileDialogRecipes->FileName);
					if(getOrdersFile() != nullptr){
						button1->Enabled = true;
						comboBox1->Enabled =  true;
					}
                  myStream->Close();
				}
			  }
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			  IO::Stream^ myStream;
			  OpenFileDialog^ openFileDialogOrders = gcnew OpenFileDialog;

			  openFileDialogOrders->InitialDirectory = "c:\\";
			  openFileDialogOrders->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
			  openFileDialogOrders->FilterIndex = 2;
			  openFileDialogOrders->RestoreDirectory = true;

			  if ( openFileDialogOrders->ShowDialog() == System::Windows::Forms::DialogResult::OK ){
				if ( (myStream = openFileDialogOrders->OpenFile()) != nullptr ){
					setOrdersFile(openFileDialogOrders->FileName);
					if(getRecipesFile() != nullptr){
						button1->Enabled = true;
						comboBox1->Enabled = true;
					}
                  myStream->Close();
				}
			  }
		 }
};
}
