// Kolory.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

struct Gracz {
    string imie;
    int kasa = 0;
};

struct Gracz gracze[3];

int Kolo[] = { -1, 0, 100, 200, 100, 200, 100, 200, 500, 500, 1000, 1000, 1500, 2000, 3000, 5000 };
// -1 bankrut
// 0 strata kolejki


void textColor(char c = 'W')
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    auto colors = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE; //default white gray

    switch (c) {
    case 'Y':   //yellow
            colors = FOREGROUND_RED | FOREGROUND_GREEN;
            break;
    case 'R': 
            colors = 12;
            break;
    case 'G': 
            colors = FOREGROUND_GREEN;
            break;
    case 'B': 
        colors = FOREGROUND_BLUE | FOREGROUND_GREEN;
        break;
    case 'P': 
        colors = FOREGROUND_RED | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
    }

    SetConsoleTextAttribute(hStdOut, colors);

}

void textPlayers()
{
    int i;
    textColor();
    cout << "\n";
    for(i=0; i<3; i++)
        cout << gracze[i].imie << "\t" << gracze[i].kasa << "\n";
    cout << "\n";
}


int main()
{
    /* initialize random seed: */
    srand(time(NULL));
    
    textColor('P');

    //char rainbow[] = { 'R','G','Y','B'};

    cout << "He..o Wo..d!\n";

    //system("cls");
    textColor();

    cout << rand() % 10 + 1;

    gracze[0].imie = "Monika";
    gracze[1].imie = "Jan";
    gracze[2].imie = "Franek";

    textPlayers();
}

