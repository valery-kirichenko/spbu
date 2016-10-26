#pragma once

namespace Calc {

	int oper_type;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  num7;
	private: System::Windows::Forms::Button^  num8;
	private: System::Windows::Forms::Button^  num9;
	private: System::Windows::Forms::Button^  num4;
	private: System::Windows::Forms::Button^  num5;
	private: System::Windows::Forms::Button^  num6;
	private: System::Windows::Forms::Button^  num1;
	private: System::Windows::Forms::Button^  num2;
	private: System::Windows::Forms::Button^  num3;
	private: System::Windows::Forms::Button^  btn_ravno;
	private: System::Windows::Forms::TextBox^  inp_main;

	private: System::Windows::Forms::TextBox^  inp_buf;
	private: System::Windows::Forms::Button^  oper_multi;
	private: System::Windows::Forms::Button^  oper_plus;
	private: System::Windows::Forms::Button^  oper_minus;
	private: System::Windows::Forms::Button^  oper_dev;
	protected: 










	protected: 

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->num7 = (gcnew System::Windows::Forms::Button());
			this->num8 = (gcnew System::Windows::Forms::Button());
			this->num9 = (gcnew System::Windows::Forms::Button());
			this->num4 = (gcnew System::Windows::Forms::Button());
			this->num5 = (gcnew System::Windows::Forms::Button());
			this->num6 = (gcnew System::Windows::Forms::Button());
			this->num1 = (gcnew System::Windows::Forms::Button());
			this->num2 = (gcnew System::Windows::Forms::Button());
			this->num3 = (gcnew System::Windows::Forms::Button());
			this->btn_ravno = (gcnew System::Windows::Forms::Button());
			this->inp_main = (gcnew System::Windows::Forms::TextBox());
			this->inp_buf = (gcnew System::Windows::Forms::TextBox());
			this->oper_multi = (gcnew System::Windows::Forms::Button());
			this->oper_plus = (gcnew System::Windows::Forms::Button());
			this->oper_minus = (gcnew System::Windows::Forms::Button());
			this->oper_dev = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// num7
			// 
			this->num7->Location = System::Drawing::Point(14, 130);
			this->num7->Name = L"num7";
			this->num7->Size = System::Drawing::Size(35, 35);
			this->num7->TabIndex = 0;
			this->num7->Text = L"7";
			this->num7->UseVisualStyleBackColor = true;
			this->num7->Click += gcnew System::EventHandler(this, &MyForm::num7_Click);
			// 
			// num8
			// 
			this->num8->Location = System::Drawing::Point(55, 130);
			this->num8->Name = L"num8";
			this->num8->Size = System::Drawing::Size(35, 35);
			this->num8->TabIndex = 1;
			this->num8->Text = L"8";
			this->num8->UseVisualStyleBackColor = true;
			this->num8->Click += gcnew System::EventHandler(this, &MyForm::num8_Click);
			// 
			// num9
			// 
			this->num9->Location = System::Drawing::Point(96, 130);
			this->num9->Name = L"num9";
			this->num9->Size = System::Drawing::Size(35, 35);
			this->num9->TabIndex = 2;
			this->num9->Text = L"9";
			this->num9->UseVisualStyleBackColor = true;
			this->num9->Click += gcnew System::EventHandler(this, &MyForm::num9_Click);
			// 
			// num4
			// 
			this->num4->Location = System::Drawing::Point(14, 171);
			this->num4->Name = L"num4";
			this->num4->Size = System::Drawing::Size(35, 35);
			this->num4->TabIndex = 3;
			this->num4->Text = L"4";
			this->num4->UseVisualStyleBackColor = true;
			this->num4->Click += gcnew System::EventHandler(this, &MyForm::num4_Click);
			// 
			// num5
			// 
			this->num5->Location = System::Drawing::Point(55, 171);
			this->num5->Name = L"num5";
			this->num5->Size = System::Drawing::Size(35, 35);
			this->num5->TabIndex = 4;
			this->num5->Text = L"5";
			this->num5->UseVisualStyleBackColor = true;
			this->num5->Click += gcnew System::EventHandler(this, &MyForm::num5_Click);
			// 
			// num6
			// 
			this->num6->Location = System::Drawing::Point(95, 171);
			this->num6->Name = L"num6";
			this->num6->Size = System::Drawing::Size(35, 35);
			this->num6->TabIndex = 5;
			this->num6->Text = L"6";
			this->num6->UseVisualStyleBackColor = true;
			this->num6->Click += gcnew System::EventHandler(this, &MyForm::num6_Click);
			// 
			// num1
			// 
			this->num1->Location = System::Drawing::Point(14, 212);
			this->num1->Name = L"num1";
			this->num1->Size = System::Drawing::Size(35, 35);
			this->num1->TabIndex = 6;
			this->num1->Text = L"1";
			this->num1->UseVisualStyleBackColor = true;
			this->num1->Click += gcnew System::EventHandler(this, &MyForm::num1_Click);
			// 
			// num2
			// 
			this->num2->Location = System::Drawing::Point(55, 212);
			this->num2->Name = L"num2";
			this->num2->Size = System::Drawing::Size(35, 35);
			this->num2->TabIndex = 7;
			this->num2->Text = L"2";
			this->num2->UseVisualStyleBackColor = true;
			this->num2->Click += gcnew System::EventHandler(this, &MyForm::num2_Click);
			// 
			// num3
			// 
			this->num3->Location = System::Drawing::Point(96, 212);
			this->num3->Name = L"num3";
			this->num3->Size = System::Drawing::Size(35, 35);
			this->num3->TabIndex = 8;
			this->num3->Text = L"3";
			this->num3->UseVisualStyleBackColor = true;
			this->num3->Click += gcnew System::EventHandler(this, &MyForm::num3_Click);
			// 
			// btn_ravno
			// 
			this->btn_ravno->Location = System::Drawing::Point(237, 171);
			this->btn_ravno->Name = L"btn_ravno";
			this->btn_ravno->Size = System::Drawing::Size(35, 75);
			this->btn_ravno->TabIndex = 9;
			this->btn_ravno->Text = L"=";
			this->btn_ravno->UseVisualStyleBackColor = true;
			this->btn_ravno->Click += gcnew System::EventHandler(this, &MyForm::btn_ravno_Click);
			// 
			// inp_main
			// 
			this->inp_main->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->inp_main->Location = System::Drawing::Point(12, 42);
			this->inp_main->MaxLength = 16;
			this->inp_main->Name = L"inp_main";
			this->inp_main->Size = System::Drawing::Size(260, 32);
			this->inp_main->TabIndex = 10;
			this->inp_main->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// inp_buf
			// 
			this->inp_buf->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->inp_buf->Location = System::Drawing::Point(96, 10);
			this->inp_buf->Name = L"inp_buf";
			this->inp_buf->ReadOnly = true;
			this->inp_buf->Size = System::Drawing::Size(176, 23);
			this->inp_buf->TabIndex = 11;
			this->inp_buf->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// oper_multi
			// 
			this->oper_multi->Location = System::Drawing::Point(146, 171);
			this->oper_multi->Name = L"oper_multi";
			this->oper_multi->Size = System::Drawing::Size(35, 35);
			this->oper_multi->TabIndex = 12;
			this->oper_multi->Text = L"*";
			this->oper_multi->UseVisualStyleBackColor = true;
			this->oper_multi->Click += gcnew System::EventHandler(this, &MyForm::oper_multi_Click);
			// 
			// oper_plus
			// 
			this->oper_plus->Location = System::Drawing::Point(187, 171);
			this->oper_plus->Name = L"oper_plus";
			this->oper_plus->Size = System::Drawing::Size(35, 35);
			this->oper_plus->TabIndex = 13;
			this->oper_plus->Text = L"+";
			this->oper_plus->UseVisualStyleBackColor = true;
			this->oper_plus->Click += gcnew System::EventHandler(this, &MyForm::oper_plus_Click);
			// 
			// oper_minus
			// 
			this->oper_minus->Location = System::Drawing::Point(146, 212);
			this->oper_minus->Name = L"oper_minus";
			this->oper_minus->Size = System::Drawing::Size(35, 35);
			this->oper_minus->TabIndex = 14;
			this->oper_minus->Text = L"-";
			this->oper_minus->UseVisualStyleBackColor = true;
			this->oper_minus->Click += gcnew System::EventHandler(this, &MyForm::oper_minus_Click);
			// 
			// oper_dev
			// 
			this->oper_dev->Location = System::Drawing::Point(187, 212);
			this->oper_dev->Name = L"oper_dev";
			this->oper_dev->Size = System::Drawing::Size(35, 35);
			this->oper_dev->TabIndex = 15;
			this->oper_dev->Text = L"/";
			this->oper_dev->UseVisualStyleBackColor = true;
			this->oper_dev->Click += gcnew System::EventHandler(this, &MyForm::oper_dev_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->oper_dev);
			this->Controls->Add(this->oper_minus);
			this->Controls->Add(this->oper_plus);
			this->Controls->Add(this->oper_multi);
			this->Controls->Add(this->inp_buf);
			this->Controls->Add(this->inp_main);
			this->Controls->Add(this->btn_ravno);
			this->Controls->Add(this->num3);
			this->Controls->Add(this->num2);
			this->Controls->Add(this->num1);
			this->Controls->Add(this->num6);
			this->Controls->Add(this->num5);
			this->Controls->Add(this->num4);
			this->Controls->Add(this->num9);
			this->Controls->Add(this->num8);
			this->Controls->Add(this->num7);
			this->Name = L"MyForm";
			this->Text = L"Visual Calculator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	/* MY FUNCTIONS */
private: void inp_num(int val){
			 String^ tb = inp_main->Text;

			 if(tb->Length < 16){
				tb += val;
				inp_main->Text = tb;
			 }
		}
	/* MY FUNCTIONS */

private: System::Void num1_Click(System::Object^  sender, System::EventArgs^  e) {
			inp_num(1);	 
		 }
private: System::Void num2_Click(System::Object^  sender, System::EventArgs^  e) {
			inp_num(2);	 
		 }
private: System::Void num3_Click(System::Object^  sender, System::EventArgs^  e) {
			inp_num(3);	 
		 }
private: System::Void num4_Click(System::Object^  sender, System::EventArgs^  e) {
			inp_num(4);	 
		 }
private: System::Void num5_Click(System::Object^  sender, System::EventArgs^  e) {
			inp_num(5);	 
		 }
private: System::Void num6_Click(System::Object^  sender, System::EventArgs^  e) {
			inp_num(6);	 
		 }
private: System::Void num7_Click(System::Object^  sender, System::EventArgs^  e) {
			inp_num(7);	 
		 }
private: System::Void num8_Click(System::Object^  sender, System::EventArgs^  e) {
			inp_num(8);	 
		 }
private: System::Void num9_Click(System::Object^  sender, System::EventArgs^  e) {
			inp_num(9);	 
		 }
private: System::Void oper_multi_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ data = inp_main->Text;
			 inp_buf->Text = data + " * ";
			 inp_main->Text = "";

