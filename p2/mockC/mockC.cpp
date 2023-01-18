// mockC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include "Caro.h"
#include "Inifile.h"
#include "Player123.h"

using namespace std;

int main()
{
    Caro* caro = new Caro();
    Inifile* ini = new Inifile();
    caro->drawBoard();
    int menu;
    Player123* play1 = new Player123();
    Player123* play2 = new Player123();
    while (1)
    {
        system("cls");

        cout << "1. Play Game: " << endl;
        cout << "2. History: " << endl;
        cout << "3. Exit" << endl;
        cout << "Select Item  >> ";
        cin >> menu;
        //play game
        if (menu == 1)
        {
            caro->Data.clear();
            system("cls");
            string player1 = "";
            string player2 = "";
            do
            {
                
                cout << "Input player 1 name: " << endl;
                cin >> player1;
                cin.ignore();
                if (ini->checkPlayerName(play1))
                {
                    ini->eraseOldResult(play1->GetName());
                    play1->SetName(player1);

                }
                play1->SetName(player1);
            } while (play1->GetName() == "");
            
            do
            {
                cout << "Input player 2 name: " << endl;
                cin >> player2;
                cin.ignore();
                if (ini->checkPlayerName(play2))
                {
                    ini->eraseOldResult(play2->GetName());
                    play2->SetName(player2);

                }
                play2->SetName(player2);
            } while (play2->GetName() == "");
            
            while (1)
            {
                caro->printBoard();
                caro->playerInput(caro->Data);
                if (caro->checkWin())
                {
                    int x = caro->Data.size() - 1;
                    if (x % 2 == 0)
                    {
                        caro->printBoard();
                        cout << "Player 1 win" << endl;
                        play1->IncreWin();
                        play1->IncreMatch();
                        play2->IncreMatch();
                        play2->IncreLose();
                        ini->writePlayerInFile(play1);
                        ini->writePlayerInFile(play2);
                        caro->drawBoard();
                        system("pause");
                        break;
                    }
                    else
                    {
                        caro->printBoard();
                        cout << "Player 2 win" << endl;
                        play2->IncreWin();
                        play2->IncreMatch();
                        play1->IncreMatch();
                        play1->IncreLose();
                        ini->writePlayerInFile(play1);
                        ini->writePlayerInFile(play2);
                        caro->drawBoard();
                        system("pause");
                        break;
                    }
                }
                if (caro->checkDraw())
                {
                    caro->printBoard();
                    cout << "Player 1 draw player 2";
                    play2->IncreDraw();
                    play2->IncreMatch();
                    play1->IncreMatch();
                    play1->IncreDraw();
                    ini->writePlayerInFile(play1);
                    ini->writePlayerInFile(play2);
                    caro->drawBoard();
                    system("pause");
                    break;
                }

            }

        }

    }
    return 0;
}

