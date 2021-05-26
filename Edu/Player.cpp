#include <iostream>
#include "Player.h"

using namespace std;

Player::Player():Tiles()
{
    this->playerNum = 0;
    this->position = 1;
}

Player::Player(int playerNum):Tiles()
{
    this->playerNum = playerNum;
    this->position = 1;
}

void Player::printPlayer() 
{
    cout << this->playerNum << " " << this->position;
}

int Player::getPosition() 
{
    return this->position;
}

void Player::move(int delta)
{
    int aux = position + delta;
    if (aux < 1) {
        this->position = 1;
    } else {
        this->position += delta;
    }
}