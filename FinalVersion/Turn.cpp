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
