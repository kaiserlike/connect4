#include <iostream>
#include <string>
#include "board.h"

using namespace std;

int main()
{

    int width = 9, height = 6;
    int mode = -1;
    board Spielfeld(width, height);
    Spielfeld.info();
    cin >> mode;
    while(mode != 0){
        switch (mode){
            case 1: Spielfeld.printBoard();

                    Spielfeld.turn();

                    Spielfeld.printBoard();
                    Spielfeld.turn();
                    Spielfeld.printBoard();
                    Spielfeld.info();

                    cin >> mode;

                    break;
        }
    }



    return 0;
}
