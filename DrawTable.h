#include <iostream>
using namespace std;
char Convert(int ** Table, int x, int y);
void DrawBead(string ** TableDraw, int ** TableRU, int ** TableLU, int ** TableRD, int ** TableLD);
void DedicateTurn(int &CursorSmallX, int &CursorSmallY, int ** TableRU, int ** TableLU, int ** TableRD, int ** TableLD);
void DrawTable(string ** TableDraw, int &CursorSmallX, int &CursorSmallY, bool &IsCursorSmall, int &CursorBigX, int &CursorBigY, bool &IsCursorBig)
{   
    // string TableDraw[26][14];
    // Line 2&4&6 , 3&5 are the same
    
    for(int j = 0 ; j < 14 ; j++)
    {
        for(int i = 0 ; i < 26 ; i++)
        {
            int x = j;
            for(int c = 0 ; c < 2 ; c++)
            {
                int k = 0;
                c == 1 ? k = 13 : k = 0;
                if(x % 7 == 0)
                {
                    TableDraw[k + 0][j] = "\u250C";
                    TableDraw[k + 1][j] = TableDraw[k + 2][j] = TableDraw[k + 3][j] = "\u2500";
                    TableDraw[k + 4][j] = "\u252C";
                    TableDraw[k + 5][j] = TableDraw[k + 6][j] = TableDraw[k + 7][j] = "\u2500";
                    TableDraw[k + 8][j] = "\u252C";
                    TableDraw[k + 9][j] = TableDraw[k + 10][j] = TableDraw[k + 11][j] = "\u2500";
                    TableDraw[k + 12][j] = "\u2510";
                }
                else if(j % 7 == 1 || j % 7 == 3 || j % 7 == 5)
                {
                    TableDraw[k + 0][j] = "\u2502";
                    TableDraw[k + 1][j] = TableDraw[k + 2][j] = TableDraw[k + 3][j] = " ";
                    TableDraw[k + 4][j] = "\u2502";
                    TableDraw[k + 5][j] = TableDraw[k + 6][j] = TableDraw[k + 7][j] = " ";
                    TableDraw[k + 8][j] = "\u2502";
                    TableDraw[k + 9][j] = TableDraw[k + 10][j] = TableDraw[k + 11][j] = " "; 
                    TableDraw[k + 12][j] = "\u2502";
                }
                else if(j % 7 == 2 || j % 7 == 4)
                {
                    TableDraw[k + 0][j] = "\u251C";
                    TableDraw[k + 1][j] = TableDraw[k + 2][j] = TableDraw[k + 3][j] = "\u2500";
                    TableDraw[k + 4][j] = "\u253C";
                    TableDraw[k + 5][j] = TableDraw[k + 6][j] = TableDraw[k + 7][j] = "\u2500";
                    TableDraw[k + 8][j] = "\u253C";
                    TableDraw[k + 9][j] = TableDraw[k + 10][j] = TableDraw[k + 11][j] = "\u2500"; 
                    TableDraw[k + 12][j] = "\u2524";
                }
                else if(x % 7 == 6 )
                {
                    TableDraw[k + 0][j] = "\u2514";
                    TableDraw[k + 1][j] = TableDraw[k + 2][j] = TableDraw[k + 3][j] = "\u2500";
                    TableDraw[k + 4][j] = "\u2534";
                    TableDraw[k + 5][j] = TableDraw[k + 6][j] = TableDraw[k + 7][j] = "\u2500";
                    TableDraw[k + 8][j] = "\u2534";
                    TableDraw[k + 9][j] = TableDraw[k + 10][j] = TableDraw[k + 11][j] = "\u2500"; 
                    TableDraw[k + 12][j] = "\u2518";
                }
            }
        }
    }
    double FCursorSmallX = CursorSmallX;
    double FCursorSmallY = CursorSmallY;
    // double FCursorBigX = CursorBigX;
    // double FCursorBigY = CursorBigY;
    if(FCursorSmallX > 2)
    {
        FCursorSmallX += 0.25;
    }
    if(FCursorSmallY > 2)
    {
        FCursorSmallY += 0.5;
    }
    if(IsCursorSmall)
    {
        TableDraw[int (FCursorSmallX * 4 + 4)][int (FCursorSmallY * 2)] = "\u2557"; // RU
        TableDraw[int (FCursorSmallX * 4)][int (FCursorSmallY * 2)] = "\u2554"; // LU
        TableDraw[int (FCursorSmallX * 4 + 4)][int (FCursorSmallY * 2 + 2)] = "\u255D"; // RD
        TableDraw[int (FCursorSmallX * 4)][int (FCursorSmallY * 2 + 2)] = "\u255A"; // LD
        for (int i=1;i<4;i++)
        {
            TableDraw[int (FCursorSmallX * 4 + i)][int (FCursorSmallY * 2)] = "\u2550";
            TableDraw[int (FCursorSmallX * 4 + i)][int (FCursorSmallY * 2 + 2)] = "\u2550";
        }
        TableDraw[int (FCursorSmallX * 4)][int (FCursorSmallY * 2 + 1)] = "\u2551";
        TableDraw[int (FCursorSmallX * 4 + 4)][int (FCursorSmallY * 2 + 1)] = "\u2551";
    }
    else if(IsCursorBig)
    {
        TableDraw[CursorBigX * 13 + 12][CursorBigY * 7] = "\u2557"; // RU
        TableDraw[CursorBigX * 13][CursorBigY * 7] = "\u2554"; // LU
        TableDraw[CursorBigX * 13 + 12][CursorBigY * 7 + 6] = "\u255D"; // RD
        TableDraw[CursorBigX * 13][CursorBigY * 7 + 6] = "\u255A"; // LD
        for (int i=1;i<12;i++)
        {
            TableDraw[CursorBigX * 13 + i][CursorBigY * 7] = "\u2550";
            TableDraw[CursorBigX * 13 + i][CursorBigY * 7 + 6] = "\u2550";
        }
        for (int i=1;i<6;i++)
        {
            TableDraw[CursorBigX * 13 ][CursorBigY * 7 + i ] = "\u2551";
            TableDraw[CursorBigX * 13 + 12][CursorBigY * 7 + i] = "\u2551";
        }
    }
    return;
}

