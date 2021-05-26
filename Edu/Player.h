#ifndef SERPIENTESESCALERAS_PLAYER_H
#define SERPIENTESESCALERAS_PLAYER_H

#include "Tiles.h"

class Player: public Tiles
{
    private:
        int playerNum;
        int position;

    public:
        Player();
        Player(int);

        void printPlayer();
        int getPosition();
        void move(int);
};

#endif //SERPIENTESESCALERAS_PLAYER_H
