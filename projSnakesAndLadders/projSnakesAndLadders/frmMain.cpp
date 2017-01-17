#pragma once
#include"frmMain.h"
#include<random>
using namespace projSnakesAndLadders;

//remaining function declarations
void moveBall(int, Point, Point);
void moveBall(int, int, int);
void moveBall(int, Ball&, int);
Point calculatePositionfromNo(int);
void move_callback(Point);
void checkStatus(Ball, int, int);
void switchPlayer();
void gamewon(int);
void dice_callback(int);

//global variable declarations
Player currentPlayer = PLAYER_1;
Ball B1, B2;
Ladder ladder;
Snake snake;
bool changePlayer;
float heightDiff = (float)56.4, widthDiff = (float)76;

void init()
{
	using namespace scores;
	bonus1 = bonus2 = moves1 = moves2 = snake1 = snake2 = ladder1 = ladder2 = 0;
	UI<frmMain>::get()->pnlWin->Visible = false;
	UI<frmMain>::get()->lblStatus->Text = "Player 1 chance!";
	UI<frmMain>::get()->lblbonus1->Text = "0";
	UI<frmMain>::get()->lblbonus2->Text = "0";
	UI<frmMain>::get()->lblmoves1->Text = "0";
	UI<frmMain>::get()->lblmoves2->Text = "0";
	UI<frmMain>::get()->lbllad1->Text = "0";
	UI<frmMain>::get()->lbllad2->Text = "0";
	UI<frmMain>::get()->lblsnake1->Text = "0";
	UI<frmMain>::get()->lblsnake2->Text = "0";
	currentPlayer = PLAYER_1;
	moveDice::count = 0;
	moveDice::running = false;
	moveBallSetup::completed = true;
	B1.init();
	B2.init();
	UI<frmMain>::get()->ball1->Location = B1.position;
	UI<frmMain>::get()->ball2->Location = Point(B2.position.X, B2.position.Y - 5);
}

void ballTimer() {
	using namespace moveBallSetup;

	if (current.X != to.X || current.Y != to.Y)
	{
		if (current.X < to.X)
			current.X += speed;
		else if (current.X > to.X)
			current.X -= speed;
		if (current.Y<to.Y)
			current.Y += speed;
		else if (current.Y > to.Y)
			current.Y -= speed;
		if (ballNo == 1)
		{
			UI<projSnakesAndLadders::frmMain>::get()->ball1->Location = current;
			B1.setPos(current);
		}
		else if (ballNo == 2)
		{
			UI<projSnakesAndLadders::frmMain>::get()->ball2->Location = current;
			B2.setPos(current);
		}
	}
	else
	{
		if (B1.noInBoard == B2.noInBoard) {
			UI<frmMain>::get()->ball2->Location = Point(UI<frmMain>::get()->ball2->Location.X, UI<frmMain>::get()->ball2->Location.Y - 5);
			B2.setPos(UI<frmMain>::get()->ball2->Location);
		}
		UI<frmMain>::get()->tmrMove->Enabled = false;
		moveBallSetup::completed = true;
		move_callback(moveBallSetup::current);
	}
}

void moveBall(int ballNo, Point from, Point to) {
	if (!moveBallSetup::completed)
		return;
	moveBallSetup::ballNo = ballNo;
	moveBallSetup::from = from;
	moveBallSetup::to = to;
	moveBallSetup::current = from;
	moveBallSetup::completed = false;
	UI<frmMain>::get()->tmrMove->Enabled = true;

}

void moveBall(int ballNo, int fromPosition, int toPosition) {

		if (!moveBallSetup::completed)
			return;
		if (ballNo == 1)
			B1.noInBoard = toPosition;
		else if (ballNo == 2)
			B2.noInBoard = toPosition;
		moveBall(ballNo, calculatePositionfromNo(fromPosition), calculatePositionfromNo(toPosition));

	}

void moveBall(int ballNo, Ball& b, int steps) {
		if (!moveBallSetup::completed)
			return;
		b.noInBoard = b.noInBoard + steps;
		moveBall(ballNo, b.position, calculatePositionfromNo(b.noInBoard));
	}

Point calculatePositionfromNo(int no){
	Point d;
	d.Y = (int)(10 * heightDiff - ((no - 1) / 10)*heightDiff - heightDiff / 2 - 20);
	if (!(((no - 1) / 10) % 2))
		d.X = (int)(((no - 1) % 10)*widthDiff + widthDiff / 2 - 20);
	else
		d.X = (int)(10 * widthDiff - ((no - 1) % 10)*widthDiff - widthDiff / 2 - 20);
	return d;
}

