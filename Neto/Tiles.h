//
// Created by conti on 5/23/2021.
//

#ifndef SERPIENTESESCALERAS_TILES_H
#define SERPIENTESESCALERAS_TILES_H

#include <iostream>

class Tiles {
public:
    std::string tileType;
    int tileNum;

    Tiles();
    Tiles(std::string, int);
    int getTileNum();
    std::string getTileType();
};

#endif //SERPIENTESESCALERAS_TILES_H
