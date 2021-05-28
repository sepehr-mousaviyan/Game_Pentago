
void IsDraw(int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD, bool &Draw);

//ALL *32
void IsWin(bool &Win, bool &Draw, int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD, string O, string X)
{
    int WinEven = 0;
    int WinOdd = 0;
    
    //Vertical + Horizontal = 24
    for(int i = 0;i < 3; i++)
    {
        //Vertical *12
        if(TableLU[i][1] != -1 && TableLU[i][1] % 2 == TableLU[i][2] % 2 && TableLU[i][1] % 2 == TableLD[i][0] % 2 && TableLU[i][1] % 2 == TableLD[i][1] % 2)
        {
            if(TableLU[i][1] % 2 == TableLU[i][0] % 2 || TableLU[i][1] % 2 == TableLD[i][2] % 2)
            {
                TableLU[i][1] % 2 == 0 ? ++WinEven : ++WinOdd;
            }
        }
        if(TableRU[i][1] != -1 && TableRU[i][1] % 2 == TableRU[i][2] % 2 && TableRU[i][1] % 2 == TableRD[i][0] % 2 && TableRU[i][1] % 2 == TableRD[i][1] % 2)
        {
            if(TableRU[i][1] % 2 == TableRU[i][0] % 2 || TableRU[i][1] % 2 == TableRD[i][2] % 2)
            {
                TableRU[i][1] % 2 == 0 ? ++WinEven : ++WinOdd;
            }
        }
        //Horizontal *12
        if(TableLU[1][i] != -1 && TableLU[1][i] % 2 == TableLU[2][i] % 2 && TableLU[1][i] % 2 == TableRU[0][i] % 2 && TableLU[1][i] % 2 == TableRU[1][i] % 2)
        {
            if(TableLU[1][i] % 2 == TableLU[0][i] % 2 || TableLU[1][i] % 2 == TableRU[2][i] % 2)
            {
                TableLU[1][i] % 2 == 0 ? ++WinEven : ++WinOdd;
            }
        }
        if(TableLD[1][i] != -1 && TableLD[1][i] % 2 == TableLD[2][i] % 2 && TableLD[1][i] % 2 == TableRD[0][i] % 2 && TableLD[1][i] % 2 == TableRD[1][i] % 2)
        {
            if(TableLD[1][i] % 2 == TableLD[0][i] % 2 || TableLD[1][i] % 2 == TableRD[2][i] % 2)
            {
                TableLD[1][i] % 2 == 0 ? ++WinEven : ++WinOdd;
            }
        }
    }
    //Qotr bozorg asli *2
    if(TableLU[1][1] != -1 && TableLU[1][1] % 2 == TableLU[2][2] % 2 && TableLU[1][1] % 2 == TableRD[0][0] % 2 && TableLU[1][1] % 2 == TableRD[1][1] % 2)
    {
        if(TableLU[1][1] % 2 == TableLU[0][0] % 2 || TableLU[1][1] % 2 == TableRD[2][2] % 2)
        {
            TableLU[1][1] % 2 == 0 ? ++WinEven : ++WinOdd;
        }
    }
    //Qotr bozorg fari *2
    if(TableLD[1][1] != -1 && TableLD[1][1] % 2 == TableLD[2][0] % 2 && TableLD[1][1] % 2 == TableRU[0][2] % 2 && TableLD[1][1] % 2 == TableRU[1][1] % 2)
    {
        if(TableLD[1][1] % 2 == TableLD[0][2] % 2 || TableLD[1][1] % 2 == TableRU[2][0] % 2)
        {
            TableLD[1][1] % 2 == 0 ? ++WinEven : ++WinOdd;
        }
    }
    //Qotr kochak asli *2
    if(TableLU[1][0] != -1 && TableLU[1][0] % 2 == TableLU[2][1] % 2 && TableLU[1][0] % 2 == TableRU[0][2] % 2 && TableLU[1][0] % 2 == TableRD[1][0] % 2 && TableLU[1][0] % 2 == TableRD[2][1] % 2)
    {
        TableLU[1][0] % 2 == 0 ? ++WinEven : ++WinOdd;
    }
    if(TableLU[0][1] != -1 && TableLU[0][1] % 2 == TableLU[1][2] % 2 && TableLU[0][1] % 2 == TableLD[2][0] % 2 && TableLU[0][1] % 2 == TableRD[0][1] % 2 && TableLU[0][1] % 2 == TableRD[1][2] % 2)
    {
        TableLU[0][1] % 2 == 0 ? ++WinEven : ++WinOdd;
    }
    //Qotr kochak fari *2
    if(TableLD[1][2] != -1 && TableLD[1][2] % 2 == TableLD[2][1] % 2 && TableLD[1][2] % 2 == TableRD[0][0] % 2 && TableLD[1][2] % 2 == TableRU[1][2] % 2 && TableLD[1][2] % 2 == TableRU[2][1] % 2)
    {
        TableLD[1][2] % 2 == 0 ? ++WinEven : ++WinOdd;
    }
    if(TableLD[0][1] != -1 && TableLD[0][1] % 2 == TableLD[1][0] % 2 && TableLD[0][1] % 2 == TableLU[2][2] % 2 && TableLD[0][1] % 2 == TableRU[0][1] % 2 && TableLD[0][1] % 2 == TableRU[1][0] % 2)
    {
        TableLD[0][1] % 2 == 0 ? ++WinEven : ++WinOdd;
    }
    /////////////////////////////////////////////////
    if(WinEven == 0 && WinOdd == 0)
    {
        return; 
    }
    else if(WinEven > WinOdd)
    {
        Win = true;
        cout << O << " won!\n";
    }
    else if(WinEven < WinOdd)
    {
        Win = true;
        cout << X << " won!\n";
    }
    else
    {
        Draw = true;
        cout << "Draw!\n";
    }
    return;
}
void IsDraw(int ** TableRU, int ** TableLU, int ** TableLD, int ** TableRD, bool &Draw)
{
    for (int Row = 0 ; Row < 3 ; ++Row)
    {
        for (int Column = 0 ; Column < 3 ; ++Column)
        {
            if(TableRU[Column][Row] == -1 || TableLU[Column][Row] == -1 || TableLD[Column][Row] == -1 || TableRD[Column][Row] == -1 ) 
            {
                return;
            }
        }
    }
    Draw = true;
    cout << "Draw!\n";
    return;
}