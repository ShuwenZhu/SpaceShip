// Name of Program: SpaceShip
// @author Shuwen Zhu
// @date May 5, 2021
// Windows 10 / Visual Studio 2019
// This program allows player choose a certain difficulty before start
// and creat random obstacle accordingly. Player needs to use "A" and 
// "D" key to dodge and earn score. The score earnd is displayed on the
// bottom of the game console.
// 
#include "game1.h"
#include <iostream>         /* cout */
#include <conio.h>          /* _kbhit, _getch*/

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);   //get current console
COORD CursorPosition;   //store cursor position

/* Point cursor to given position */
void gotoxy(int x, int y)
{
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

int main()
{
    int diff = 0;
    cout << "Welcome to space travelling!\n" 
            << "\"A\" - move left    \"D\" - move right"
            << "Please choose your prefered challange index:\n"
            << "(0 - 5) 0 - easiest, 5 - hardest\n"
            << ">>";
    cin >> diff;
    while (!cin || diff < 0 || diff >5) 
    {
        // user didn't input a number
        cout << "0 - 5 numbers only please! " << endl;
        cin.clear(); // reset failbit
        cin.ignore(1000, '\n'); //skip bad input
        // next, request user reinput
        cin >> diff;
    }
    Game g1;
    g1.setDifficulty(diff);
    system("cls");
    boolean start = true;       // game running controller 
    while (start)
    {
        /* determine if the game ends*/
        start = g1.run();
        /* fill console with space content */
        for (int i = WINDOW_HEIGHT - 1; i >= 0; i--)
        {
            for (int j = 0; j < WINDOW_WIDTH; j++)
            {
                gotoxy(j, i);
                cout << g1.getSpaceCord(j, i);
            }
        }
        /* keyboard input processing */
        if (_kbhit())
        {
            char ch = _getch();
            if (ch == 'a' || ch == 'A')
                g1.movePlayer(-1);
            else if (ch == 'd' || ch == 'D')
                g1.movePlayer(1);
        }
        /* display the player position to the console*/
        for (int i = 0; i < WINDOW_WIDTH; i++)
        {
            gotoxy(i, WINDOW_HEIGHT);
            cout << g1.getPlayerCord(i);
        }
        /* display result to the console*/
        gotoxy(WINDOW_WIDTH / 2, WINDOW_HEIGHT + 1);
        cout << "Your score: " << g1.getScore() << endl;

        /* refresh rate / game speed*/
        Sleep(300);
    }

    system("pause");
    return 0;
}