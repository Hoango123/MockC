// mockC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Caro.h"

using namespace std;

int main()
{
    Caro* caro = new Caro();
    caro->drawBoard();
    while (1)
    {
        system("cls");
        caro->printBoard();
        caro->playerInput(caro->Data);
        if (caro->checkWin())
        {
            int x = caro->Data.size() - 1;
            if (x % 2 == 0)
            {
                caro->printBoard();
                cout << "Player 1 win" << endl;
                break;
            }
            else
            {
                caro->printBoard();
                cout << "Player 2 win" << endl;
                break;
            }
        }
        if (caro->checkDraw())
        {
            caro->printBoard();
            cout << "Player 1 draw player 2";
            break;
        }
    }
    return 0;
}

