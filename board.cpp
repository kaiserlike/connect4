#include "board.h"

using namespace std;


board::board(int w, int h){     //spielfeld wird erzeugt und mit '.' initialisiert

    for(int x=0; x < h; x++){
        for(int y=0; y < w; y++){
            output [x] [y] = '.';
        }
    }



}

void board::printBoard(){       //spielfeld wird ausgegeben
    for(int x=0; x < 5; x++){
        for(int y=0; y < 8; y++){
            cout << output [x] [y];
        }
        cout << x+1 << endl;
    }
    for(int i=1; i<=8; i++){
        cout << i;
    }
    cout << endl << endl;
}

void board::turn(int column){       //spielzug

    if (output [0] [column - 1] == '.'){        //wird gecheckt ob spalte voll ist
        if (playerTurn==1){                     //abfrage welcher spieler dran ist
            for (int i=4; i>=0; i--){           //in das erste freie feld von unten wird A eingetragen (münze)
                if(output [i] [column-1] == '.'){
                    output [i] [column-1] = 'A';
                    currentCoin=i;              //aktuell eingeworfene münzposition wird gespeichert (später für checkWin)
                    break;
                }
            }
        }else if (playerTurn==2){
            for (int i=4; i>=0; i--){
                if(output [i] [column-1] == '.'){
                    output [i] [column-1] = 'B';
                    currentCoin=i;
                    break;
                }
            }
        }
        checkWin();     //überprüfung ob gewonnen od unentschieden
        if(win ==1){
            printBoard();
            cout << "player 1 has won!!!" << endl << endl;
        }else if (win == 2){
            printBoard();
            cout << "player 2 has won!!!" << endl << endl;
        }else if (draw==40){
            printBoard();
            cout << "Draw!!!" << endl << endl;
        }
        if(playerTurn==1){      //spieler der an der reihe ist wird gewechselt
            playerTurn=2;
        }else if(playerTurn==2){
            playerTurn=1;
        }
    }else {
        cout << "Spalte voll!" << endl << endl;     //wird ausgegeben wenn gewählte spalte voll ist
    }
}

void board::info(){                     //hauptmenü text
    cout << "Choose gamemode:" << endl;
    cout << "press 1 for player versus player" << endl;
    cout << "press 2 for player versus computer" << endl;
    cout << "press 3 for computer versus computer" << endl;
    cout << "press 0 to quit" << endl;
}

void board::checkTurn(){                //aufforderung spalte zu wählen -> wird eingelesen und übergeben
    cout << "Choose a column to insert coin: ";
    cin >> column;
    cout << endl;
}

