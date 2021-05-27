//
// Created by conti on 5/23/2021.
//

#include "Player.h"

Player::Player(int playerNum) {
    this -> position = 0;
    this -> playerNum = playerNum;
}

Player::Player() {
}

int Player::getPlayerNum() {
    return playerNum;
}

int Player::getPos() {
    return position;
}

void Player::setNewPos(int newPosition) {
    position = newPosition;
}
