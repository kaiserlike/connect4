#include "player.h"


using namespace std;

player::player(int playerNr){       //player erzeugen mit spielernummer
    playerNumber = playerNr;
}

player::~player(){}



void player::checkTurn(){                //aufforderung spalte zu wählen -> wird eingelesen und übergeben
    cout << "Player " << playerNumber << ": " << "Choose a column to insert coin: ";
    cin >> column;
    cout << endl;
}
