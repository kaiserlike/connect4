#include <iostream>
#include <string>
#include "board.h"
#include "player.h"

using namespace std;

int main()
{

    int width = 9, height = 6;  //Hoehe und Breite von Spielfeld
    int mode = -1;              // variable zum bestimmen von spielmodi
    board Spielfeld(width, height); //construct Spielfeld
    Spielfeld.info();       //"Hauptmenue" Ausgabe zum Spielmodi waehlen
    cin >> mode;
    while(mode != 0){
        switch (mode){
            case 1:             //player vs player
                    HumanPlayer::player player1(1); //erzeugt player1
                    HumanPlayer::player player2(2); //erzeugt player2
                    Spielfeld.playerTurn=1;         //player1 ist dran
                    while(Spielfeld.win != 1 || Spielfeld.win != 2 || Spielfeld.draw !=40){     //solange niemand gewonnen oder unentschieden ist wird weiter gespielt
                        Spielfeld.printBoard();     //Spielfeld wird geprintet
                        if (Spielfeld.playerTurn==1){
                            player1.checkTurn();            //Eingabe der Spalte in der M�nze eingeworfen wird
                            Spielfeld.turn(player1.column);   //zug wird durchgef�hrt
                        }else if(Spielfeld.playerTurn==2){
                            player2.checkTurn();
                            Spielfeld.turn(player2.column);
                        }


                        if(Spielfeld.win==1 || Spielfeld.win==2 || Spielfeld.draw==40){ //nochmals abchecken ob jemand gewonnen hat oder ein unentschieden ist
                            break;
                        }
                    };
            case 2:             //computer vs player
                    ComputerPlayer::player player3(1); //erzeugt player1
                    HumanPlayer::player player4(2); //erzeugt player2
                    Spielfeld.playerTurn=1;         //player1 ist dran
                    while(Spielfeld.win != 1 || Spielfeld.win != 2 || Spielfeld.draw !=40){     //solange niemand gewonnen oder unentschieden ist wird weiter gespielt
                        Spielfeld.printBoard();     //Spielfeld wird geprintet
                        if (Spielfeld.playerTurn==1){
                            player1.playTurn(Spielfeld.output);
                            Spielfeld.turn(player1.column);   //zug wird durchgef�hrt
                        }else if(Spielfeld.playerTurn==2){
                            player2.checkTurn();
                            Spielfeld.turn(player2.column);
                        }


                        if(Spielfeld.win==1 || Spielfeld.win==2 || Spielfeld.draw==40){ //nochmals abchecken ob jemand gewonnen hat oder ein unentschieden ist
                            break;
                        }
                    };
            /*case 3:             //computer vs computer
                ComputerPlayer::player player1(1); //erzeugt player1
                ComputerPlayer::player player2(2); //erzeugt player2
                Spielfeld.playerTurn=1;         //player1 ist dran
                while(Spielfeld.win != 1 || Spielfeld.win != 2 || Spielfeld.draw !=40){     //solange niemand gewonnen oder unentschieden ist wird weiter gespielt
                    Spielfeld.printBoard();     //Spielfeld wird geprintet
                    if (Spielfeld.playerTurn==1){
                        Spielfeld.turn(player1.playTurn);   //zug wird durchgef�hrt
                    }else if(Spielfeld.playerTurn==2){
                        Spielfeld.turn(player2.playTurn);
                    }


                    if(Spielfeld.win==1 || Spielfeld.win==2 || Spielfeld.draw==40){ //nochmals abchecken ob jemand gewonnen hat oder ein unentschieden ist
                        break;
                    }
                }*/



                    Spielfeld.refreshBoard();   // spielfeld wird wieder mit '.' initialisiert

                    Spielfeld.info();           //Hauptmen� wird wieder aufgerufen

                    cin >> mode;
        }
    }



    return 0;
}
