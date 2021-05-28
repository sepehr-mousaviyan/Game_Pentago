#include <iostream>
using namespace std;
void MakeTableZero(int ** TableName)
{
    for (int Row = 0 ; Row < 3 ; ++Row)
    {
        for (int Column = 0 ; Column < 3 ; ++Column)
        {
            TableName[Row][Column] = -1;
        }
    }
    return;
}