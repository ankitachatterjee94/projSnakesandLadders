#pragma once
#include"includes.h"

//external function declarations
//only those functions which are required by this module need to be declared
//the rest can be declared in the cpp file itself
void init();
void ballTimer();
void diceTimer();
void rolldice();

namespace projSnakesAndLadders {

	public ref class frmMain : public System::Windows::Forms::Form
	{
	public:
		frmMain(void)
		{
			//store handle to main UI
			UI<projSnakesAndLadders::frmMain>::set(this);
			//initialize form controls
			InitializeComponent();
			//adjust ball layout in GUI
			this->ball1->Parent = this->picBoard;
			this->ball2->Parent = this->picBoard;
			//start a new game
			init();
		}

#pragma region Control creation
		System::Windows::Forms::SplitContainer^  mainPanel;
		System::Windows::Forms::PictureBox^  picBoard;
		System::Windows::Forms::PictureBox^  ball1;
		System::Windows::Forms::PictureBox^  ball2;
		System::Windows::Forms::Timer^  tmrMove;
		System::Windows::Forms::Timer^  tmrDice;
		System::Windows::Forms::PictureBox^  d6;
		System::Windows::Forms::PictureBox^  d2;
		System::Windows::Forms::PictureBox^  d4;
		System::Windows::Forms::PictureBox^  d5;
		System::Windows::Forms::PictureBox^  d1;
		System::Windows::Forms::PictureBox^  d3;
		System::Windows::Forms::PictureBox^  imgDice;
		System::Windows::Forms::GroupBox^  groupBox2;
		System::Windows::Forms::GroupBox^  groupBox1;
		System::Windows::Forms::Label^  lblStatus;
		System::Windows::Forms::Label^  lblbonus2;
		System::Windows::Forms::Label^  lblsnake2;
		System::Windows::Forms::Label^  lbllad2;
		System::Windows::Forms::Label^  lblmoves2;
		System::Windows::Forms::Label^  label5;
		System::Windows::Forms::Label^  label6;
		System::Windows::Forms::Label^  label7;
		System::Windows::Forms::Label^  label8;
		System::Windows::Forms::Label^  lblbonus1;
		System::Windows::Forms::Label^  lblsnake1;
		System::Windows::Forms::Label^  lbllad1;
		System::Windows::Forms::Label^  lblmoves1;
		System::Windows::Forms::Label^  label4;
		System::Windows::Forms::Label^  label3;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::Panel^  pnlWin;
		System::Windows::Forms::Button^  button2;
		System::Windows::Forms::Button^  button1;
		System::Windows::Forms::Label^  lblwin;
		System::ComponentModel::IContainer^  components;

#pragma endregion

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmMain()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMain::typeid));
			this->mainPanel = (gcnew System::Windows::Forms::SplitContainer());
			this->ball2 = (gcnew System::Windows::Forms::PictureBox());
			this->ball1 = (gcnew System::Windows::Forms::PictureBox());
			this->picBoard = (gcnew System::Windows::Forms::PictureBox());
			this->pnlWin = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->lblwin = (gcnew System::Windows::Forms::Label());
			this->lblStatus = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->lblbonus2 = (gcnew System::Windows::Forms::Label());
			this->lblsnake2 = (gcnew System::Windows::Forms::Label());
			this->lbllad2 = (gcnew System::Windows::Forms::Label());
			this->lblmoves2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->lblbonus1 = (gcnew System::Windows::Forms::Label());
			this->lblsnake1 = (gcnew System::Windows::Forms::Label());
			this->lbllad1 = (gcnew System::Windows::Forms::Label());
			this->lblmoves1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->imgDice = (gcnew System::Windows::Forms::PictureBox());
			this->d2 = (gcnew System::Windows::Forms::PictureBox());
			this->d4 = (gcnew System::Windows::Forms::PictureBox());
			this->d5 = (gcnew System::Windows::Forms::PictureBox());
			this->d1 = (gcnew System::Windows::Forms::PictureBox());
			this->d3 = (gcnew System::Windows::Forms::PictureBox());
			this->d6 = (gcnew System::Windows::Forms::PictureBox());
			this->tmrMove = (gcnew System::Windows::Forms::Timer(this->components));
			this->tmrDice = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainPanel))->BeginInit();
			this->mainPanel->Panel1->SuspendLayout();
			this->mainPanel->Panel2->SuspendLayout();
			this->mainPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ball2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ball1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoard))->BeginInit();
			this->pnlWin->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgDice))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->d2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->d4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->d5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->d1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->d3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->d6))->BeginInit();
			this->SuspendLayout();
			// 
			// mainPanel
			// 
			this->mainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainPanel->IsSplitterFixed = true;
			this->mainPanel->Location = System::Drawing::Point(0, 0);
			this->mainPanel->Name = L"mainPanel";
			// 
			// mainPanel.Panel1
			// 
			this->mainPanel->Panel1->Controls->Add(this->ball2);
			this->mainPanel->Panel1->Controls->Add(this->ball1);
			this->mainPanel->Panel1->Controls->Add(this->picBoard);
			// 
			// mainPanel.Panel2
			// 
			this->mainPanel->Panel2->Controls->Add(this->pnlWin);
			this->mainPanel->Panel2->Controls->Add(this->lblStatus);
			this->mainPanel->Panel2->Controls->Add(this->groupBox2);
			this->mainPanel->Panel2->Controls->Add(this->groupBox1);
			this->mainPanel->Panel2->Controls->Add(this->imgDice);
			this->mainPanel->Panel2->Controls->Add(this->d2);
			this->mainPanel->Panel2->Controls->Add(this->d4);
			this->mainPanel->Panel2->Controls->Add(this->d5);
			this->mainPanel->Panel2->Controls->Add(this->d1);
			this->mainPanel->Panel2->Controls->Add(this->d3);
			this->mainPanel->Panel2->Controls->Add(this->d6);
			this->mainPanel->Size = System::Drawing::Size(998, 564);
			this->mainPanel->SplitterDistance = 760;
			this->mainPanel->SplitterWidth = 1;
			this->mainPanel->TabIndex = 0;
			// 
			// ball2
			// 
			this->ball2->BackColor = System::Drawing::Color::Transparent;
			this->ball2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ball2.Image")));
			this->ball2->Location = System::Drawing::Point(21, 517);
			this->ball2->Name = L"ball2";
			this->ball2->Size = System::Drawing::Size(40, 40);
			this->ball2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->ball2->TabIndex = 1;
			this->ball2->TabStop = false;
			this->ball2->Tag = L"2";
			// 
			// ball1
			// 
			this->ball1->BackColor = System::Drawing::Color::Transparent;
			this->ball1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ball1.Image")));
			this->ball1->Location = System::Drawing::Point(20, 517);
			this->ball1->Name = L"ball1";
			this->ball1->Size = System::Drawing::Size(40, 40);
			this->ball1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->ball1->TabIndex = 2;
			this->ball1->TabStop = false;
			this->ball1->Tag = L"1";
			// 
			// picBoard
			// 
			this->picBoard->Dock = System::Windows::Forms::DockStyle::Fill;
			this->picBoard->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBoard.Image")));
			this->picBoard->Location = System::Drawing::Point(0, 0);
			this->picBoard->Name = L"picBoard";
			this->picBoard->Size = System::Drawing::Size(760, 564);
			this->picBoard->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->picBoard->TabIndex = 0;
			this->picBoard->TabStop = false;
			// 
			// pnlWin
			// 
			this->pnlWin->Controls->Add(this->button2);
			this->pnlWin->Controls->Add(this->button1);
			this->pnlWin->Controls->Add(this->lblwin);
			this->pnlWin->Location = System::Drawing::Point(-8, 0);
			this->pnlWin->Name = L"pnlWin";
			this->pnlWin->Size = System::Drawing::Size(242, 564);
			this->pnlWin->TabIndex = 3;
			this->pnlWin->Visible = false;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(83, 291);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Quit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMain::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(66, 260);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(111, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Play another game";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMain::button1_Click);
			// 
			// lblwin
			// 
			this->lblwin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblwin->Location = System::Drawing::Point(3, 201);
			this->lblwin->Name = L"lblwin";
			this->lblwin->Size = System::Drawing::Size(236, 36);
			this->lblwin->TabIndex = 0;
			this->lblwin->Text = L"Player 1 won!";
			this->lblwin->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblStatus
			// 
			this->lblStatus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblStatus->AutoSize = true;
			this->lblStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStatus->Location = System::Drawing::Point(17, 468);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(100, 20);
			this->lblStatus->TabIndex = 9;
			this->lblStatus->Text = L"Roll the dice!";
			this->lblStatus->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::Transparent;
			this->groupBox2->Controls->Add(this->lblbonus2);
			this->groupBox2->Controls->Add(this->lblsnake2);
			this->groupBox2->Controls->Add(this->lbllad2);
			this->groupBox2->Controls->Add(this->lblmoves2);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->ForeColor = System::Drawing::Color::Green;
			this->groupBox2->Location = System::Drawing::Point(3, 185);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(228, 194);
			this->groupBox2->TabIndex = 8;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Player 2";
			// 
			// lblbonus2
			// 
			this->lblbonus2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblbonus2->Location = System::Drawing::Point(171, 133);
			this->lblbonus2->Name = L"lblbonus2";
			this->lblbonus2->Size = System::Drawing::Size(42, 13);
			this->lblbonus2->TabIndex = 11;
			this->lblbonus2->Text = L"0";
			this->lblbonus2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lblsnake2
			// 
			this->lblsnake2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblsnake2->Location = System::Drawing::Point(171, 101);
			this->lblsnake2->Name = L"lblsnake2";
			this->lblsnake2->Size = System::Drawing::Size(42, 13);
			this->lblsnake2->TabIndex = 10;
			this->lblsnake2->Text = L"0";
			this->lblsnake2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lbllad2
			// 
			this->lbllad2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lbllad2->Location = System::Drawing::Point(165, 70);
			this->lbllad2->Name = L"lbllad2";
			this->lbllad2->Size = System::Drawing::Size(48, 13);
			this->lbllad2->TabIndex = 9;
			this->lbllad2->Text = L"0";
			this->lbllad2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lblmoves2
			// 
			this->lblmoves2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblmoves2->Location = System::Drawing::Point(171, 37);
			this->lblmoves2->Name = L"lblmoves2";
			this->lblmoves2->Size = System::Drawing::Size(42, 13);
			this->lblmoves2->TabIndex = 8;
			this->lblmoves2->Text = L"0";
			this->lblmoves2->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(15, 133);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(74, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Bonus moves:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(15, 101);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(74, 13);
			this->label6->TabIndex = 6;
			this->label6->Text = L"Snakes fallen:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(15, 70);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(87, 13);
			this->label7->TabIndex = 5;
			this->label7->Text = L"Ladders climbed:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(15, 37);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(73, 13);
			this->label8->TabIndex = 4;
			this->label8->Text = L"No. of moves:";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::Color::Transparent;
			this->groupBox1->Controls->Add(this->lblbonus1);
			this->groupBox1->Controls->Add(this->lblsnake1);
			this->groupBox1->Controls->Add(this->lbllad1);
			this->groupBox1->Controls->Add(this->lblmoves1);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->ForeColor = System::Drawing::Color::Red;
			this->groupBox1->Location = System::Drawing::Point(3, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(228, 194);
			this->groupBox1->TabIndex = 7;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Player 1";
			// 
			// lblbonus1
			// 
			this->lblbonus1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblbonus1->Location = System::Drawing::Point(171, 132);
			this->lblbonus1->Name = L"lblbonus1";
			this->lblbonus1->Size = System::Drawing::Size(42, 13);
			this->lblbonus1->TabIndex = 7;
			this->lblbonus1->Text = L"0";
			this->lblbonus1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lblsnake1
			// 
			this->lblsnake1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblsnake1->Location = System::Drawing::Point(168, 100);
			this->lblsnake1->Name = L"lblsnake1";
			this->lblsnake1->Size = System::Drawing::Size(45, 13);
			this->lblsnake1->TabIndex = 6;
			this->lblsnake1->Text = L"0";
			this->lblsnake1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lbllad1
			// 
			this->lbllad1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lbllad1->Location = System::Drawing::Point(165, 69);
			this->lbllad1->Name = L"lbllad1";
			this->lbllad1->Size = System::Drawing::Size(48, 13);
			this->lbllad1->TabIndex = 5;
			this->lbllad1->Text = L"0";
			this->lbllad1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lblmoves1
			// 
			this->lblmoves1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->lblmoves1->Location = System::Drawing::Point(162, 36);
			this->lblmoves1->Name = L"lblmoves1";
			this->lblmoves1->Size = System::Drawing::Size(51, 13);
			this->lblmoves1->TabIndex = 4;
			this->lblmoves1->Text = L"0";
			this->lblmoves1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(15, 132);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(75, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Bonus Moves:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(15, 100);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(74, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Snakes fallen:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Ladders climbed:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(15, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"No. of moves:";
			// 
			// imgDice
			// 
			this->imgDice->Cursor = System::Windows::Forms::Cursors::Hand;
			this->imgDice->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imgDice.Image")));
			this->imgDice->Location = System::Drawing::Point(165, 499);
			this->imgDice->Name = L"imgDice";
			this->imgDice->Size = System::Drawing::Size(57, 60);
			this->imgDice->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->imgDice->TabIndex = 6;
			this->imgDice->TabStop = false;
			this->imgDice->Click += gcnew System::EventHandler(this, &frmMain::imgDice_Click);
			// 
			// d2
			// 
			this->d2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"d2.Image")));
			this->d2->Location = System::Drawing::Point(12, 509);
			this->d2->Name = L"d2";
			this->d2->Size = System::Drawing::Size(50, 50);
			this->d2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->d2->TabIndex = 5;
			this->d2->TabStop = false;
			this->d2->Visible = false;
			// 
			// d4
			// 
			this->d4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"d4.Image")));
			this->d4->Location = System::Drawing::Point(12, 504);
			this->d4->Name = L"d4";
			this->d4->Size = System::Drawing::Size(50, 50);
			this->d4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->d4->TabIndex = 4;
			this->d4->TabStop = false;
			this->d4->Visible = false;
			// 
			// d5
			// 
			this->d5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"d5.Image")));
			this->d5->Location = System::Drawing::Point(21, 513);
			this->d5->Name = L"d5";
			this->d5->Size = System::Drawing::Size(50, 50);
			this->d5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->d5->TabIndex = 3;
			this->d5->TabStop = false;
			this->d5->Visible = false;
			// 
			// d1
			// 
			this->d1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"d1.Image")));
			this->d1->Location = System::Drawing::Point(21, 504);
			this->d1->Name = L"d1";
			this->d1->Size = System::Drawing::Size(50, 50);
			this->d1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->d1->TabIndex = 2;
			this->d1->TabStop = false;
			this->d1->Visible = false;
			// 
			// d3
			// 
			this->d3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"d3.Image")));
			this->d3->Location = System::Drawing::Point(21, 504);
			this->d3->Name = L"d3";
			this->d3->Size = System::Drawing::Size(50, 50);
			this->d3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->d3->TabIndex = 1;
			this->d3->TabStop = false;
			this->d3->Visible = false;
			// 
			// d6
			// 
			this->d6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"d6.Image")));
			this->d6->Location = System::Drawing::Point(21, 504);
			this->d6->Name = L"d6";
			this->d6->Size = System::Drawing::Size(50, 50);
			this->d6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->d6->TabIndex = 0;
			this->d6->TabStop = false;
			this->d6->Visible = false;
			// 
			// tmrMove
			// 
			this->tmrMove->Interval = 10;
			this->tmrMove->Tick += gcnew System::EventHandler(this, &frmMain::tmrMove_Tick);
			// 
			// tmrDice
			// 
			this->tmrDice->Interval = 50;
			this->tmrDice->Tick += gcnew System::EventHandler(this, &frmMain::tmrDice_Tick);
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(998, 564);
			this->Controls->Add(this->mainPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"frmMain";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Snakes & Ladders";
			this->mainPanel->Panel1->ResumeLayout(false);
			this->mainPanel->Panel2->ResumeLayout(false);
			this->mainPanel->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mainPanel))->EndInit();
			this->mainPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ball2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ball1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBoard))->EndInit();
			this->pnlWin->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgDice))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->d2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->d4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->d5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->d1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->d3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->d6))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void tmrMove_Tick(System::Object^  sender, System::EventArgs^  e) {
			ballTimer();
		}

	private: System::Void tmrDice_Tick(System::Object^  sender, System::EventArgs^  e) {
			diceTimer();
		}

	private: System::Void imgDice_Click(System::Object^  sender, System::EventArgs^  e) {
			rolldice();
		}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			init();
		}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			Application::Exit();
		}

	};

}
