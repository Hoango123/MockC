#pragma once
#include <Windows.h>
#include <cstdlib>	
#include <iostream>
#include <vector>

#define GAMEPADHIGHT 10
#define GAMEPADWEIGHT 10	
#define GAMEWONCONDITION 4

using namespace std;

class Caro
{
public:
	char player1[15];
	char player2[15];

	struct Block
	{
		int x;
		int y;
	};

	char gamePad[GAMEPADHIGHT][GAMEPADWEIGHT];
	vector <Block*> Data;

	void drawBoard();
	void printBoard();
	void inputX();
	void inputO();
	void playerInput(vector<Block*> Data);
	bool checkWin();
	bool checkDraw();
	Caro();
	~Caro();
};

