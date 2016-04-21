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
        void turn();
        void checkWin();
        int column=2;


    private:

        char output [5] [8];
        int columnFull [8] = {0,0,0,0,0,0,0,0};
        int playerTurn = 1;

};


#endif // FUNCTIONS_H_INCLUDED
