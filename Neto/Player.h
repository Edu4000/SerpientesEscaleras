//
// Created by conti on 5/23/2021.
//

#ifndef SERPIENTESESCALERAS_PLAYER_H
#define SERPIENTESESCALERAS_PLAYER_H

#include <iostream>

class Player {
public:
    int position;
    int playerNum;
    Player();
    Player(int);
    int getPlayerNum();
    int getPos();
    void setNewPos(int);
};

#endif //SERPIENTESESCALERAS_PLAYER_H