#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
bool IsError = false;
bool IsCursorSmall = false;
bool IsCursorBig = false;
char RotateDir;
int CursorSmallX = 0, CursorSmallY = 0;
int CursorBigX = 0, CursorBigY = 0;
void IsDraw(int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD, bool &Draw);
void IsWin(bool &Win, bool &Draw, int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD, string O, string X);
void DedicateTurn(int &CursorSmallX, int &CursorSmallY, int ** TableRU, int ** TableLU, int ** TableRD, int ** TableLD, int Turn);
void DrawTable(string ** TableDraw, int &CursorSmallX, int &CursorSmallY, bool &IsCursorSmall, int &CursorBigX, int &CursorBigY, bool &IsCursorBig);
void Draw‌B‌ead(string ** TableDraw, int ** TableRU, int ** TableLU, int ** TableRD, int ** TableLD);
void PrintTable(string ** TableDraw, int Turn, string X, string O, bool Win, bool Draw);
void Swip(int ** TableName, char Move);
void PlaceBead(int &CursorSmallX, int &CursorSmallY,int &CursorBigX, int &CursorBigY,bool &IsCursorSmall,bool &IsCursorBig, bool &IsError, string ** TableDraw, int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD, int Turn, string X, string O, bool Win, double TimeO,  double TimeX, bool Draw, int TimeMax);
void Cursor(int &CursorSmallX, int &CursorSmallY,int &CursorBigX, int &CursorBigY,bool &IsCursorSmall,bool &IsCursorBig, bool &IsError, string ** TableDraw, int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD, int &Turn, string X, string O, bool Win, double TimeO,  double TimeX, bool Draw, int TimeMax, char mode, int &ToDo)
{
    if(IsCursorSmall)
    {
        char Action = getch();
        system("cls");
        switch (Action) 
        {
            case 'w' :
            {
                (CursorSmallY > 0) ? --CursorSmallY : IsError = true;
                break;
            } 
            case 's' :
            {
                (CursorSmallY < 5) ? ++CursorSmallY : IsError = true;
                break;
            }
            case 'a' :
            {
                (CursorSmallX > 0) ? --CursorSmallX : IsError = true;
                break;
            }
            case 'd' :
            {
                (CursorSmallX < 5) ? ++CursorSmallX : IsError = true;
                break;
            }
            case 'u' :
            {
                
                if(mode == 'u')
                {
                    IsCursorSmall = false;
                    ToDo = 1;
                    Turn--;
                    
                }
                break;
            }
            case '\r' :
            {
                if(CursorSmallX < 3 && CursorSmallY < 3 && TableLU[CursorSmallX][CursorSmallY] == -1)
                {
                    PlaceBead(CursorSmallX, CursorSmallY, CursorBigX, CursorBigY, IsCursorSmall, IsCursorBig, IsError, TableDraw, TableRU, TableLU, TableLD, TableRD, Turn, X, O, Win, TimeO, TimeX, Draw, TimeMax);   
                }
                else if(CursorSmallX >= 3 && CursorSmallY < 3 && TableRU[CursorSmallX - 3][CursorSmallY] == -1)
                {
                    PlaceBead(CursorSmallX, CursorSmallY, CursorBigX, CursorBigY, IsCursorSmall, IsCursorBig, IsError, TableDraw, TableRU, TableLU, TableLD, TableRD, Turn, X, O, Win, TimeO, TimeX, Draw, TimeMax); 
                }
                else if(CursorSmallX < 3 && CursorSmallY >= 3 && TableLD[CursorSmallX][CursorSmallY - 3] == -1)
                {
                    PlaceBead(CursorSmallX, CursorSmallY, CursorBigX, CursorBigY, IsCursorSmall, IsCursorBig, IsError, TableDraw, TableRU, TableLU, TableLD, TableRD, Turn, X, O, Win, TimeO, TimeX, Draw, TimeMax); 
                }
                else if(CursorSmallX >= 3 && CursorSmallY >= 3 && TableRD[CursorSmallX - 3][CursorSmallY - 3] == -1)
                {
                    PlaceBead(CursorSmallX, CursorSmallY, CursorBigX, CursorBigY, IsCursorSmall, IsCursorBig, IsError, TableDraw, TableRU, TableLU, TableLD, TableRD, Turn, X, O, Win, TimeO, TimeX, Draw, TimeMax); 
                }
                else
                {
                    cout << "Oops this place is already taken!\n";  
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
                    system("cls");
                    return;
                }
            }
        }
    }
    if(IsCursorBig)
    {
        char Action = getch();
        
        system("cls");
        switch (Action) 
        {
            case 'w' :
            {
                (CursorBigY > 0) ?  --CursorBigY : IsError = true;
                break;
            } 
            case 's' :
            {
                (CursorBigY < 1) ? ++CursorBigY : IsError = true;
                break;
            }
            case 'a' :
            {
                (CursorBigX > 0) ? --CursorBigX : IsError = true;
                break;
            }
            case 'd' :
            {
                (CursorBigX < 1) ? ++CursorBigX : IsError = true;
                break;
            }
            // case 'u' :
            // {
            //     if(mode == 'u')
            //     {
            //         IsCursorSmall = true;
            //         IsCursorBig = false;
            //         ToDo = 1;     
            //     }
            //     break;  
            // }
            case 'l' :
            {
                if(CursorBigX == 0 && CursorBigY == 0)
                {
                    Swip(TableLU, 'l');
                }
                else if(CursorBigX == 0 && CursorBigY == 1)
                {
                    Swip(TableLD, 'l');
                }
                else if(CursorBigX == 1 && CursorBigY == 0)
                {
                    Swip(TableRU, 'l');
                }
                else if(CursorBigX == 1 && CursorBigY == 1)
                {
                    Swip(TableRD, 'l');
                }
                IsCursorSmall = false;
                IsCursorBig = false;
                break;
            }
            case 'r' :
            {
                if(CursorBigX == 0 && CursorBigY == 0)
                {
                    Swip(TableLU, 'r');
                }
                else if(CursorBigX == 0 && CursorBigY == 1)
                {
                    Swip(TableLD, 'r');
                }
                else if(CursorBigX == 1 && CursorBigY == 0)
                {
                    Swip(TableRU, 'r');
                }
                else if(CursorBigX == 1 && CursorBigY == 1)
                {
                    Swip(TableRD, 'r');
                }
                IsCursorSmall = false;
                IsCursorBig = false;
                break;
            }
        }
    }
    return;
}
void PlaceBead(int &CursorSmallX, int &CursorSmallY,int &CursorBigX, int &CursorBigY,bool &IsCursorSmall,bool &IsCursorBig, bool &IsError, string ** TableDraw, int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD, int Turn, string X, string O, bool Win, double TimeO,  double TimeX, bool Draw, int TimeMax)
{
    IsCursorSmall = false;
    IsCursorBig = true;
    
    DedicateTurn(CursorSmallX, CursorSmallY, TableRU, TableLU, TableRD, TableLD, Turn);  
    if(!Win && !Draw)
    {
        IsWin(Win, Draw, TableRU, TableLU, TableLD, TableRD, O, X);
        IsDraw(TableRU, TableLU, TableLD, TableRD, Draw);
    } 
    
    if(Win || Draw)
    {
        IsCursorSmall = false;
        IsCursorBig = false;
        return;
    }
    DrawTable(TableDraw, CursorSmallX, CursorSmallY, IsCursorSmall, CursorBigX, CursorBigY, IsCursorBig);
    Draw‌B‌ead(TableDraw, TableRU, TableLU, TableRD, TableLD);
    PrintTable(TableDraw, Turn, X, O, Win, Draw);
    
    if(TimeMax != 0)
    {
        cout << setw(10) << left << O << "\'s time left: " << setw(2) << left << int(TimeMax - TimeO)/60 << " minutes, " << setw(2) << left << int(TimeMax - TimeO)%60  << " seconds" << "\n" 
            << setw(10) << left << X << "\'s time left: " << setw(2) << left << int(TimeMax - TimeX)/60 << " minutes, " << setw(2) << left << int(TimeMax - TimeX)%60  << " seconds" << "\n"
            << "(Press any botton to refresh times)";
    }
    return;
}