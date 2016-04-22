#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class board {

    public:

        board (int width, int height);  // constructor

        ~board(); // destructor

        void info();
        void printBoard();
        void turn(int column);
        void checkWin(int column);

        void refreshBoard();


        int playerTurn = 1;     //variable f�r spieler der an der reihe ist
        int currentCoin=0;      //variable f�r position der zuletzt eingeworfenen m�nze
        int win=0;          // ob bzw wer gewonnen hat 1=spieler1, 2=spieler2
        int draw=0;     //ob unentschieden ist, z�hlt die belegten felder -> 40=unentschieden (8*5)


    private:


        int width=8, height=5;
        char output [5] [8];        //array f�r spielfeld


};


#endif // FUNCTIONS_H_INCLUDED
