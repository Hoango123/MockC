#include "Caro.h"
#include "Player123.h"

using namespace std;


void Caro::drawBoard()
{
	//tao o trong de dien X O
	for (int i = 0; i < GAMEPADHIGHT; i++)
	{
		for (int j = 0; j < GAMEPADWEIGHT; j++)
		{
			gamePad[i][j] = ' ';
		}
	}
}

void Caro::printBoard()
{
	cout << "  ";
	for (int i = 0; i < 10; i++)
	{
		cout << "| " << i << ' ';
	}
	cout << '|' << endl;
	cout << "-------------------------------------------" << endl;
	for (int i = 0; i < GAMEPADHIGHT; i++)
	{
		cout << i << ' ';
		for (int j = 0; j < GAMEPADWEIGHT; j++)
		{
			cout << "|" << " " << gamePad[i][j] << " ";
		}
		cout << "|" << endl;
		cout << "-------------------------------------------" << endl;
	}
}

void Caro::inputX()
{
	int x, y;
	do
	{
		cout << "Player 1 turn: ";
		cin >> x >> y;
		cin.ignore();
	} while (((0 > x) || (GAMEPADHIGHT - 1 < x)) || ((0 > y) || (GAMEPADWEIGHT - 1 < y)));
	for (int i = 0; i < Data.size(); i++)
	{
		if (Data[i]->x == x && Data[i]->y == y)
		{
			cout << "Diem danh khong hop le";
			return;
		}
	}
	Block* b = new Block();
	b->x = x;
	b->y = y;
	Data.push_back(b);
	for (int i = 0; i < GAMEPADHIGHT; i++)
	{
		for (int j = 0; j < GAMEPADWEIGHT; j++)
		{
			if (b->x == i && b->y == j)
			{
				gamePad[i][j] = 'X';
			}
		}
	}
}

void Caro::inputO()
{
	int x, y;
	do
	{
		cout << "Player 2 turn: ";
		cin >> x >> y;
		cin.ignore();
	} while (((0 > x) || (GAMEPADHIGHT - 1 < x)) || ((0 > y) || (GAMEPADWEIGHT - 1 < y)));
	for (int i = 0; i < Data.size(); i++)
	{
		if (Data[i]->x == x && Data[i]->y == y)
		{
			cout << "Diem danh khong hop le";
			return;
		}
	}
	Block* b = new Block();
	b->x = x;
	b->y = y;
	Data.push_back(b);
	for (int i = 0; i < GAMEPADHIGHT; i++)
	{
		for (int j = 0; j < GAMEPADWEIGHT; j++)
		{
			if (b->x == i && b->y == j)
			{
				gamePad[i][j] = 'O';
			}
		}
	}
}

void Caro::playerInput(vector<Block*> Data)
{
	if (Data.size() == 0)
	{
		inputX();
	}
	else if ((Data.size() - 1) % 2 == 0)
	{
		inputO();
	}
	else if ((Data.size() - 1) % 2 != 0)
	{
		inputX();
	}
	system("cls");
}

bool Caro::checkWin()
{
	for (int i = 0; i < GAMEPADHIGHT; i++)
	{
		for (int j = 0; j < GAMEPADWEIGHT; j++)
		{
			//Ngang
			if (gamePad[i][j] != ' ' && gamePad[i][j] == gamePad[i][j + 1] && gamePad[i][j] == gamePad[i][j + 2] && gamePad[i][j] == gamePad[i][j + 3])
			{
				return true;
			}
			//Doc
			else if (gamePad[i][j] != ' ' && gamePad[i][j] == gamePad[i + 1][j] && gamePad[i][j] == gamePad[i + 2][j] && gamePad[i][j] == gamePad[i + 3][j])
			{
				return true;
			}
			//cheo huyen
			else if (gamePad[i][j] != ' ' && gamePad[i][j] == gamePad[i + 1][j + 1] && gamePad[i][j] == gamePad[i + 2][j + 2] && gamePad[i][j] == gamePad[i + 3][j + 3])
			{
				return true;
			}
			//cheo sac
			else if (gamePad[i][j] != ' ' && gamePad[i][j] == gamePad[i - 1][j + 1] && gamePad[i][j] == gamePad[i - 2][j + 2] && gamePad[i][j] == gamePad[i - 3][j + 3])
			{
				return true;
			}
		}

	}
	return false;
}

bool Caro::checkDraw()
{
	if (Data.size() == (GAMEPADHIGHT * GAMEPADWEIGHT)) return true;
	return false;
}

Caro::Caro()
{
}

Caro::~Caro()
{
}
