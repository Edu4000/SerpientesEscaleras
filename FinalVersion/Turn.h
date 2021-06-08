#ifndef SERPIENTESESCALERAS_TURN_H
#define SERPIENTESESCALERAS_TURN_H
#include <iostream>
#include "Player.h"
#include "Dice.h"
using namespace std;

class Turn {
public:
    int turn;
    Player p;
    Dice d;
    Tiles t;
    int nextPos;

    Turn();
    void nextTurn();
    int getTurn();
    void setPlayer(Player p);
    void setDice(Dice d);
    void setTiles(Tiles t);
    void setNextPos(int next);

    friend ostream& operator<<(ostream& os, const Turn& obj){
        os << "|Turn|Player|Tile|Dice|Type|EndUp|\n" << "| " << obj.turn+1 << "  |  " << obj.p.playerNum << "  |  " << obj.p.position+1 << " |  " << obj.d.diceVal << " |  " << obj.t.tileType << "  |  " << obj.nextPos+1 << "  |\n" << "--------------------------------------------";
        return os;
    }
};

#endif //SERPIENTESESCALERAS_TURN_H
