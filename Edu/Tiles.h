//
// Created by conti on 5/23/2021.
//

#ifndef SERPIENTESESCALERAS_TILES_H
#define SERPIENTESESCALERAS_TILES_H

#include <iostream>
using namespace std;

class Tiles {
protected:
    string type;

public:
    Tiles();
    Tiles(string);

    string getType();
    int getPenalty();
};


#endif //SERPIENTESESCALERAS_TILES_H