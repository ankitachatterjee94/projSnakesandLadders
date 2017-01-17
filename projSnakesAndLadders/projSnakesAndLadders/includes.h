//main include file
//contains all class definitons, namespace and enum declarations
#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace std;

//stores data related to a single ball
class Ball {
public:
	Point position;
	int noInBoard;

	Ball() {
		init();
	}
	
	Ball(Point position, int no) {
		this->position = position;
		noInBoard = no;
	}

	void init() {
		position = Point(21, 517);
		noInBoard = 1;
	}

	void setPos(Point position) {
		this->position = position;
	}

};

//stores ladder positions, performs search operations and returns end point of ladder
class Ladder {
	int arr[7][2];
	int a = 1;
public:
	static const int total = 7;

	Ladder() {
		arr[0][0] = 3; arr[0][1] = 21;
		arr[1][0] = 8; arr[1][1] = 30;
		arr[2][0] = 28; arr[2][1] = 84;
		arr[3][0] = 58; arr[3][1] = 77;
		arr[4][0] = 75; arr[4][1] = 86;
		arr[5][0] = 90; arr[5][1] = 91;
		arr[6][0] = 80; arr[6][1] = 99;
	}

	bool search(int position)
	{
		for (int i = 0; i < total; i++)
			if (arr[i][0] == position)
			{
				a = arr[i][1];
				return true;
			}
		return false;
	}

	int to() {
		return a;
	}

};

//stores snake positions, performs search operations and returns end point of snake
class Snake {
	int arr[7][2];
	int a = 1;
public:
	static const int total = 7;

	Snake() {
		arr[0][0] = 17; arr[0][1] = 13;
		arr[1][0] = 52; arr[1][1] = 29;
		arr[2][0] = 57; arr[2][1] = 40;
		arr[3][0] = 62; arr[3][1] = 22;
		arr[4][0] = 88; arr[4][1] = 18;
		arr[5][0] = 95; arr[5][1] = 51;
		arr[6][0] = 97; arr[6][1] = 79;
	}

	bool search(int position)
	{
		for (int i = 0; i < total; i++)
			if (arr[i][0] == position)
			{
				a = arr[i][1];
				return true;
			}
		return false;
	}

	int to() {
		return a;
	}
};

//class to store refernce to main UI
//we need to use a generic class as the namespace containing the GUI has not been created yet
template<class V>
public ref class UI {
	static V^ ref;
public:
	static void set(V^ a) {
		ref = a;
	}
	static V^ get() {
		return ref;
	}
};

//namespace for ball movement
namespace moveBallSetup {
	Point current, from, to;
	int ballNo;
	int speed = 1;
	bool completed = true;
}

//namespace for keeping count of moves, snakes, ladders etc.
namespace scores {
	int bonus1, bonus2;
	int ladder1, ladder2;
	int snake1, snake2;
	int moves1, moves2;
}

//namespace for dice movement
namespace moveDice {
	bool running = false;
	long int count = 0;
	long int max = 25;
	int face;
}

//enum to store cuurent player information
enum Player { PLAYER_1, PLAYER_2 };