#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

using namespace std;

class player {

    public:
        player (string name);  //constructor
        int column;

};

class HumanPlayer : public player {

    public:
        HumanPlayer (string name);  //constructor


};

class ComputerPlayer : public player {

    public:
        ComputerPlayer (string name);  //constructor
    private:
        int algorithm();

};


#endif // PLAYER_H_INCLUDED
