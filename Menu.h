#include <iostream>
#include <windows.h>

using namespace std;
void Ranking();
int StartGameMenu(string ** TableDraw,int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD);
int ClassicGame(string ** TableDraw,int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD);
void Undo(int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD, int ** TableRUTemp, int ** TableLUTemp, int ** TableLDTemp, int ** TableRDTemp, int ToDo);
int UndoGame(string ** TableDraw,int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD);
int MainMenu(string ** TableDraw,int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD)
{
    system("cls");
    cout << "Main menu:\n1- Start game\n2- Ranking\n3- Exit\n";
    while(true)
    {
        char DoWhat = getch();
        switch(DoWhat)
        {
            case '1':
            {
                return StartGameMenu(TableDraw, TableRU, TableLU, TableLD, TableRD);
                break;
            }
            case '2':
            {
                system("cls");
                cout << "Preparing ranking...";
                Sleep(1000);
                system("cls");
                cout << "Ranking:(Top 10)\n\n";
                Ranking();
                cout << "(Enter or ESC to go back)";
                while(true)
                {
                    char DoWhat = getch();
                    if(DoWhat == char(27) || DoWhat == '\r')
                    {
                        return MainMenu(TableDraw, TableRU, TableLU, TableLD, TableRD);
                    }
                }
                return 0;
                break;
            }
            case '3':
            {
                system("cls");
                cout << "Closing the program!";
                Sleep(2000);
                system("cls");
                cout << ":((((((";
                exit(0);
                return 0;
                break;
            }
        }
    }
    return 0;
}
int StartGameMenu(string ** TableDraw,int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD)
{
    system("cls");
    cout << "Start game menu:\n1- Classic (15 minutes for each person and without Undo): \n2- Undo free!(unranked and time free)\n(Press ESC to get back)\n";
    while(true)
    {
        char DoWhatStartGame = getch();
        switch(DoWhatStartGame)
        {
            case '1':
            {
                return ClassicGame(TableDraw, TableRU, TableLU, TableLD, TableRD);
                break;
            }
            case '2':
            {
                return UndoGame(TableDraw, TableRU, TableLU, TableLD, TableRD);
                break;
            }
            case char(27):
            {
                system("cls");
                cout << "Geting back!";
                Sleep(1000);
                return MainMenu(TableDraw, TableRU, TableLU, TableLD, TableRD);
                break;
            }         
        }
    }
    return 0;
}