			 oper_type = 1;
		 }
private: System::Void btn_ravno_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			int val = Convert::ToInt32(inp_main->Text);
			String^ sval = inp_buf->Text;
			sval = (inp_buf->Text)->Substring(0, inp_buf->Text->Length-2);
					
			int val2 = Convert::ToInt32(sval);

			switch(oper_type){
				case 1:{
					int ans = val * val2;
					inp_buf->Text = "" + ans;

					break;
				}
				case 2:{
					int ans = val + val2;
					inp_buf->Text = "" + ans;

					break;
				}
				case 3:{
					int ans = val2 - val;
					inp_buf->Text = "" + ans;

					break;
				}
				case 4:{
					int ans = val / val2;
					inp_buf->Text = "" + ans;

					break;
				}
			}
			
			inp_main->Text = "";
		 }
private: System::Void oper_plus_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ data = inp_main->Text;
			 inp_buf->Text = data + " + ";
			 inp_main->Text = "";

			 oper_type = 2;
		 }
private: System::Void oper_minus_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ data = inp_main->Text;
			 inp_buf->Text = data + " - ";
			 inp_main->Text = "";

			 oper_type = 3;
		 }
private: System::Void oper_dev_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ data = inp_main->Text;
			 inp_buf->Text = data + " / ";
			 inp_main->Text = "";

			 oper_type = 4;
		 }
};
}
