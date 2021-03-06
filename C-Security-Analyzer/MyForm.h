#pragma once

namespace CSecurityAnalyzer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 585);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(121, 41);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Run Tests!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(633, 586);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(121, 40);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Close";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(238, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"C Code Security Analyzer";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(139, 585);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(361, 29);
			this->textBox1->TabIndex = 3;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(506, 585);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(121, 40);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Browse...";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(12, 538);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(121, 41);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Reset";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 37);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(742, 495);
			this->richTextBox1->TabIndex = 6;
			this->richTextBox1->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(11, 24);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(766, 638);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"C Code Security Analyzer";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//Button to begin tests on selected C Code
		/*
		Process:
		1. Open file
		2. Take in line
		3. Run line through security tests
		4. Reach End-Of-File
		5. Output Errors, Holes and Warnings to GUI
		*/
	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		//Closing Program Button
		Application::Exit();
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		//Browse for C-file
		/*
		Opens File Dialog
		- Only can select .c files
		- Opens initially in the C: Directory
		- If re-opend, opens in last opened directory
		- Sets path to file in the textbox1
		*/
		openFileDialog1->InitialDirectory = "c:\\";
		openFileDialog1->Filter = "C files (*.c)|*.c";
		openFileDialog1->FilterIndex = 1;
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			textBox1->Text = openFileDialog1->FileName;
		}
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		//Reset Button
		/*
		Reset
		- Sets textbox1(file path) to blank
		*/
		textBox1->Text = "";
	}
};
}
