#include "Player123.h"

string Player123::GetName()
{
	return name;
}

void Player123::SetName(string value)
{
	name = value;
}

void Player123::SetWin(int value)
{
	win = value;
}

void Player123::SetLose(int value)
{
	lose = value;
}

void Player123::SetDraw(int value)
{
	draw = value;
}

void Player123::SetMatch(int value)
{
	match = value;
}

int Player123::GetWin()
{
	return win;
}

int Player123::GetLose()
{
	return lose;
}

int Player123::GetDraw()
{
	return draw;
}

int Player123::GetWinRate()
{
	return ((double)(win) / (double)(win + draw + match)) * 100;
}

void Player123::IncreWin()
{
	win++;
}

void Player123::IncreLose()
{
	lose++;
}

void Player123::IncreDraw()
{
	draw++;
}

void Player123::IncreMatch()
{
	match++;
}

Player123::Player123()
{
}

Player123::~Player123()
{
}
