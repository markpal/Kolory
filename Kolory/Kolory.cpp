﻿// Kolory.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
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
        break;
    default:
        //colors = 22;
        break;
    }

    SetConsoleTextAttribute(hStdOut, colors);

}

void textPlayers()
{
    int i;
    textColor();
    cout << "\n";
    for (i = 0; i < 3; i++)
        cout << gracze[i].imie << "\t" << gracze[i].kasa << "\n";
    cout << "\n";
}


int main()
{
    int i;

    string haslo = "wielka antarktyda";
    char literka;
    int n = haslo.size();
    int maska[100];
    int suma = 0;

    for (i = 0; i < n; i++)
    {
        if (haslo[i] == ' ')
            maska[i] = 0;
        else
            maska[i] = 1;
    }

    do
    {
        cout << "Podaj litere" << endl;
        cin >> literka;

        for (i = 0; i < n; i++)
        {
            if (haslo[i] == literka)
                maska[i] = 0;
        }

        textColor('P');
        for (i = 0; i < n; i++)
        {

            if (maska[i] == 1)
                cout << ".";
            else
                cout << haslo[i];
        }
        textColor();
        cout << endl;

        suma = 0;

        for (i = 0; i < n; i++)
        {
            suma += maska[i];
        }

    } while (suma);
    cout << "BRAWO!";
    exit(0);
    /* initialize random seed: */
    srand(time(NULL));

    textColor('P');

    //char rainbow[] = { 'R','G','Y','B'};

    cout << "He..o Wo..d!\n";

    //system("cls");
    textColor();

    i = rand() % 15;
    cout << Kolo[i];

    gracze[0].imie = "Monika";
    gracze[1].imie = "Jan";
    gracze[2].imie = "Franek";

    textPlayers();
    Beep(523, 500);
}
