Was brauche ich?

class ComputerPlayer : public player {      //subclass computerplayer

public:
    int lastPlayed = 33;
    int opLastPlayed = 33;
    char ownCoin, opCoin;

private:
    //int algorithm();
    void playTurn(char array[][]);
    int checkBest(lastPlayed);
    int checkLoss(opLastPlayed);

};

//Dummy Klasse 1: Spielt immer dort, wo er zuletzt gespielt hat. Wenn dort voll ist, eines rechts davon.
void playTurn(Spielfeld[height][width]);         //gibt die Column zurueck, in die gespielt wird
{

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






int checkBest(height, width){
    int counter = 0;
    int maxC = 0;
    //int y = 0;
    //int x = 0;
    bestMove = 4;                                           //eine der Mittelspalten ist tendenziell immer am Besten

    for(int w = 0; w < width-1; w++){                       //das Spielfeld von unten nach oben durchgehen, um zu checken
        for(int h = 1; h < height; h++){                    //ob es irgendwo 3, dann zwei, dann 1 verbundene von uns gibt
            if(Spielfeld[h][w] == ownCoin){
                int startY = h;
                int startX = w;
                counter ++;

                while(h+1 < height && h-1 > 0){             //checken, obs nicht außerhalb des Spielfelds geht
                    if(Spielfeld[h][w-1] == ownCoin){       //1
                        while(Spielfeld[h][w-1] == ownCoin){
                            counter++;
                            h;
                            w--;
                        }
                        switch(counter){                    //gehört in eine eigene funktion, dann in alle ifs (1-5)
                            case(counter >= 3):
                                //check, if can play there
                                //bestMove == there
                                //get out of here and play there

                            case(counter > maxC && counter < 3):
                                //set maxC = counter; reset counter = 0;
                                //check, if can play there
                                //check, if opponent wins if play there
                                //bestMove == there
                                //try next direction

                            case(counter < maxC):
                                //break and try next direction;
                        }


                    }
                    if(Spielfeld[h+1][w-1] == ownCoin){       //2
                        while(Spielfeld[h+1][w-1] == ownCoin){
                            counter++;
                            h++;
                            w--;
                        }

                    }

                    if(Spielfeld[h+1][w] == ownCoin){     //3
                        i(Spielfeld[h+1][w] == ownCoin){
                            counter++;
                            h++;
                            w;
                        }
                    }

                    if(Spielfeld[h+1][w+1] == ownCoin){     //4
                        while(Spielfeld[h+1][w+1] == ownCoin){
                            counter++;
                            h++;
                            w++;
                        }
                    }

                    if(Spielfeld[h][w+1] == ownCoin){     //5
                        while(Spielfeld[h][w+1] == ownCoin){
                            counter++;
                            h;
                            w++;
                        }
                    }
                }
            }
        }
    }
}

    column = play;
    lastPlayed = play;


checkPlayable(int height, int width){
    if(Spielfeld[height][width] == '.' && Spielfeld[height-1][width] != '.'){
        play = width//+1                //CHECKEN, obs plus 1 gehoert!!!!
    }
}


checkLoss()
{
    //genau wie checkBest aber mit opCoin
}







1 2 3 4 4 3 2 1
2 3 4 5 5 4 3 2
3 4 5 6 6 5 4 3
2 3 4 5 5 4 3 2
1 2 3 X 4 3 2 1

1 2 3 4 4 3 2 1
2 3 4 5 5 4 3 2
3 4 5 6 6 5 4 3
2 3 4 O 5 4 3 2
1 2 3 X 4 3 2 1

1 2 3 4 4 3 2 1
2 3 4 5 5 4 3 2
3 4 5 6 6 5 4 3
2 3 4 5 5 4 3 2
1 2 3 X 4 3 2 1

1 2 3 4 4 3 2 1
2 3 4 5 5 4 3 2
3 4 5 6 6 5 4 3
2 3 4 5 5 4 3 2
1 2 3 X 4 3 2 1