void move_callback(Point last) {

	//set dice image to be rolled again
	UI<frmMain>::get()->imgDice->Image = (cli::safe_cast<System::Drawing::Image^>((gcnew System::ComponentModel::ComponentResourceManager(frmMain::typeid))->GetObject(L"imgDice.Image")));

	if (currentPlayer == PLAYER_1) {
		checkStatus(B1, 1, moveDice::face);
	}
	else if (currentPlayer == PLAYER_2) {
		checkStatus(B2, 2, moveDice::face);
	}
}

void checkStatus(Ball b, int ballNo, int diceFace){

	//checkforSix();
	if (diceFace == 6)
	{
		UI<frmMain>::get()->lblStatus->Text = "Player " + ballNo.ToString() + " roll dice again!";

		if (ballNo == 1)
		{
			scores::bonus1++;
			UI<frmMain>::get()->lblbonus1->Text = scores::bonus1.ToString();
		}
		else
		{
			scores::bonus2++;
			UI<frmMain>::get()->lblbonus2->Text = scores::bonus2.ToString();
		}

		return;
	}

	//checkforLadder();
	if (ladder.search(b.noInBoard))
	{
		moveBall(ballNo, b.noInBoard, ladder.to());

		if (ballNo == 1)
		{
			scores::ladder1++;
			UI<frmMain>::get()->lbllad1->Text = scores::ladder1.ToString();
		}
		else
		{
			scores::ladder2++;
			UI<frmMain>::get()->lbllad2->Text = scores::ladder2.ToString();
		}
	}

	//checkforSnake();
	if (snake.search(b.noInBoard))
	{
		moveBall(ballNo, b.noInBoard, snake.to());

		if (ballNo == 1)
		{
			scores::snake1++;
			UI<frmMain>::get()->lblsnake1->Text = scores::snake1.ToString();
		}
		else
		{
			scores::snake2++;
			UI<frmMain>::get()->lblsnake2->Text = scores::snake2.ToString();
		}
	}

	//checkforWin();
	if (b.noInBoard == 100)
	{
		UI<frmMain>::get()->lblStatus->Text = "Player " + ballNo.ToString() + " Wins!!";
		gamewon(ballNo);

	}

	//changePlayer();
	if (changePlayer)
		switchPlayer();

}

void switchPlayer() {
	currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
	UI<frmMain>::get()->lblStatus->Text = "Player " + (currentPlayer == PLAYER_1 ? 1 : 2).ToString() + " chance!";
	changePlayer = false;
}

void gamewon(int player) {
	UI<frmMain>::get()->lblwin->Text = "Player " + player.ToString() + " Wins!";
	UI<frmMain>::get()->pnlWin->Visible = true;
}

void diceTimer() {
	if (moveDice::running && moveDice::count < moveDice::max)
	{
		random_device generator;
		uniform_int_distribution<int> distribution;
		distribution = uniform_int_distribution<int>(1, 6);
		moveDice::face = distribution(generator);
		UI<frmMain>::get()->imgDice->Image = (cli::safe_cast<System::Drawing::Image^>((gcnew System::ComponentModel::ComponentResourceManager(frmMain::typeid))->GetObject(L"d" + moveDice::face.ToString() + ".Image")));
		moveDice::count++;
	}
	else
	{
		UI<frmMain>::get()->tmrDice->Enabled = false;
		moveDice::running = false;
		moveDice::count = 0;
		dice_callback(moveDice::face);
	}
}

void rolldice() {
	if (moveDice::running || (!moveBallSetup::completed))
		return;
	moveDice::running = true;
	UI<frmMain>::get()->tmrDice->Enabled = true;
}

void dice_callback(int face){
	changePlayer = true;
	if (currentPlayer == PLAYER_1) {
		scores::moves1++;
		UI<frmMain>::get()->lblmoves1->Text = scores::moves1.ToString();

		if (B1.noInBoard + face <= 100)
			if (!(B1.noInBoard + face == 100 && face == 6))
				moveBall(1, B1, face);
			else
				switchPlayer();
		else
			switchPlayer();

	}
	else if (currentPlayer == PLAYER_2) {
		scores::moves2++;
		UI<frmMain>::get()->lblmoves2->Text = scores::moves2.ToString();

		if (B2.noInBoard + face <= 100)
			if (!(B2.noInBoard + face == 100 && face == 6))
				moveBall(2, B2, face);
			else
				switchPlayer();
		else
			switchPlayer();

	}
}

void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew projSnakesAndLadders::frmMain);
}
