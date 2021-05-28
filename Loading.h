#include <iostream>
#include <windows.h>
using namespace std;

void Loading()
{
    int x = 2000;
    for(int i = 1; i < 10; i++)
    {
        if(x % 2 == 0)
        {
            x /= 2;
        }
        Sleep(x);
        system("cls");
        cout << "Welcome to Pentilagon!!\n";
        for(int j = 0; j < i; j++)
        {
            cout << "//";
        }
    }
    Sleep(2000);
}