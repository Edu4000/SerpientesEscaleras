//
// Created by conti on 5/23/2021.
//

#ifndef SERPIENTESESCALERAS_TILES_H
#define SERPIENTESESCALERAS_TILES_H

#include <iostream>

class Tiles {
private:
    int reward, penalty;
    std::string tileType;
    int tileNum;

public:
    Tiles();
    Tiles(std::string, int,int,int);
    int getTileNum();
    std::string getTileType();

    int additionalMove();
};

#endif //SERPIENTESESCALERAS_TILES_H
