
// Pentago game Project 
//BY:
// Aria   Hasanali 
// Sepehr Mousaviyan

// include header files
#include <iostream>
#include <chrono>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string>

#include "Loading.h"
#include "Menu.h"
#include "MakeTableMines.h"
#include "DrawTable.h"
#include "Cursor.h"
#include "DedicateTurn.h"
#include "Win.h"
#include "Swip.h"
#include "Time.h"
#include "Player.h"

// set main namespace 
using namespace std;

int ClassicGame(string ** TableDraw,int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD);
void MakeTableZero(int ** TableName);
int UndoGame(string ** TableDraw,int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD);
void Undo(int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD, int ** TableRUTemp, int ** TableLUTemp, int ** TableLDTemp, int ** TableRDTemp, int ToDo);
void MakePlaceFree(int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD, int CursorSmallX, int CursorSmallY);

bool Win = false;
bool Draw = false;
int main()
{

    // // making tables
    
    // //      TableLU | TableRU
    // //      ________|_________
    // //              |
    // //      TableLD | TableRD

    string ** TableDraw = new string * [26];
    for (int Row=0 ; Row < 26 ; ++Row)
    {
        TableDraw[Row] = new string [14];
    }

    int ** TableRU = new int * [3];
    for (int Row=0 ; Row<3 ; ++Row)
        TableRU[Row] = new int [3];
    MakeTableZero(TableRU);

    int ** TableLU = new int * [3];
    for (int Row=0 ; Row < 3 ; ++Row)
        TableLU[Row] = new int [3];
    MakeTableZero(TableLU);

    int ** TableRD = new int * [3];
    for (int Row=0 ; Row < 3 ; ++Row)
        TableRD[Row] = new int [3];
    MakeTableZero(TableRD);

    int ** TableLD = new int * [3];
    for (int Row=0 ; Row<3 ; ++Row)
        TableLD[Row] = new int [3];
    MakeTableZero(TableLD);
    ////////////////////////////////////////////////////////////////////////
    
    Loading();
    system("cls");
    MainMenu(TableDraw, TableRU, TableLU, TableLD, TableRD);
    return 0;
}
int ClassicGame(string ** TableDraw,int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD)
{
    int ToDo = 2;
    int TimeMax = 15 * 60;
    double TimeO = 0;
    double TimeX = 0;
    string X, O, NowPlayingName;
    system("cls");
    cout << "Classic game:\nEnter first Players name(As O): ";
    cin >> O;
    cout << "Enter second Players name(As X): ";
    cin >> X;
    // Player X, O;
    int Turn = 0;
    IsCursorSmall = true;
    while(!Win && !Draw)
    {
        system("cls");
        while(IsCursorSmall)
        {
            auto start = chrono::steady_clock::now();  
            DrawTable(TableDraw, CursorSmallX, CursorSmallY, IsCursorSmall, CursorBigX, CursorBigY, IsCursorBig);
            Draw‌B‌ead(TableDraw, TableRU, TableLU, TableRD, TableLD);
            PrintTable(TableDraw, Turn, X, O, Win, Draw);
            cout << setw(10) << left << O << "\'s time left: " << setw(2) << left << int(TimeMax - TimeO)/60 << " minutes, " << setw(2) << left << int(TimeMax - TimeO)%60  << " seconds" << "\n" 
                 << setw(10) << left << X << "\'s time left: " << setw(2) << left << int(TimeMax - TimeX)/60 << " minutes, " << setw(2) << left << int(TimeMax - TimeX)%60  << " seconds" << "\n"
                 << "(Press any botton to refresh times)";
            Cursor(CursorSmallX, CursorSmallY, CursorBigX, CursorBigY, IsCursorSmall, IsCursorBig, IsError, TableDraw, TableRU, TableLU, TableLD, TableRD, Turn, X, O, Win, TimeO, TimeX, Draw, TimeMax, 's', ToDo);
        
            auto end = chrono::steady_clock::now();
            chrono::duration<double> Duration = end-start;
            Turn % 2 == 0 ? TimeO += Duration.count() : TimeX += Duration.count();
            if(int(TimeMax - TimeO) <= 0)
            {
                Win = true;
                cout << X << " won!\n";
                IsCursorSmall = false;
                IsCursorBig = false;
                break;
            }
            else if(int(TimeMax - TimeX) <= 0)
            {
                Win = true;
                cout << O << " won!\n";
                IsCursorSmall = false;
                IsCursorBig = false;
                break;
            }
        }
        if(!Win && !Draw)
        {
            IsWin(Win, Draw, TableRU, TableLU, TableLD, TableRD, O, X);
            IsDraw(TableRU, TableLU, TableLD, TableRD, Draw);
        }
        if(Win || Draw)
        {
            IsCursorSmall = false;
            IsCursorBig = false;
            DrawTable(TableDraw, CursorSmallX, CursorSmallY, IsCursorSmall, CursorBigX, CursorBigY, IsCursorBig);
            Draw‌B‌ead(TableDraw, TableRU, TableLU, TableRD, TableLD);
            PrintTable(TableDraw, Turn, X, O, Win, Draw);
            break;
        }
        while(IsCursorBig)
        {
            // system("cls");
            // cout << O << "\'s time left:  " << TimeO << "\n" << X << "\'s time left: " << TimeX << "\n";
            auto start = std::chrono::steady_clock::now(); 
            DrawTable(TableDraw, CursorSmallX, CursorSmallY, IsCursorSmall, CursorBigX, CursorBigY, IsCursorBig);
            Draw‌B‌ead(TableDraw, TableRU, TableLU, TableRD, TableLD);
            PrintTable(TableDraw, Turn, X, O, Win, Draw);
            cout << setw(10) << left << O << "\'s time left: " << setw(2) << left << int(TimeMax - TimeO)/60 << " minutes, " << setw(2) << left << int(TimeMax - TimeO)%60  << " seconds" << "\n" 
                 << setw(10) << left << X << "\'s time left: " << setw(2) << left << int(TimeMax - TimeX)/60 << " minutes, " << setw(2) << left << int(TimeMax - TimeX)%60  << " seconds" << "\n"
                 << "(Press any botton to refresh times)";
            Cursor(CursorSmallX, CursorSmallY, CursorBigX, CursorBigY, IsCursorSmall, IsCursorBig, IsError, TableDraw, TableRU, TableLU, TableLD, TableRD, Turn, X, O, Win, TimeO, TimeX, Draw, TimeMax, 's', ToDo);
            
            auto end = chrono::steady_clock::now();
            chrono::duration<double> Duration = end - start;
            Turn % 2 == 0 ? TimeO += Duration.count() : TimeX += Duration.count();
            if(int(TimeMax - TimeO) <= 0)
            {
                Win = true;
                cout << X << " won!\n";
                IsCursorSmall = false;
                IsCursorBig = false;
                break;
            }
            else if(int(TimeMax - TimeX) <= 0)
            {
                Win = true;
                cout << O << " won!\n";
                IsCursorSmall = false;
                IsCursorBig = false;
                break;
            }
        }
        IsCursorSmall = true;
        

        if(!Win && !Draw)
        {
            IsWin(Win, Draw, TableRU, TableLU, TableLD, TableRD, O, X);
            IsDraw(TableRU, TableLU, TableLD, TableRD, Draw);
        }
        if(Win || Draw)
        {
            IsCursorSmall = false;
            IsCursorBig = false;
            DrawTable(TableDraw, CursorSmallX, CursorSmallY, IsCursorSmall, CursorBigX, CursorBigY, IsCursorBig);
            Draw‌B‌ead(TableDraw, TableRU, TableLU, TableRD, TableLD);
            PrintTable(TableDraw, Turn, X, O, Win, Draw);
            break;
        }
        DrawTable(TableDraw, CursorSmallX, CursorSmallY, IsCursorSmall, CursorBigX, CursorBigY, IsCursorBig);
        Draw‌B‌ead(TableDraw, TableRU, TableLU, TableRD, TableLD);
        PrintTable(TableDraw, Turn, X, O, Win, Draw);
        CursorSmallX = CursorSmallY = 0;
        CursorBigX = CursorBigY = 0;
        Turn++;
        
    }
    AddGame(O, X, Win, Draw, Turn);
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
}

