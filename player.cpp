#include "player.h"


using namespace std;

player::player(int playerNr){       //player erzeugen mit spielernummer
    playerNumber = playerNr;
}

player::~player(){}



void player::checkTurn(){                //aufforderung spalte zu w�hlen -> wird eingelesen und �bergeben
    cout << "Player " << playerNumber << ": " << "Choose a column to insert coin: ";
    cin >> column;
    cout << endl;
}
