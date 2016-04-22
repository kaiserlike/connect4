#include "player.h"


using namespace std;

player::player(int playerNr){       //player erzeugen mit spielernummer
    playerNumber = playerNr;
}

player::~player(){}

void player::getPlayer(){       //gibt spieler aus
    cout << "Player " << playerNumber << ": ";
}

