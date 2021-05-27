//
// Created by conti on 5/23/2021.
//

#include <iostream>
#include "Tiles.h"
#include "Dice.h"
#include "Player.h"
#include "ctime"

class MyGame {
public:
    void start() {
        int numberPlayers;
        int turns;
        Tiles board[30]; // board[0] is tile[1]
        std::srand(time(0));
        Dice D = Dice();
        Player * currPlayer;

        /* Random locations for ladder and snake tiles are created */
        int ld1 = 1 + (std::rand() % (5 - 1 + 1));
        int sn1 = 6 + (std::rand() % (10 - 6 + 1));
        int ld2 = 11 + (std::rand() % (15 - 11 + 1));
        int sn2 = 16 + (std::rand() % (20 - 16 + 1));
        int ld3 = 21 + (std::rand() % (25 - 21 + 1));
        int sn3 = 26 + (std::rand() % (29 - 26 + 1));

        for (int i = 0; i < 30; i++)
        {
            if ( (i == sn1) || (i == sn2) || (i == sn3))
            {
                board[i] = Tiles("Snake", i+1);
            } else if ((i == ld1) || (i == ld2) || (i == ld3))
            {
                board[i] = Tiles("Ladder", i+1);
            } else {
                board[i] = Tiles("N", i+1);
            }
        }

        // Welcome message and questions
        std::cout << "Welcome to Snakes and Ladders" << std::endl;
        std::cout << "How many players will play?" << std::endl;
        std::cin >> numberPlayers;
        std::cout << "How many turns do you want?" << std::endl;
        std::cin >> turns;
        std::cout << "Enjoy!!!\n" << std::endl;

        /* Start of the game */
        std::cout << "Press C to continue next turn, or E to end the game: " << std::endl;
        int turn = 0;

        // Creating Array of Players
        Player players [numberPlayers];
        for (int i = 0; i < numberPlayers; i++)
        {
            players[i] = Player(i + 1);
        }

        // While loop
        std::string input;

        while (true) {
            std::cin >> input;

            try {
                if (input == "C") {
                    // rest of the code
                    currPlayer = &players[turn % numberPlayers];

                    /* Roll dice and find new positions for the player */
                    D.rollDice();
                    std::string type;
                    int nextPos = currPlayer->getPos() + D.getDiceVal(); // Next absolute position given the player's absolute position plus the dice
                    int finalPos;

                    for (int i = 0; i < 30; i++) {
                        if (board[i].getTileNum() == nextPos) { // loop and find the tile with the same absolute position of the next position aof the player
                            if (board[i].getTileType() == "Snake") {
                                finalPos = nextPos - 3;
                                type = "S";
                            } else if(board[i].getTileType() == "Ladder") {
                                finalPos = nextPos + 3;
                                type = "L";
                            } else {
                                finalPos = nextPos;
                                type = "N";
                            }
                        }
                    }

                    if (finalPos >= 29) { // If it is a ladder, then it does this and wins the game
                        std::cout << "|Turn|Player|Tile|Dice|Type|EndUp|" << std::endl;
                        std::cout << "| " << turn+1 << "  |  " << currPlayer->getPlayerNum() << "  |  " << currPlayer->getPos()+1 << " |  " << D.getDiceVal() << " | " << type << " | " <<  "30 |" << std::endl;
                        std::cout << "Player " << currPlayer->getPlayerNum() << " is the winner!!!" << std::endl;
                        break;
                    } else if (nextPos >= 29) { // If only moves, does this and wins the game
                        std::cout << "|Turn|Player|Tile|Dice|Type|EndUp|" << std::endl;
                        std::cout << "| " << turn+1 << " |  " << currPlayer->getPlayerNum() << "  | " << currPlayer->getPos()+1 << " |  " << D.getDiceVal() << " | N | " <<  "30 |" << std::endl;
                        std::cout << "Player " << currPlayer->getPlayerNum() << " is the winner!!!" << std::endl;
                        break;
                    }

                    /* Show result */
                    std::cout << "|Turn|Player|Tile|Dice|Type|EndUp|" << std::endl;
                    std::cout << "| " << turn+1 << "  |  " << currPlayer->getPlayerNum() << "  |  " << currPlayer->getPos()+1 << " |  " << D.getDiceVal() << " |  " << type << "  |  " << finalPos+1 << "  |" << std::endl;
                    std::cout << "--------------------------------------------" << std::endl;

                    // Update player position, swap to the next player and update the turn
                    currPlayer->setNewPos(finalPos);
                    turn++;

                    if (turn >= turns) {
                        std::cout << "-- GAME OVER --" << std::endl;
                        std::cout << "The maximum number of turns, which is " << turn << ", has been reached..." << std::endl;
                        break;
                    }

                } else if (input == "E") {
                    std::cout << "-- GAME OVER --" << std::endl;
                    std::cout << "Thanks for playing!!!" << std::endl;
                    break;
                } else {
                    throw 404;
                }
            }
            catch (...) {
                std::cout << "Invalid option, please press C to continue next turn or E to end the game" << std::endl;
            }
        }
    }
};

int main()
{
     MyGame G;
     G.start();
     return 0;
}