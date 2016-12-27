#pragma once
#include "CGALHolder.h"

namespace sample {

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

		public: Graphics^ g;
				Pen^ pen;
				CGALHolder* cgalHolder;

		public:
			MyForm(void)
			{
				InitializeComponent();
				g = pictureBox1->CreateGraphics();
				pen = gcnew Pen(Color::Black);
				cgalHolder = new CGALHolder();
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
		private: System::Windows::Forms::MenuStrip^  menuStrip1;
		protected:
		private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
		private: System::Windows::Forms::ToolStripMenuItem^  convexhullToolStripMenuItem;
		private: System::Windows::Forms::PictureBox^  pictureBox1;

		private:
			/// <summary>
			/// ќб€зательна€ переменна€ конструктора.
			/// </summary>
			System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			/// <summary>
			/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
			/// содержимое этого метода с помощью редактора кода.
			/// </summary>
			void InitializeComponent(void)
			{
				this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->convexhullToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				this->menuStrip1->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				this->SuspendLayout();
				// 
				// menuStrip1
				// 
				this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->editToolStripMenuItem });
				this->menuStrip1->Location = System::Drawing::Point(0, 0);
				this->menuStrip1->Name = L"menuStrip1";
				this->menuStrip1->Size = System::Drawing::Size(568, 24);
				this->menuStrip1->TabIndex = 0;
				this->menuStrip1->Text = L"menuStrip1";
				// 
				// editToolStripMenuItem
				// 
				this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->convexhullToolStripMenuItem });
				this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
				this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
				this->editToolStripMenuItem->Text = L"Edit";
				// 
				// convexhullToolStripMenuItem
				// 
				this->convexhullToolStripMenuItem->Name = L"convexhullToolStripMenuItem";
				this->convexhullToolStripMenuItem->Size = System::Drawing::Size(152, 22);
				this->convexhullToolStripMenuItem->Text = L"convex_hull";
				this->convexhullToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::convexhullToolStripMenuItem_Click);
				// 
				// pictureBox1
				// 
				this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
				this->pictureBox1->Location = System::Drawing::Point(0, 24);
				this->pictureBox1->Name = L"pictureBox1";
				this->pictureBox1->Size = System::Drawing::Size(568, 384);
				this->pictureBox1->TabIndex = 1;
				this->pictureBox1->TabStop = false;
				// 
				// MyForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->ClientSize = System::Drawing::Size(568, 408);
				this->Controls->Add(this->pictureBox1);
				this->Controls->Add(this->menuStrip1);
				this->MainMenuStrip = this->menuStrip1;
				this->Name = L"MyForm";
				this->Text = L"MyForm";
				this->menuStrip1->ResumeLayout(false);
				this->menuStrip1->PerformLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				this->ResumeLayout(false);
				this->PerformLayout();

			}
#pragma endregion
		private: System::Void convexhullToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			cgalHolder->addPoint(5,10);
			cgalHolder->addPoint(350, 30);
			cgalHolder->addPoint(400, 200);
			cgalHolder->addPoint(200, 350);
			cgalHolder->addPoint(80, 100);
			cgalHolder->paintConvexHull(g, Pens::Black, cgalHolder->simpleConvexHull());
		}
		};
}
