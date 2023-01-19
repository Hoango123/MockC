#pragma once
#include "Player123.h"
#include "Caro.h"

static const char* recordfile = "PlayerRecord.ini";
static const char* replayfile = "PlayerReplay.ini";

class Inifile
{
public:

	static bool is_file_exist(const char* fileName);

	//record
	static void createRecordFile();
	void writePlayerInFile(Player123* player);
	static void showAllRecordInFile();
	static bool checkPlayerName(Player123* player);
	static void searchPlayerByName(string name);
	static void findPlayerSameRank(string name, int win, int lose);
	static void eraseOldResult(string name);
	static void updatCurrentResult(Player123* player);


	//relay
	static void createReplayFile();
	static bool checkGameId(char id);
	static void saveReplayInFile(vector<Caro::Block*> Data);
	static void showAllReplayGameInFile();
	vector<Caro::Block*> getReplayMoveById(char id);
	static string getReplayPlayerById(char id, int user);
	Inifile();
	~Inifile();
};

