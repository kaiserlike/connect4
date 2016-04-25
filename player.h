#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include <iostream>
//#include "board.h"

using namespace std;

class player {

public:
    player (int playerNumber);  //constructor
    ~player();
    void checkTurn();
    int column;     //variable für gewählte spalte
    void playTurn();        //sollte eigentlich in CP sein

private:
    int playerNumber;
};

class HumanPlayer : public player {     //subclass humanplayer

public:
    ~HumanPlayer();


};

class ComputerPlayer : public player {      //subclass computerplayer

public:
    int lastPlayed;
    int opLastPlayed;
    char ownCoin, opCoin;

private:
    //int algorithm();
    //void playTurn(char array[][]);
    int checkBest();
    int checkLoss();



};


#endif // PLAYER_H_INCLUDED
