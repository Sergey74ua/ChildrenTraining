#pragma once

#include "SelectDB.h"
#include <string>
#include <ctime>

namespace Shop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
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
			srand(time(NULL));
			fillShaft(shaft);
			fillCore(core);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
		List<KeyValuePair<String^, int>>^ shaft = gcnew List<KeyValuePair<String^, int>>();
		KeyValuePair<String^, int> selectShaft;
		List<KeyValuePair<String^, int>>^ core = gcnew List<KeyValuePair<String^, int>>();
		KeyValuePair<String^, int> selectCore;
		KeyValuePair<String^, int> minStaff;
		KeyValuePair<String^, int> maxStaff;
		KeyValuePair<String^, int> randShaft;
		KeyValuePair<String^, int> randCore;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			//Заполняем данные по рукояткам и сердцевинам
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Dock = System::Windows::Forms::DockStyle::Top;
			this->label1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Chartreuse;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(784, 50);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Лавка Оливандера 2.0";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownWidth = 250;
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(22, 39);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(300, 26);
			this->comboBox1->TabIndex = 1;
			this->comboBox1->Text = L"Рукоять";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox1_SelectedIndexChanged);
			this->comboBox1->DataSource = shaft; //Заполняем меню выпадающего списка рукояток
			// 
			// comboBox2
			// 
			this->comboBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->comboBox2->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(439, 39);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(300, 26);
			this->comboBox2->TabIndex = 2;
			this->comboBox2->Text = L"Сердцевина";
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox2_SelectedIndexChanged);
			this->comboBox2->DataSource = core; //Заполняем меню выпадающего списка сердцевин
			
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->comboBox2);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->ForeColor = System::Drawing::SystemColors::Control;
			this->groupBox1->Location = System::Drawing::Point(7, 50);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(765, 200);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Вариант 1";
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::Gold;
			this->label3->Location = System::Drawing::Point(22, 129);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(717, 48);
			this->label3->TabIndex = 4;
			this->label3->Text = L"цена";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Violet;
			this->label2->Location = System::Drawing::Point(22, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(717, 48);
			this->label2->TabIndex = 3;
			this->label2->Text = L"выберите рукоять и сердцевину";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox2->ForeColor = System::Drawing::SystemColors::Control;
			this->groupBox2->Location = System::Drawing::Point(7, 256);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(765, 140);
			this->groupBox2->TabIndex = 7;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Вариант 2";
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label6->Location = System::Drawing::Point(188, 19);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(381, 23);
			this->label6->TabIndex = 4;
			this->label6->Text = L"выбирите вариант";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::Gold;
			this->label5->Location = System::Drawing::Point(192, 89);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(381, 48);
			this->label5->TabIndex = 4;
			this->label5->Text = L"цена";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button2->Location = System::Drawing::Point(579, 38);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(160, 60);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Максимальная цена";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::Violet;
			this->label4->Location = System::Drawing::Point(188, 42);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(385, 48);
			this->label4->TabIndex = 3;
			this->label4->Text = L"выберите рукоять и сердцевину";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button1->Location = System::Drawing::Point(22, 38);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(160, 60);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Минимальная цена";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Controls->Add(this->label7);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox3->ForeColor = System::Drawing::SystemColors::Control;
			this->groupBox3->Location = System::Drawing::Point(7, 402);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(765, 140);
			this->groupBox3->TabIndex = 8;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Вариант 3";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button3->Location = System::Drawing::Point(22, 41);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(160, 60);
			this->button3->TabIndex = 0;
			this->button3->Text = L"Случайный посох";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label8
			// 
			this->label8->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->ForeColor = System::Drawing::Color::Gold;
			this->label8->Location = System::Drawing::Point(196, 67);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(543, 48);
			this->label8->TabIndex = 4;
			this->label8->Text = L"цена";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->ForeColor = System::Drawing::Color::Violet;
			this->label7->Location = System::Drawing::Point(196, 19);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(543, 48);
			this->label7->TabIndex = 3;
			this->label7->Text = L"выберите рукоять и сердцевину";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkGreen;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Ollivander\'s Shop 2.0";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->ResumeLayout(false);
		}
#pragma endregion
	//Загрузка формы
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	//Выбор рукоятки
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		selectShaft = (KeyValuePair<String^, int>)comboBox1->SelectedValue;
		this->label2->Text = System::Convert::ToString(selectShaft.Key + " + " + selectCore.Key);
		this->label3->Text = System::Convert::ToString(selectShaft.Value + selectCore.Value + " галлеонов");
	}
	//Выбор сердцевины
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		selectCore = (KeyValuePair<String^, int>)comboBox2->SelectedValue;
		this->label2->Text = System::Convert::ToString(selectShaft.Key + " + " + selectCore.Key);
		this->label3->Text = System::Convert::ToString(selectShaft.Value + selectCore.Value + " галлеонов");
	}
	//Минимальная цена
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		minStaff = KeyValuePair<String^, int>(L"Остролист + Жилы из крыла летучей мыши", 1 + 1);
		this->label4->Text = System::Convert::ToString(minStaff.Key);
		this->label5->Text = System::Convert::ToString(minStaff.Value + " галлеонов");
		this->label6->Text = L"Самый дешевый посох";
	}
	//Максимальная цена
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		maxStaff = KeyValuePair<String^, int>(L"Явор (белый клён) + Зуб василиска", 11 + 8);
		this->label4->Text = System::Convert::ToString(maxStaff.Key);
		this->label5->Text = System::Convert::ToString(maxStaff.Value + " галлеонов");
		this->label6->Text = L"Самый дорогой посох";
	}
	//Случайная цена
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		randShaft = (KeyValuePair<String^, int>)comboBox1->Items[rand() % 39];
		randCore = (KeyValuePair<String^, int>)comboBox2->Items[rand() % 23];
		this->label7->Text = System::Convert::ToString(randShaft.Key + randCore.Key);
		this->label8->Text = System::Convert::ToString(randShaft.Value + randCore.Value + " галлеонов");
	}
};
}