#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int ConvertScore(string score);
void Sort(string * Words, int * Score, int * WinNumber, int * LoseNumber,int counter);

void AddGame(string O, string X, bool Win, bool Draw, int Turn)
{
    
    // print various components of tm structure.
    ofstream Source;
    Source.open("Source.txt" , ios::app);
    
    if(Draw)
    {
        Source << X << " " << "Draw" << " " ;
        Source << O << " " << "Draw" << "\n";
    }
    else if(Win)
    {
        string Winer;
        string Loser;
        Turn % 2 == 1 ? Winer = X : Winer = O;
        Turn % 2 == 1 ? Loser = O : Loser = X;
        Source << Winer << " " << "Win" << " " ;
        Source << Loser << " " << "Lose" << "\n";
    }
    Source.close();
    return;
}
void Ranking()
{
    //trying to open
    ifstream Source;
    Source.open("Source.txt");
    int CountTime = 0;
    while (!Source && CountTime < 3) 
    {
        CountTime++;
        ifstream Source ( "Library_3.txt", ios::in );
    }
    if(CountTime == 3)
    {
        cerr << "File does not exits!\nPlease make the file.\n";
        exit(1);
    }
    string word1, word2;
    int counter = 0;
    int n = 100;
    const int d = 50;
    string * Words;
    Words = new string [n];
    int * Score;
    Score = new int [n];
    for(int i = 0 ; i < n ; i++)
    {
        Score[i] = 0;
    }
    int * WinNumber;
    WinNumber = new int [n];
    for(int i = 0 ; i < n ; i++)
    {
        WinNumber[i] = 0;
    }
    int * LoseNumber;
    LoseNumber = new int [n];
    for(int i = 0 ; i < n ; i++)
    {
        LoseNumber[i] = 0;
    }
    Source >> word1;
    Words[0] = word1;
    while(Source >> word2)
    {
        bool IsThere = false;
        if(counter == n)
        {
            string * TempWord;
            TempWord = new string [n];
            int * TempScore;
            TempScore = new int [n];
            int * TempWinNumber;
            TempWinNumber = new int [n];
            int * TempLoseNumber;
            TempLoseNumber = new int [n];
            for(int i=0 ; i < n ; i++)
            {
                TempWord[i] = Words[i];
                TempScore[i] = Score[i];
                TempWinNumber[i] = WinNumber[i];
                TempLoseNumber[i] = LoseNumber[i];
            }
            delete [] Words;
            delete [] Score;
            delete [] WinNumber;
            delete [] LoseNumber;
            n = n + d;
            Words = new string [n];
            Score = new int [n];
            WinNumber = new int [n];
            LoseNumber = new int [n];
            for(int i=0 ; i < n - d ; i++)
            {
                Words[i] = TempWord[i];
                Score[i] = TempScore[i];
                WinNumber[i] = TempWinNumber[i];
                LoseNumber[i] = TempLoseNumber[i];
            }
            for(int i = n - d ; i < n ; i++)
            {
                Score[i] = 0;
                WinNumber[i] = 0;
                LoseNumber[i] = 0;
            }
            delete [] TempWord;
            delete [] TempScore;
            delete [] TempWinNumber;
            delete [] TempLoseNumber;
        }
        
        for(int i = 0 ; i < counter ; i++)
        {
            if(Words[i] == word1)
            {
                IsThere = true;
                Score[i] += ConvertScore(word2);
                if(word2 == "Win")
                {
                    WinNumber[i]++;
                }
                else if(word2 == "Lose")
                {
                    LoseNumber[i]++;
                }
                break;
            }  
        }
        if(!IsThere)
        {
            Words[counter] = word1;
            Score[counter] += ConvertScore(word2);
            if(word2 == "Win")
            {
                WinNumber[counter]++;
            }
            else if(word2 == "Lose")
            {
                LoseNumber[counter]++;
            }
            counter++;
        }
        Source >> word1;    
    }
    Source.close();
    Sort(Words, Score, WinNumber, LoseNumber, counter);
    for(int i = 0 ; i < 10 ; i++)
    {
        cout << left << setw(2)<< i + 1 << ": " << left << setw(10) << Words[i] << "--> " << "Score: " << setw(4) << Score[i] << "Lose: " << setw(4) << LoseNumber[i] << "Draw: " << setw(4) << Score[i] - WinNumber[i] * 3 << "Win: " << setw(4) << WinNumber[i] << "\n";
    }
    return;
}
int ConvertScore(string score)
{
    if(score == "Lose")
    {
        return 0;
    }
    else if(score == "Draw")
    {
        return 1;
    }
    else if(score == "Win")
    {
        return 3;
    }
    return 0;
}
void Sort(string * Words, int * Score, int * WinNumber, int * LoseNumber,int counter)
{
    for(int i = 0 ; i < counter ; i++)
    {
        for(int j = 0 ; j < counter ; j++)
        {
            // Now comapre strings
            if(Score[i] > Score[j])
            {
                swap(Words[i], Words[j]);
                swap(Score[i], Score[j]);
                swap(WinNumber[i], WinNumber[j]);
                swap(LoseNumber[i], LoseNumber[j]);
            }
            else if(Score[i] == Score[j] && WinNumber[i] > WinNumber[j])
            {
                swap(Words[i], Words[j]);
                swap(Score[i], Score[j]);
                swap(WinNumber[i], WinNumber[j]);
                swap(LoseNumber[i], LoseNumber[j]);
            }
            else if(Score[i] == Score[j] && WinNumber[i] == WinNumber[j] && LoseNumber[i] < LoseNumber[j])
            {
                swap(Words[i], Words[j]);
                swap(Score[i], Score[j]);
                swap(WinNumber[i], WinNumber[j]);
                swap(LoseNumber[i], LoseNumber[j]);
            }
        }
    }
    return;
}