int UndoGame(string ** TableDraw,int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD)
{
    int ToDo = 0;
    int CursorSmallXTemp = 0;
    int CursorSmallYTemp = 0;
    int ** TableRUTemp = new int * [3];
    for (int Row=0 ; Row<3 ; ++Row)
        TableRUTemp[Row] = new int [3];
    MakeTableZero(TableRUTemp);

    int ** TableLUTemp = new int * [3];
    for (int Row=0 ; Row < 3 ; ++Row)
        TableLUTemp[Row] = new int [3];
    MakeTableZero(TableLUTemp);

    int ** TableRDTemp = new int * [3];
    for (int Row=0 ; Row < 3 ; ++Row)
        TableRDTemp[Row] = new int [3];
    MakeTableZero(TableRDTemp);

    int ** TableLDTemp = new int * [3];
    for (int Row=0 ; Row<3 ; ++Row)
        TableLDTemp[Row] = new int [3];
    MakeTableZero(TableLDTemp);

    int TimeMax = 0;
    string X, O, NowPlayingName;
    system("cls");
    cout << "ٔNot a classic game:(you can press U to undo whenever you want)\nEnter first Players name(As O): ";
    cin >> O;
    cout << "Enter second Players name(As X): ";
    cin >> X;
    // Player X, O;
    int Turn = 0;
    IsCursorSmall = true;
    while(!Win && !Draw)
    {
        system("cls");
        while(IsCursorSmall)
        { 
            DrawTable(TableDraw, CursorSmallX, CursorSmallY, IsCursorSmall, CursorBigX, CursorBigY, IsCursorBig);
            Draw‌B‌ead(TableDraw, TableRU, TableLU, TableRD, TableLD);
            PrintTable(TableDraw, Turn, X, O, Win, Draw);
            if(Turn != 0)
            {
                cout << "(Press U to undo, you can undo just 1 turn!)\n";
            }
            Cursor(CursorSmallX, CursorSmallY, CursorBigX, CursorBigY, IsCursorSmall, IsCursorBig, IsError, TableDraw, TableRU, TableLU, TableLD, TableRD, Turn, X, O, Win, 0, 0, Draw, TimeMax, 'u', ToDo);  
                     
        }
        if(ToDo == 0)
        {
            CursorSmallXTemp = CursorSmallX;
            CursorSmallYTemp = CursorSmallY;
        } 
        Undo(TableRU, TableLU, TableLD, TableRD, TableRUTemp, TableLUTemp, TableLDTemp, TableRDTemp, ToDo);
        if(ToDo == 1)
        {
            MakePlaceFree(TableRU, TableLU, TableLD, TableRD, CursorSmallXTemp, CursorSmallYTemp);
            ToDo = 0;
            DrawTable(TableDraw, CursorSmallX, CursorSmallY, IsCursorSmall, CursorBigX, CursorBigY, IsCursorBig);
            Draw‌B‌ead(TableDraw, TableRU, TableLU, TableRD, TableLD);
            PrintTable(TableDraw, Turn, X, O, Win, Draw);
            cout << "Undo done!\n";
            Sleep(1000);
            IsCursorSmall = true;
            continue;
        }
        
        if(!Win && !Draw)
        {
            IsWin(Win, Draw, TableRU, TableLU, TableLD, TableRD, O, X);
            IsDraw(TableRU, TableLU, TableLD, TableRD, Draw);
        }
        if(Win || Draw)
        {
            IsCursorSmall = false;
            IsCursorBig = false;
            DrawTable(TableDraw, CursorSmallX, CursorSmallY, IsCursorSmall, CursorBigX, CursorBigY, IsCursorBig);
            Draw‌B‌ead(TableDraw, TableRU, TableLU, TableRD, TableLD);
            PrintTable(TableDraw, Turn, X, O, Win, Draw);
            break;
        }
        while(IsCursorBig)
        {
            // system("cls");
            // cout << O << "\'s time left:  " << TimeO << "\n" << X << "\'s time left: " << TimeX << "\n";
            DrawTable(TableDraw, CursorSmallX, CursorSmallY, IsCursorSmall, CursorBigX, CursorBigY, IsCursorBig);
            Draw‌B‌ead(TableDraw, TableRU, TableLU, TableRD, TableLD);
            PrintTable(TableDraw, Turn, X, O, Win, Draw);
            
            Cursor(CursorSmallX, CursorSmallY, CursorBigX, CursorBigY, IsCursorSmall, IsCursorBig, IsError, TableDraw, TableRU, TableLU, TableLD, TableRD, Turn, X, O, Win, 0, 0, Draw, TimeMax, 'u', ToDo);
            
        }
        IsCursorSmall = true;
        // Undo(TableRU, TableLU, TableLD, TableRD, TableRUTemp, TableLUTemp, TableLDTemp, TableRDTemp, ToDo);
        // if(ToDo == 1)
        // {
        //     MakePlaceFree(TableRU, TableLU, TableLD, TableRD, CursorSmallX, CursorSmallY);
        //     ToDo = 0;
        //     DrawTable(TableDraw, CursorSmallX, CursorSmallY, IsCursorSmall, CursorBigX, CursorBigY, IsCursorBig);
        //     Draw‌B‌ead(TableDraw, TableRU, TableLU, TableRD, TableLD);
        //     PrintTable(TableDraw, Turn, X, O, Win, Draw);
        //     cout << "Undo done!\n";
        //     Sleep(1000);
        //     IsCursorSmall = true;
        //     IsCursorBig = false;
        //     Turn--;
        //     continue;
        // }
        // IsCursorSmall = true;
        

        if(!Win && !Draw)
        {
            IsWin(Win, Draw, TableRU, TableLU, TableLD, TableRD, O, X);
            IsDraw(TableRU, TableLU, TableLD, TableRD, Draw);
        }
        if(Win || Draw)
        {
            IsCursorSmall = false;
            IsCursorBig = false;
            DrawTable(TableDraw, CursorSmallX, CursorSmallY, IsCursorSmall, CursorBigX, CursorBigY, IsCursorBig);
            Draw‌B‌ead(TableDraw, TableRU, TableLU, TableRD, TableLD);
            PrintTable(TableDraw, Turn, X, O, Win, Draw);
            break;
        }
        DrawTable(TableDraw, CursorSmallX, CursorSmallY, IsCursorSmall, CursorBigX, CursorBigY, IsCursorBig);
        Draw‌B‌ead(TableDraw, TableRU, TableLU, TableRD, TableLD);
        PrintTable(TableDraw, Turn, X, O, Win, Draw);
        CursorSmallX = CursorSmallY = 0;
        CursorBigX = CursorBigY = 0;
        Turn++;
        
    }
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
}
void Undo(int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD, int ** TableRUTemp, int ** TableLUTemp, int ** TableLDTemp, int ** TableRDTemp, int ToDo)
{
    for(int j = 0; j < 3 ; j++)
    {
        for(int i = 0; i < 3 ; i++)
        {
            if(ToDo == 0)
            {
                TableRUTemp[i][j] = TableRU[i][j];
                TableLUTemp[i][j] = TableLU[i][j];
                TableLDTemp[i][j] = TableLD[i][j];
                TableRDTemp[i][j] = TableRD[i][j];
            }
            else if(ToDo == 1)
            {
                TableRU[i][j] = TableRUTemp[i][j];
                TableLU[i][j] = TableLUTemp[i][j];
                TableLD[i][j] = TableLDTemp[i][j];
                TableRD[i][j] = TableRDTemp[i][j];
            }
        }
    }
    return;
}
void MakePlaceFree(int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD, int CursorSmallX, int CursorSmallY)
{
    if(CursorSmallX < 3 && CursorSmallY < 3)
    {
        TableLU[CursorSmallX][CursorSmallY] = -1;
    }
    else if(CursorSmallX >= 3 && CursorSmallY < 3)
    {
        TableRU[CursorSmallX - 3][CursorSmallY] = -1;
    }
    else if(CursorSmallX < 3 && CursorSmallY >= 3)
    {
        TableLD[CursorSmallX][CursorSmallY - 3] = -1;
    }
    else if(CursorSmallX >= 3 && CursorSmallY >= 3)
    {
        TableRD[CursorSmallX - 3][CursorSmallY - 3] = -1;
    }
    return;
}
