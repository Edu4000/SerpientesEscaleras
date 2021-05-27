//
// Created by conti on 5/24/2021.
//

#include "Dice.h"
#include <cstdlib>
#include <iostream>
#include "time.h"

Dice::Dice()
{
    this -> diceVal = 0;
}

void Dice::rollDice()
{
    diceVal = 1 + (std::rand() % (6)); // nmin = 1;
}

int Dice::getDiceVal()
{
    return diceVal;
}