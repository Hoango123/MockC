#pragma once
#include "Player123.h"

static const char* recordfile = "PlayerRecord.ini";

class Inifile
{
public:
	static bool is_file_exist(const char* fileName);

	static void createRecordFile();
	void writePlayerInFile(Player123* player);
	static void showAllRecordInFile();
	static bool checkPlayerName(Player123* player);
	static void searchPlayerByName(string name);
	static void findPlayerSameRank(string name, int win, int lose);
	static void eraseOldResult(string name);
	Inifile();
	~Inifile();
};

