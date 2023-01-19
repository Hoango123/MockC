
#ifndef PLAYER123_H
#define PLAYER123_H
#include <string>
using namespace std;
class Player123
{
private:
	string name = "";
	int win = 0;
	int lose = 0;
	int draw = 0;
	int match = 0;
public:
	string GetName();
	void SetName(string value);
	void SetWin(int value);
	void SetLose(int value);
	void SetDraw(int value);
	void SetMatch(int value);
	int GetWin();
	int GetLose();
	int GetDraw();
	int GetWinRate();
	void IncreWin();
	void IncreLose();
	void IncreDraw();
	void IncreMatch();
	Player123();
	~Player123();
};
#endif // PLAYER_H