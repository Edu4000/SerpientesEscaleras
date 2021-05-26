
//
// Created by conti on 5/23/2021.
//
#include <iostream>
#include "Tiles.h"

using namespace std;

Tiles::Tiles() {
    this -> type = "N";
}

Tiles::Tiles(string type) {
    this -> type = type;
}

string Tiles::getType() {
    return this->type;
}

int Tiles::getPenalty() {
    if (this->type == "L") {
        return 3;
    }
    else if (this->type == "S")
    {
        return -3;
    }
    else
    {
        return 0;
    }
}