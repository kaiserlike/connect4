#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class player {

public:
    player (int playerNumber);  //constructor
    ~player();
    void checkTurn();
    int column;     //variable für gewählte spalte

private:
    int playerNumber;
};

class HumanPlayer : public player {     //subclass humanplayer

public:
    ~HumanPlayer();


};

class ComputerPlayer : public player {      //subclass computerplayer

private:
    int algorithm();

};


#endif // PLAYER_H_INCLUDED
