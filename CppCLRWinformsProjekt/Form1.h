#pragma once
#include <time.h>
#include "Process.h"
#include "LearningRule.h"
#include "Resource.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			srand(time(0));
			sample_count = 0;
			category_count = 7;
			category_now = 1;
			epoch_count = 0;
			neuron_count = 1;
			feature_dim = 2;
			learning_rate = 0.1f;
			total_cycle = 0;

			desired_output = new int[7];
			selected_classes = new int[7];
			for (int i = 0; i < category_count; i++) {
				desired_output[i] = 0;
				selected_classes[i] = 0;
			}				

			selected_rule = learning_rule::PERCEPTRON;
			comboBox1->SelectedIndex = 0;
			comboBox2->SelectedIndex = 0;
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private:
		Samples* samples;                                                               // Struct For Input Information
		int sample_count;                                                               // Input Count
		int category_count;                                                             // Class Count
		int category_now;                                                               // Selected Class
		int epoch_count;                                                                // Max Cycle Number
		int feature_dim;                                                                // 2
		int neuron_count;                                                               // Line Count
		int* desired_output;                                                            // Witch Line For Selected Class
		float learning_rate;                                                            // Learning Rate
		int* selected_classes;                                                          // Selected Classes
		learning_rule::Rule selected_rule;                                              // Selected Learning Rule
		int total_cycle;                                                                // Total Cycle

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^  label_ct;
	private: System::Windows::Forms::Label^  label_cls;
	private: System::Windows::Forms::Label^  label_line;
	private: System::Windows::Forms::Button^  btn_train;
	private: System::Windows::Forms::Button^  btn_clear;
			 System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Ich bin fünfzehn jahre alt.
			 /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->label_ct = (gcnew System::Windows::Forms::Label());
				 this->label_cls = (gcnew System::Windows::Forms::Label());
				 this->label_line = (gcnew System::Windows::Forms::Label());
				 this->btn_train = (gcnew System::Windows::Forms::Button());
				 this->btn_clear = (gcnew System::Windows::Forms::Button());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlLightLight;
				 this->pictureBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->pictureBox1->Location = System::Drawing::Point(5, 11);
				 this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(607, 469);
				 this->pictureBox1->TabIndex = 1;
				 this->pictureBox1->TabStop = false;
				 this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
				 this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseClick);
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(162)));
				 this->label2->Location = System::Drawing::Point(617, 111);
				 this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(90, 16);
				 this->label2->TabIndex = 5;
				 this->label2->Text = L"Sample Count :";
				 // 
				 // comboBox1
				 // 
				 this->comboBox1->FormattingEnabled = true;
				 this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) { L"A", L"B", L"C", L"D", L"E", L"F", L"G" });
				 this->comboBox1->Location = System::Drawing::Point(616, 78);
				 this->comboBox1->Margin = System::Windows::Forms::Padding(2);
				 this->comboBox1->Name = L"comboBox1";
				 this->comboBox1->Size = System::Drawing::Size(157, 21);
				 this->comboBox1->TabIndex = 7;
				 this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(162)));
				 this->label6->Location = System::Drawing::Point(616, 56);
				 this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(77, 20);
				 this->label6->TabIndex = 14;
				 this->label6->Text = L"Class Type";
				 // 
				 // comboBox2
				 // 
				 this->comboBox2->FormattingEnabled = true;
				 this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Perceptron", L"Delta Rule" });
				 this->comboBox2->Location = System::Drawing::Point(616, 33);
				 this->comboBox2->Margin = System::Windows::Forms::Padding(2);
				 this->comboBox2->Name = L"comboBox2";
				 this->comboBox2->Size = System::Drawing::Size(157, 21);
				 this->comboBox2->TabIndex = 17;
				 this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(162)));
				 this->label4->Location = System::Drawing::Point(616, 11);
				 this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(92, 20);
				 this->label4->TabIndex = 18;
				 this->label4->Text = L"Learning rule";
				 // 
				 // label_ct
				 // 
				 this->label_ct->AutoSize = true;
				 this->label_ct->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(162)));
				 this->label_ct->Location = System::Drawing::Point(617, 193);
				 this->label_ct->Name = L"label_ct";
				 this->label_ct->Size = System::Drawing::Size(88, 16);
				 this->label_ct->TabIndex = 19;
				 this->label_ct->Text = L"Total Cycle      :";
				 // 
				 // label_cls
				 // 
				 this->label_cls->AutoSize = true;
				 this->label_cls->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(162)));
				 this->label_cls->Location = System::Drawing::Point(617, 137);
				 this->label_cls->Name = L"label_cls";
				 this->label_cls->Size = System::Drawing::Size(89, 16);
				 this->label_cls->TabIndex = 20;
				 this->label_cls->Text = L"Class Count    :";
				 // 
				 // label_line
				 // 
				 this->label_line->AutoSize = true;
				 this->label_line->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(162)));
				 this->label_line->Location = System::Drawing::Point(617, 165);
				 this->label_line->Name = L"label_line";
				 this->label_line->Size = System::Drawing::Size(89, 16);
				 this->label_line->TabIndex = 21;
				 this->label_line->Text = L"Line Count      :";
				 // 
				 // btn_train
				 // 
				 this->btn_train->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(162)));
				 this->btn_train->Location = System::Drawing::Point(620, 382);
				 this->btn_train->Name = L"btn_train";
				 this->btn_train->Size = System::Drawing::Size(153, 46);
				 this->btn_train->TabIndex = 22;
				 this->btn_train->Text = L"Normalise And Training";
				 this->btn_train->UseVisualStyleBackColor = true;
				 this->btn_train->Click += gcnew System::EventHandler(this, &Form1::btn_train_Click);
				 // 
				 // btn_clear
				 // 
				 this->btn_clear->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(162)));
				 this->btn_clear->Location = System::Drawing::Point(620, 434);
				 this->btn_clear->Name = L"btn_clear";
				 this->btn_clear->Size = System::Drawing::Size(153, 46);
				 this->btn_clear->TabIndex = 23;
				 this->btn_clear->Text = L"Clear";
				 this->btn_clear->UseVisualStyleBackColor = true;
				 this->btn_clear->Click += gcnew System::EventHandler(this, &Form1::btn_clear_Click);
				 // 
				 // Form1
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::SystemColors::ButtonFace;
				 this->ClientSize = System::Drawing::Size(785, 484);
				 this->Controls->Add(this->btn_clear);
				 this->Controls->Add(this->btn_train);
				 this->Controls->Add(this->label_line);
				 this->Controls->Add(this->label_cls);
				 this->Controls->Add(this->label_ct);
				 this->Controls->Add(this->label4);
				 this->Controls->Add(this->comboBox2);
				 this->Controls->Add(this->label6);
				 this->Controls->Add(this->comboBox1);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->pictureBox1);
				 this->Margin = System::Windows::Forms::Padding(2);
				 this->Name = L"Form1";
				 this->Text = L"Form1";
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion

	// Paint Our Picture Box When Program Start
	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Pen^ pen = gcnew Pen(Color::Black, 1.0f);                                         // Set Casual Color
		int center_width, center_height, x1, x2, i; 

		center_width = (int)(pictureBox1->Width / 2);                                     // Set Our Origin Koordinants
		center_height = (int)(pictureBox1->Height / 2);

		e->Graphics->DrawLine(pen, center_width, 0, center_width, pictureBox1->Height);   // Draw X and Y lines
		e->Graphics->DrawLine(pen, 0, center_height, pictureBox1->Width, center_height);

		for (i = 0; i < sample_count; i++) {                                              
			Pen^ pen = gcnew Pen(color_of(samples[i].id), 3.0f);

			x1 = (int)(samples[i].x1 + (pictureBox1->Width >> 1));
			x2 = (int)((pictureBox1->Height >> 1) - samples[i].x2);

			e->Graphics->DrawLine(pen, x1 - 5, x2, x1 + 5, x2);
			e->Graphics->DrawLine(pen, x1, x2 - 5, x1, x2 + 5);
		}

		int* important = new int[6];			// It is so important
		delete[] important;						// Sometimes...
	}

	// Event Event Clicked On Picture Box
	private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Pen^ pen = gcnew Pen(color_of(category_now), 3.0f);                               // Set Casual Color
		int temp_x, temp_y;
		float x1, x2;
		temp_x = (System::Convert::ToInt32(e->X));                                        // Get Mouse Place
		temp_y = (System::Convert::ToInt32(e->Y));

		x1 = (float)(temp_x - (pictureBox1->Width >> 1));
		x2 = (float)((pictureBox1->Height >> 1) - temp_y);
		if (sample_count == 0) {                                                          // Save Our Data In Struct
			sample_count = 1;
			samples = new Samples[1];
			samples[0].x1 = x1;
			samples[0].x2 = x2;
			samples[0].id = category_now;
		}
		else {
			Samples* temp;
			temp = samples;
			sample_count++;
			samples = new Samples[sample_count];
			for (int i = 0; i < sample_count - 1; i++) {
				samples[i].x1 = temp[i].x1;
				samples[i].x2 = temp[i].x2;
				samples[i].id = temp[i].id;
			}

			samples[sample_count - 1].x1 = x1;
			samples[sample_count - 1].x2 = x2;
			samples[sample_count - 1].id = category_now;
			delete temp;
		}
		pictureBox1->CreateGraphics()->DrawLine(pen, temp_x - 5, temp_y, temp_x + 5, temp_y);   // Draw Input Point
		pictureBox1->CreateGraphics()->DrawLine(pen, temp_x, temp_y - 5, temp_x, temp_y + 5);
		label2->Text = "Sample Count  : " + System::Convert::ToString(sample_count);            // Set New Sample Cunt
	}

	// Selected Class Changes
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		category_now = comboBox1->SelectedIndex + 1;
	}

	// Normalise And Train Button Event
	private: System::Void btn_train_Click(System::Object^  sender, System::EventArgs^  e) {
		Pen^ pen = gcnew Pen(Color::Coral, 2.0f);											// Set Casual Color
		total_cycle = 0;                                                                    // Total Cycle At Start

		if (class_count() == 0 && class_count() == 1) neuron_count = 0;                     // Set Line Count
		else if (class_count() == 2) neuron_count = 1;
		else neuron_count = class_count();


		pictureBox1->Refresh();		                                                        // Refresh The Screen

		classes_selected();                                                                 // Calculate Selected Classes

		for (int i = 0; i < neuron_count; i++) {                                            // Loop To Draw All Lines

			float* dataset, *weight, *label;
			float factor;

			dataset = new float[feature_dim * sample_count];
			weight = new float[neuron_count * (feature_dim + 1)];
			label = new float[neuron_count * sample_count];

			for (int j = 0; j < category_count; j++) {                                      // Clear Desired Output Array
				desired_output[j] = 0;
			}

			for (int j = 0; j < category_count; j++) {                                      // Set Desired Output As Needed
				if (selected_classes[i] == 1) {
					desired_output[i] = 1;
					selected_classes[i] = 0;
					pen = gcnew Pen(color_of(i + 1), 2.0f);
					break;
				}
			}

			load_data(dataset, label);

			preprocessing::normalize(dataset, sample_count * feature_dim, &factor);				// Normalize TheData

			preprocessing::randomize(weight, (feature_dim + 1) * neuron_count);					// Initialize The Weights

			learning_rule::supervised(feature_dim, sample_count, neuron_count, dataset, weight, label, selected_rule);  // Main Function

			for (int classifier = 0; classifier < neuron_count; classifier++)                   // Draw Lines
				draw_line(pen, &weight[classifier * (feature_dim + 1)], (int)factor);

			total_cycle += preprocessing::getCycle();                                           // Get Total Cycle
			label_ct->Text = "Total Cycle       : " + total_cycle.ToString();                   // Set Total Cycle
			label_cls->Text = "Classes Count : " + class_count().ToString();                    // Set Class Count
			if (class_count() == 0 || class_count() == 1) {                                     // Set Line Count
				label_line->Text = "Line Count       : 0";
			}
			else if (class_count() == 2) {
				label_line->Text = "Line Count       : 1";
			}
			else {
				label_line->Text = "Line Count       : " + class_count().ToString();
			}

			delete[] dataset, weight, label;
		}
	}

	// Learning Rule Select Event
	private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		switch (comboBox2->SelectedIndex) {
		case 0: selected_rule = learning_rule::PERCEPTRON; break;  // Perceptron Rule Selected
		case 1: selected_rule = learning_rule::DELTA_RULE; break;  // Delta Rule Selected
		}
	}

	// Pick A Color with Sended Number
	private: Drawing::Color color_of(int category) {
		switch (category) {
		case 1: return Color::Black;
		case 2: return Color::Red;
		case 3: return Color::Blue;
		case 4: return Color::Green;
		case 5: return Color::Purple;
		case 6: return Color::Yellow;
		default:return Color::Orange;
		}
	}

	// Save Our Input Data In An Array
	private: void load_data(float *dataset, float *label) {
		for (int i = 0; i < sample_count; i++) {                                           // dataset[X1, Y1, X2, Y2.... Xn, Yn]
			dataset[i * feature_dim] = samples[i].x1;
			dataset[i * feature_dim + 1] = samples[i].x2;

			for (int j = 0; j < neuron_count; j++)
				label[neuron_count * i + j] = desired_output[samples[i].id - 1] & (1 << j);	// Binarize
		}

	}

	// Number Of Total Selected Classes
	private: int class_count() {
		int class_count = 0;

		for (int i = 0; i < category_count; i++) {
			for (int j = 0; j < sample_count; j++) {
				if (samples[j].id == i) {
					class_count++;
					break;
				}
			}
		}
		return class_count;
	}

	// Return  Witch Classes Selected As An Array
	private: void classes_selected() {
		for (int i = 1; i < category_count + 1; i++) {
			for (int j = 0; j < sample_count; j++) {
				if (samples[j].id == i) {
					selected_classes[i-1] = 1;
					break;
				}
			}
		}
	}

	// Draw Line With Given Points
	private: void draw_line(Pen ^pen, float *weight, int factor) {
		int min_x, max_x, min_y, max_y;

		min_x = (this->pictureBox1->Width) / -2;
		max_x = (this->pictureBox1->Width) / 2;

		min_y = YPoint(min_x, weight, (int)factor);
		max_y = YPoint(max_x, weight, (int)factor);
		pictureBox1->CreateGraphics()->DrawLine(pen, (pictureBox1->Width / 2) + min_x, (pictureBox1->Height / 2) - min_y, (pictureBox1->Width / 2) + max_x, (pictureBox1->Height / 2) - max_y);
	}

	// Clear Our Picture Box
	private: System::Void btn_clear_Click(System::Object^  sender, System::EventArgs^  e) {
		pictureBox1->Image = nullptr;
		
		sample_count = 0;
		category_count = 7;
		category_now = 1;
		epoch_count = 0;
		neuron_count = 1;
		feature_dim = 2;
		learning_rate = 0.1f;
		total_cycle = 0;

		desired_output = new int[7];
		selected_classes = new int[7];
		for (int i = 0; i < category_count; i++) {
			desired_output[i] = 0;
			selected_classes[i] = 0;
		}

		selected_rule = learning_rule::PERCEPTRON;
		comboBox1->SelectedIndex = 0;
		comboBox2->SelectedIndex = 0;

		label2->Text = "Sample Count  : ";
		label_line->Text = "Line Count       : ";
		label_cls->Text = "Classes Count : ";
		label_ct->Text = "Total Cycle       : ";
	}
};
}
