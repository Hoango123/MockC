#include "Inifile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>	
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

bool Inifile::is_file_exist(const char* fileName)
{
	std::ifstream infile(fileName);
	return infile.good();
}

void Inifile::createRecordFile()
{
	ofstream fout;
	fout.open(recordfile, ios::out | ios::app);
	fout << "  Account    Win    Lose    Draw    WinRate\n";
	fout.close();
}
void Inifile::writePlayerInFile(Player123* player)
{
	if (!is_file_exist(recordfile)) { createRecordFile(); }	
	ofstream fout;
	fout.open(recordfile, ios::out | ios::app);
	fout << setw(8) << player->GetName();
	fout << setw(8) << player->GetWin();
	fout << setw(8) << player->GetLose();
	fout << setw(8) << player->GetDraw();
	fout << setw(8) << player->GetWinRate();
	fout << '\n';
	fout.close();
}

void Inifile::showAllRecordInFile()
{
	if (!is_file_exist(recordfile)) { createRecordFile(); }
	ifstream fin;
	fin.open(recordfile);
	char charsInLine[200];
	int count = 0;
	while (!fin.eof()) {
		fin.getline(charsInLine, 200);
		cout << charsInLine << endl;
	}
	fin.close();
}

bool Inifile::checkPlayerName(Player123* player)
{
	if (!is_file_exist(recordfile)) { createRecordFile(); }
	ifstream fin;
	fin.open(recordfile);
	string namePlayer;
	string charsInLine;
	while (!fin.eof())
	{
		getline(fin, charsInLine);
		fin >> namePlayer;
		if (namePlayer == player->GetName())
		{
			return true;
		}
	}
	fin.close();
	return false;
}

void Inifile::searchPlayerByName(string name)
{
	if (!is_file_exist(recordfile)) { createRecordFile(); }
	string namePlayer;
	int numWin, numLose, numDraw;
	ifstream fin;
	fin.open(recordfile);
	string charsInLine;
	while (!fin.eof())
	{
		getline(fin, charsInLine);
		fin >> namePlayer >> numWin >> numLose >> numDraw;
		if (namePlayer == name)
		{
			cout << "Player's Information\n";
			cout << "Name: " << namePlayer << endl;
			cout << "Number of Wins: " << numWin << endl;
			cout << "Number of Losses: " << numLose << endl;
			cout << "Number of Draws: " << numDraw << endl;
			findPlayerSameRank(namePlayer, numWin, numLose);
			return;
		}
	}
	fin.close();
	cout << "Don't find any player name: " << name << endl;
}

void Inifile::findPlayerSameRank(string name, int win, int lose)
{
	if (!is_file_exist(recordfile)) { createRecordFile(); }
	string namePlayer;
	string temp; // bien tranh ghi lai mot ten nhieu lan
	int numWin, numLose, numDraw;
	ifstream fin;
	fin.open(recordfile);
	string charsInLine;
	while (!fin.eof())
	{
		getline(fin, charsInLine);
		fin >> namePlayer >> numWin >> numLose >> numDraw;
		if ((namePlayer != name) && (numWin == win) && (numLose - lose >= -1) && (numLose - lose <= 1))
		{
			if (temp == namePlayer) return;
			cout << "Player Same Rank\n";
			cout << "Name: " << namePlayer << endl;
			cout << "Number of Wins: " << numWin << endl;
			cout << "Number of Losses: " << numLose << endl;
			cout << "Number of Draws: " << numDraw << endl;
			temp = namePlayer;
		}
	}
	fin.close();
}

void Inifile::eraseOldResult(string name)
{
	if (!is_file_exist(recordfile)) { createRecordFile(); }
	string line;
	ifstream myfile;
	myfile.open(recordfile);
	ofstream temp;
	temp.open("temp.ini");
	while (getline(myfile, line))
	{
		if (line.substr(8 - name.size(), name.size()) != name)
			temp << line << endl;
	}
	myfile.close();
	temp.close();
	remove(recordfile);
	rename("temp.ini", recordfile);
}

Inifile::Inifile()
{
}

Inifile::~Inifile()
{
}