void Draw‌B‌ead(string ** TableDraw, int ** TableRU, int ** TableLU, int ** TableRD, int ** TableLD)
{
    for(int j = 0 ; j < 14 ; j++)
    {
        for(int i = 0 ; i < 26 ; i++)
        {
            if(i < 13 && j < 7 && i % 4 == 2 && j % 2 == 1)
            {
                TableDraw[i][j] = Convert(TableLU , i/4, j/2);
            }
            else if(i >= 13 && j < 7 && i % 4 == 3 && j % 2 == 1)
            {
                TableDraw[i][j] = Convert(TableRU , i/4 - 3, j/2);
            }
            else if(i < 13 && j >= 7 && i % 4 == 2 && j % 2 == 0)
            {
                TableDraw[i][j] = Convert(TableLD , i/4, j/2 - 4);
            }
            else if(i >= 13 && j >= 7 && i % 4 == 3 && j % 2 == 0)
            {
                TableDraw[i][j] = Convert(TableRD - 3, i/4, j/2 - 4);
            }
            
        }
    }
    return;
}

char Convert(int ** Table, int x, int y)
{
    switch (Table[x][y] % 2)
    {
        case 0:
        {
            return 'O';
            break;
        }
        case 1:
        {
            return 'X';
            break;
        }
        default:
        {
            return ' ';
            break;
        }
    }
}

void PrintTable(string ** TableDraw, int Turn, string X, string O, bool Win, bool Draw)
{
    if(!Win && !Draw)
    {
        string TurnNow;
        string TurnNowBead;
        Turn % 2 == 1 ? TurnNow = X  : TurnNow = O;
        Turn % 2 == 1 ? TurnNowBead = "X"  : TurnNowBead = "O";
        cout << TurnNow << "\'s turn, as " << TurnNowBead << ":\n";
    }
    for(int j = 0 ; j < 14 ; j++)
    {
        for(int i = 0 ; i < 26 ; i++)
        {
            cout << TableDraw[i][j];  
        }
        cout << "\n";
    }
    return;
}