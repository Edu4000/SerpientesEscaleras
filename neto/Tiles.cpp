//
// Created by conti on 5/23/2021.
//

#include "Tiles.h"
#include <iostream>

Tiles::Tiles()
{
    this -> tileNum = 0;
    this -> tileType = "";
}

Tiles::Tiles(std::string tileType, int tileNum) {
    this -> tileNum = tileNum;
    this -> tileType = tileType;
}

int Tiles::getTileNum()
{
    return tileNum;
}

std::string Tiles::getTileType()
{
    return tileType;
}