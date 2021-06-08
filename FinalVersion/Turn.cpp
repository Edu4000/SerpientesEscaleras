#include "Turn.h"

Turn::Turn() {
  this -> turn = 0;
}

void Turn::nextTurn() {
  this->turn++;
}

int Turn::getTurn() {
  return this->turn;
}

void Turn::setDice(Dice d) {
    this->d = d;
}

void Turn::setPlayer(Player p) {
    this->p = p;
}

void Turn::setTiles(Tiles t) {
    this->t = t;
}

void Turn::setNextPos(int next) {
    this->nextPos = next;
}
