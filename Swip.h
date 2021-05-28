#include <iostream>
using namespace std;
void Swip(int ** TableName, char Move)
{
    int ** TableTemp = new int * [3];
    for(int i = 0 ; i < 3 ; i++)
    {
        TableTemp[i] = new int [3];
    }
    
    if(Move == 'l')
    {
        TableTemp[0][2] = TableName[0][0];
        TableTemp[1][2] = TableName[0][1];
        TableTemp[2][2] = TableName[0][2];
        TableTemp[0][1] = TableName[1][0];
        TableTemp[1][1] = TableName[1][1];
        TableTemp[2][1] = TableName[1][2];
        TableTemp[0][0] = TableName[2][0];
        TableTemp[1][0] = TableName[2][1];
        TableTemp[2][0] = TableName[2][2];
    }
    else if(Move == 'r')
    {
        TableTemp[2][0] = TableName[0][0];
        TableTemp[1][0] = TableName[0][1];
        TableTemp[0][0] = TableName[0][2];
        TableTemp[2][1] = TableName[1][0];
        TableTemp[1][1] = TableName[1][1];
        TableTemp[0][1] = TableName[1][2];
        TableTemp[2][2] = TableName[2][0];
        TableTemp[1][2] = TableName[2][1];
        TableTemp[0][2] = TableName[2][2];
    }
    for(int j = 0 ; j < 3 ; j++)
    {
        for(int i = 0 ; i < 3 ; i++)
        {
            TableName[i][j] = TableTemp[i][j];
        }
    }
    for(int i = 0 ; i < 3 ; i++)
    {
        delete [] TableTemp[i] ;
    }
    delete TableTemp;
    return;
}