void board::checkWin(){
    int connect4;               //variable zum zählen der münzen nacheinander (waagrecht, senkrecht und diagonal)
    connect4=0;
    win=0;
    if(playerTurn==1){          //check player 1 ob gewonnen
        for(int i=0;i<5; i++){
            if((currentCoin + i) == 5){     //abbruch wenn am ende des arrays
                break;
            }
            if(output [currentCoin+i] [column - 1] == 'A'){     //checkt ob münza da (südlich) von zuletzt eingeworfener münze weg, wenn ja, zähle 1 zu connect4
                connect4++;
            }else{
                break;                          //sobald keine münze da ist, abbruch
            }
        }
        for(int i=1;i<5; i++){
            if((currentCoin - i) < 0){
                break;
            }
            if(output [currentCoin-i] [column - 1] == 'A'){     //checkt ob münza da (nördlich), wenn ja, zähle 1 zu connect4
                connect4++;
            }else{
                break;
            }
        }
        if (connect4 == 4){     //wenn 4 hintereinander waren -> win variable setzen
            win = 1;
        }
        connect4=0;                     //connect4 wieder auf 0 um andere richtungen zu checken
        for(int i=0;i<8; i++){
            if((column + i) == 8){
                break;
            }
            if(output [currentCoin] [column-1 + i] == 'A'){     //checkt ob münza da (östlich), wenn ja, zähle 1 zu connect4
                connect4++;
            }else{
                break;
            }
        }
        for(int i=1;i<8; i++){
            if((column - i) < 0){
                break;
            }
            if(output [currentCoin] [column-1 - i] == 'A'){     //checkt ob münza da (westlich), wenn ja, zähle 1 zu connect4
                connect4++;
            }else{
                break;
            }
        }

        if (connect4 == 4){     //wenn 4 hintereinander waren -> win variable setzen
                win = 1;
        }
        connect4=0;     //connect4 wieder auf 0 um andere richtungen zu checken
        for (int i=0; i<4;i++){                     //check diagonal
            if((currentCoin+i)<5&&(column-1+i)<8){
                if (output [currentCoin+i] [column-1+i]=='A'){          //check südöstlich
                    connect4++;
                }
            }
        }
        for (int i=1; i<4;i++){
            if((currentCoin-i)>0&&(column-1-i)>0){
                if (output [currentCoin-i] [column-1-i]=='A'){      //check nordwestlich
                    connect4++;
                }
            }
        }
        if (connect4 == 4){     //wenn 4 hintereinander waren -> win variable setzen
                win = 1;
        }
        connect4=0;     //connect4 wieder auf 0 um andere richtungen zu checken
        for (int i=0; i<4;i++){
            if((currentCoin-i)>0&&(column-1+i)<8){
                if (output [currentCoin-i] [column-1+i]=='A'){      //check nordöstlich
                    connect4++;
                }
            }
        }
        for (int i=1; i<4;i++){
            if((currentCoin+i)<5&&(column-1-i)>0){
                if (output [currentCoin+i] [column-1-i]=='A'){      //check südwestlich
                    connect4++;
                }
            }
        }
        if (connect4 == 4){     //wenn 4 hintereinander waren -> win variable setzen
                win = 1;
        }
    }else if(playerTurn==2){        //check player 1 ob gewonnen, wie oben
        for(int i=0;i<5; i++){
            if((currentCoin + i) == 5){
                break;
            }
            if(output [currentCoin+i] [column - 1] == 'B'){
                connect4++;
            }else{
                break;
            }
        }
        for(int i=1;i<5; i++){
            if((currentCoin - i) < 0){
                break;
            }
            if(output [currentCoin-i] [column - 1] == 'B'){
                connect4++;
            }else{
                break;
            }
        }
        if (connect4 == 4){
            win = 2;
        }
        connect4=0;
        for(int i=0;i<8; i++){
            if((column + i) == 8){
                break;
            }
            if(output [currentCoin] [column-1 + i] == 'B'){
                connect4++;
            }else{
                break;
            }
        }
        for(int i=1;i<8; i++){
            if((column - i) < 0){
                break;
            }
            if(output [currentCoin] [column-1 - i] == 'B'){
                connect4++;
            }else{
                break;
            }
        }

        if (connect4 == 4){
                win = 2;
        }
        connect4=0;
        for (int i=0; i<4;i++){                     //check diagonal
            if((currentCoin+i)<5&&(column-1+i)<8){
                if (output [currentCoin+i] [column-1+i]=='B'){
                    connect4++;
                }
            }
        }
        for (int i=1; i<4;i++){
            if((currentCoin-i)>0&&(column-1-i)>0){
                if (output [currentCoin-i] [column-1-i]=='B'){
                    connect4++;
                }
            }
        }
        if (connect4 == 4){
                win = 2;
        }
        connect4=0;
        for (int i=0; i<4;i++){
            if((currentCoin-i)>0&&(column-1+i)<8){
                if (output [currentCoin-i] [column-1+i]=='B'){
                    connect4++;
                }
            }
        }
        for (int i=1; i<4;i++){
            if((currentCoin+i)<5&&(column-1-i)>0){
                if (output [currentCoin+i] [column-1-i]=='B'){
                    connect4++;
                }
            }
        }
        if (connect4 == 4){
                win = 2;
        }
    }
    draw=0;
    for(int x=0;x<5;x++){       //check ob unentschieden
        for(int y=0;y<8;y++){
            if (output [x] [y] != '.'){
                draw++;
            }else{
                draw=0;
                break;
            }
        }
    }
}

void board::refreshBoard(){     //board wieder mit '.' initialisieren
    for(int x=0; x < 5; x++){
        for(int y=0; y < 8; y++){
            output [x] [y] = '.';
        }
    }
}

board::~board(){

}
