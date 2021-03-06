#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <algorithm>
#include <vector>
#include <chrono>
#include "InvalidConfigurationException.cpp"
#include "InvalidOptionException.cpp"
#include "Tiles.h"
#include "Turn.h"
#include "Dice.h"
#include "Player.h"
#include "ctime"

class MyGame {
private:
    bool hasNumber(std::vector<int> specialCase, int num)
    {
        for (int i : specialCase)
        {
            if (i == num)
            {
                return true;
            }
        }
        return false;
    }

public:
    void start() {
        std::string playMode;
        int numberPlayers;int turns;int tiles;int snakes;int ladders;int penalties;int rewards;
        // Welcome message and questions
        std::cout << "Welcome to Snakes and Ladders" << std::endl;

        std::cout << "How many players will play?" << std::endl;
        while (!(std::cin >> numberPlayers)) {
        std::cout << "Please introduce a number" << std::endl;
        std::cin.clear();
        std::cin.ignore(100, '\n');
        }
        if (numberPlayers < 2) {
            throw InvalidConfigurationException("numberPlayers", numberPlayers);
        }

        std::cout << "How many turns do you want?" << std::endl;
        while (!(std::cin >> turns)) {
            std::cout << "Please introduce a number" << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        if (turns < numberPlayers) {
            throw InvalidConfigurationException("turns", turns);
        }

        std::cout << "How many tiles in the board should they be?" << std::endl;
        while (!(std::cin >> tiles)) {
            std::cout << "Please introduce a number" << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        if (tiles < 10) {
            throw InvalidConfigurationException("tiles", tiles);
        }

        std::cout << "How many snakes in the board should they be?" << std::endl;
        while (!(std::cin >> snakes)) {
            std::cout << "Please introduce a number" << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        if (snakes < 1) {
            throw InvalidConfigurationException("snakes", snakes);
        }

        std::cout << "How many ladders in the board should they be?" << std::endl;
        while (!(std::cin >> ladders)) {
            std::cout << "Please introduce a number" << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        if (ladders < 1) {
            throw InvalidConfigurationException("ladders", ladders);
        }

        std::cout << "What is the penalty for snake tiles?" << std::endl;
        while (!(std::cin >> penalties)) {
            std::cout << "Please introduce a number" << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        if (penalties < 1) {
            throw InvalidConfigurationException("penalties", penalties);
        }

        std::cout << "What is the reward for ladder tiles?" << std::endl;
        while (!(std::cin >> rewards)) {
            std::cout << "Please introduce a number" << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
        }
        if (rewards < 1) {
            throw InvalidConfigurationException("rewards", rewards);
        }

        std::cout << "Will you upload a play file or will you play? Play File | A ; Play | M" << std::endl;
        while (true) {


            while (!(std::cin >> playMode)) {
                std::cout << "Please introduce either A or M" << std::endl;
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }

            if (playMode == "M") {
                std::cout << "Enjoy!!!\n" << std::endl;
                playInConsole(numberPlayers, turns, tiles, snakes, ladders, penalties, rewards);
                break;
            }

            if (playMode == "A") {
                std::string path;
                std::cout << "Input file name: " << std::endl;
                std::cin >> path;
                std::cout << "Enjoy!!!\n" << std::endl;
                playFromFile(path, numberPlayers, turns, tiles, snakes, ladders, penalties, rewards);
                break;
            }
            std::cout << "Please introduce either A or M" << std::endl;
        }
    }

    void playInConsole(int numberPlayers, int turns, int tiles, int snakes, int ladders, int penalties, int rewards) {
        // Generating Game Elements
        srand(time(0));
        Tiles board[tiles]; // board[0] is tile[1]
        Dice D = Dice();
        Player * currPlayer;
        Turn turn = Turn();

        if (snakes + ladders >= tiles) {
            std::cout << "Error: there cannot neither more snakes, ladder,or both type of tiles than the total number of tiles" << std::endl;
            exit(EXIT_FAILURE);
        }

        std::vector<int> specialCases;
        int index;

        // Getting index for Snakes
        while (specialCases.size() != snakes) {
            index = 1 + rand() % tiles;
            if(!hasNumber(specialCases, index)) {
                specialCases.push_back(index);
                board[index] = Tiles("S",index,rewards,penalties);
            }
        }
        // Getting index for Tiles
        while (specialCases.size() != (snakes+ladders)) {
            index = 1 + (rand() % tiles);
            if(!hasNumber(specialCases, index)) {
                specialCases.push_back(index);
                board[index] = Tiles("L",index,rewards,penalties);
            }
        }

        /* Start of the game */
        std::cout << "Press C to continue next turn, or E to end the game: " << std::endl;

        // Creating Array of Players
        Player players [numberPlayers];
        for (int i = 0; i < numberPlayers; i++)
        {
            players[i] = Player(i + 1);
        }

        // While loop
        std::string input;
        int menuChoice = 0;

        while (true) {
            std::cin >> input;
            try {
                if (input == "C") {
                    // rest of the code
                    currPlayer = &players[turn.getTurn() % numberPlayers];

                    /* Roll dice and find new positions for the player */
                    D.rollDice();
                    // Next absolute position given the player's absolute position plus the dice
                    int nextPos = currPlayer->getPos() + (D + board[currPlayer->getPos() + D.getDiceVal()]).getDiceVal(); // Sobrecarga de +
                    std::string type = board[currPlayer->getPos() + D.getDiceVal()].getTileType();
                    turn.setDice(D);
                    turn.setPlayer(*currPlayer);
                    turn.setTiles(board[currPlayer->getPos() + D.getDiceVal()]);

                    // If player exceeds maximun number of tiles
                    if (nextPos >= tiles-1) {
                        turn.setNextPos(tiles);
                        std::cout << turn;
                        break;
                    }

                    /* Show result */
                    turn.setNextPos(nextPos);
                    std::cout << turn;

                    // Update player position, swap to the next player and update the turn
                    currPlayer->setNewPos(nextPos);
                    turn.nextTurn();

                    if (turn.getTurn() >= turns) {
                        std::cout << "-- GAME OVER --" << std::endl;
                        std::cout << "The maximum number of turns, which is " << turn.getTurn() << ", has been reached..." << std::endl;
                        break;
                    }

                } else if (input == "E") {
                    std::cout << "-- GAME OVER --" << std::endl;
                    std::cout << "Thanks for playing!!!" << std::endl;
                    break;
                } else {
                    menuChoice++;
                    if (menuChoice > 5) {
                        throw InvalidOptionException(1);
                    }
                    throw InvalidOptionException(0);
                }
            }            
            catch (InvalidOptionException &msj) {
                if (msj.getValue() == 0) {
                    std::cout << msj.what() << std::endl;
                } else {
                    std::cout << msj.what() << std::endl;
                    break;
                }
            }
            catch (const char *msj) {
                std::cout << msj << std::endl;
            }
        }
    }

    void playFromFile(std::string path, int numberPlayers, int turns, int tiles, int snakes, int ladders, int penalties, int rewards) {
        std::ifstream file;
        std::string line;
        file.open(path);

        // Generating Game Elements
        Tiles board[30]; // board[0] is tile[1]
        std::srand(time(0));
        Dice D = Dice();
        Player * currPlayer;
        Turn turn = Turn();

        if (snakes + ladders >= tiles) {
            std::cout << "Error: there cannot neither more snakes, ladder,or both type of tiles than the total number of tiles" << std::endl;
            exit(EXIT_FAILURE);
        }

        std::vector<int> specialCases;
        int index;

        // Getting index for Snakes
        while (specialCases.size() != snakes) {
            index = 1 + rand() % tiles;
            if(!hasNumber(specialCases, index)) {
                specialCases.push_back(index);
                board[index] = Tiles("S",index,rewards,penalties);
            }
        }
        // Getting index for Tiles
        while (specialCases.size() != (snakes+ladders)) {
            index = 1 + (rand() % tiles);
            if(!hasNumber(specialCases, index)) {
                specialCases.push_back(index);
                board[index] = Tiles("L",index,rewards,penalties);
            }
        }

        std::cout << line << std::endl;

        getline(file, line);
        numberPlayers = std::stoi(line);
        if (numberPlayers < 0) {
            std::cout << "Error: check if the file format is correct!" << std::endl;
            exit(EXIT_FAILURE);
        }

        getline(file, line);
        turns = std::stoi(line);
        if (turns < 0) {
            std::cout << "Error: check if the file format is correct!" << std::endl;
            exit(EXIT_FAILURE);
        }

        /* Start of the game */

        // Creating Array of Players
        Player players [numberPlayers];
        for (int i = 0; i < numberPlayers; i++)
        {
            players[i] = Player(i + 1);
        }

        // While loop
        while (true) {
            getline(file, line);
            try {
                if (line == "C") {
                    // rest of the code
                    currPlayer = &players[turn.getTurn() % numberPlayers];

                    /* Roll dice and find new positions for the player */
                    D.rollDice();
                    // Next absolute position given the player's absolute position plus the dice
                    int nextPos = currPlayer->getPos() + (D + board[currPlayer->getPos() + D.getDiceVal()]).getDiceVal(); // Sobrecarga de +
                    std::string type = board[currPlayer->getPos() + D.getDiceVal()].getTileType();
                    turn.setDice(D);
                    turn.setPlayer(*currPlayer);
                    turn.setTiles(board[currPlayer->getPos() + D.getDiceVal()]);

                    // If player exceeds maximun number of tiles
                    if (nextPos >= tiles-1) {
                        turn.setNextPos(tiles);
                        std::cout << turn;
                        break;
                    }

                    /* Show result */
                    turn.setNextPos(nextPos);
                    std::cout << turn;

                    // Update player position, swap to the next player and update the turn
                    currPlayer->setNewPos(nextPos);
                    turn.nextTurn();

                    if (turn.getTurn() >= turns) {
                        std::cout << "-- GAME OVER --" << std::endl;
                        std::cout << "The maximum number of turns, which is " << turn.getTurn() << ", has been reached..." << std::endl;
                        break;
                    }

                } else if (line == "E") {
                    std::cout << "-- GAME OVER --" << std::endl;
                    std::cout << "Thanks for playing!!!" << std::endl;
                    break;
                } else {
                    throw 404;
                }
            }
            catch (...) {
                std::cout << "Error: check if the file format is correct!" << std::endl;
                exit(EXIT_FAILURE);
            }
            line = "";
        }
    }
};

int main()
{
    MyGame G;
    try {
        G.start();
    } catch (InvalidConfigurationException &msj) {
        cout << msj.what() << endl;
        return 1;
    }
    return 0;
}
