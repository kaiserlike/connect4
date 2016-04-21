#include "board.h"

board::board(int w, int h){

    for(int x=0; x < h; x++){
        for(int y=0; y < w; y++){
            output [x] [y] = '.';
        }
    }



}

void board::printBoard(){
    for(int x=0; x < 5; x++){
        for(int y=0; y < 8; y++){
            cout << output [x] [y];
        }
        cout << x+1 << endl;
    }
    for(int i=1; i<=8; i++){
        cout << i;
    }
    cout << endl;
}

void board::turn(){
    if(playerTurn==1){
        cout<<"choose a column player 1: ";
        cin >> column;
    }else if(playerTurn==2){
        cout<<"choose a column player 2: ";
        cin >> column;
    }
    if (output [4] [column - 1] == '.'){
        if (playerTurn==1){
            for (int i=4; i>=0; i--){
                if(output [i] [column-1] == '.'){
                    output [i] [column-1] = 'A';
                    break;
                }
            }
        }else if (playerTurn==2){
            for (int i=4; i>=0; i--){
                if(output [i] [column-1] == '.'){
                    output [i] [column-1] = 'B';
                    break;
                }
            }
        }

        if(playerTurn==1){
            playerTurn=2;
        }else if(playerTurn==2){
            playerTurn=1;
        }
    }else {
        cout << "Spalte voll!" << endl;
    }
}

void board::info(){
    cout << "Choose gamemode:" << endl;
    cout << "press 1 for player versus player" << endl;
    cout << "press 2 for player versus computer" << endl;
    cout << "press 3 for computer versus computer" << endl;
    cout << "press 0 to quit" << endl;
}



board::~board(){

}
