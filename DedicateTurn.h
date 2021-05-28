
#include <iostream>


using namespace std;
string Error = "";

void DedicateTurn(int &CursorSmallX, int &CursorSmallY, int ** TableRU, int ** TableLU, int ** TableRD, int ** TableLD, int Turn)
{
    if(CursorSmallX < 3 && CursorSmallY < 3)
    {
        TableLU[CursorSmallX][CursorSmallY] = Turn;
    }
    else if(CursorSmallX >= 3 && CursorSmallY < 3)
    {
        TableRU[CursorSmallX - 3][CursorSmallY] = Turn;
    }
    else if(CursorSmallX < 3 && CursorSmallY >= 3)
    {
        TableLD[CursorSmallX][CursorSmallY - 3] = Turn;
    }
    else if(CursorSmallX >= 3 && CursorSmallY >= 3)
    {
        TableRD[CursorSmallX - 3][CursorSmallY - 3] = Turn;
    }
    return;
}
