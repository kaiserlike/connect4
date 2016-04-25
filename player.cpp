#include "player.h"
#include "board.h"


using namespace std;

player::player(int playerNr){       //player erzeugen mit spielernummer
    playerNumber = playerNr;
}

player::~player(){}



void player::checkTurn(){                //aufforderung spalte zu wŠhlen -> wird eingelesen und Ÿbergeben
    cout << "Player " << playerNumber << ": " << "Choose a column to insert coin: ";
    cin >> column;
    cout << endl;
}

void player::playTurn(){         //gibt die Column zurueck, in die gespielt wird
    int play = 0;
    if (PlayerNumber == 1){
        ownCoin = 'A';
        opCoin = 'B';
    }else{
        ownCoin = 'B';
        opCoin = 'A';
    }

    if(lastPlayed == 33){
        play = 4;
    }

    if(Spielfeld[height][play] != '.'){
        if(play+1 < 9){
            play++;
        }else{
            play=1;}
    }else{
        column = play;
        lastPlayed = play;
    }



}
