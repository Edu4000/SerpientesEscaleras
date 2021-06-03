//
// Created by conti on 5/23/2021.
//

#include "Tiles.h"
#include <iostream>

Tiles::Tiles()
{
    this -> tileNum = 0;
    this -> tileType = "N";
    this -> reward = 0;
    this -> penalty = 0;
}

Tiles::Tiles(std::string tileType, int tileNum, int reward, int penalty) {
    this -> tileNum = tileNum;
    this -> tileType = tileType;
    this -> reward = reward;
    this -> penalty = -penalty;
}

int Tiles::getTileNum()
{
    return tileNum;
}

std::string Tiles::getTileType()
{
    return tileType;
}

int Tiles::additionalMove()
{
    if (tileType == "S") 
    {
        return penalty;
    }
    else if (tileType == "L")
    {
        return reward;
    }
    return 0;
}
