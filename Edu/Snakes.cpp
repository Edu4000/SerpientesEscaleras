#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Player.h"
#include "Tiles.h"

using namespace std;

class MyGame
{
    private:
        bool escape()
        {
            string input;
            while (true)
            {
                cout << "Press C to continue next turn, or E to end the game:" << endl;
                cin >> input;

                if (input == "C") 
                {
                    return false;
                }
                else if (input == "E") 
                {
                    return true;
                }
                else 
                {
                    cout << "Invalid option, please press C to continue next turn or E to end the game." << endl;
                }
            }
            return true;
        }

    public:
        void start()
        {
            
            // Setting up table
            Tiles table [30] = { Tiles() };
            // Pacing snakes and ladders
            srand(time(0));
            int ladders [3];
            int snakes [3];
            for (int i = 0; i < 3; i++)
            {
                int s;
                int l;
                s = rand() % 30;
                l = rand() % 30;

                table[s] = Tiles("S");
                table[l] = Tiles("L");
            }

            // Wellcome message and questions            
            cout << "Welcome to Snakes and Ladders" << endl;
            cout << "How many players will play?" << endl;
            int numberPLayers;
            cin >> numberPLayers;
            cout << "How many turns do you want?" << endl;
            int turns;
            cin >> turns;
            cout << "Enjoy!!!\n" << endl;

            // Creating Array of Players
            Player players [numberPLayers];
            for (int i = 0; i < numberPLayers; i++) 
            {
                players[i] = Player(i + 1);
            }

            // Local variables for utility
            int turn = 0;
            int active;
            int dice;
            int displacement;
            string input;

            // Game Initialization
            while (turn <= turns) 
            {
                // Get who will play
                active = turn % numberPLayers;
                
                // Rolling the dice
                dice = 1 + rand() % 6;

                // Printing Information
                // Turn
                cout << turn + 1 << " ";
                // Player Number and Position
                players[active].printPlayer();
                // Dice
                cout << " " << dice;

                // Checking for the winner
                if (players[active].getPosition() + dice >= 30)
                {
                    // Printing Information
                    // Type of Tile
                    cout << " " << table[30].getType();
                    // New Position
                    cout << " " << 30 << endl;

                    cout << "-- GAME OVER --" << endl;
                    cout << "Player " << active + 1 << " is the winner!!!" << endl;
                    break;
                }

                // Printing Information
                // Type of Tile
                cout << " " << table[ players[active].getPosition() + dice - 1].getType();
                // New Position
                displacement = dice + table[ players[active].getPosition() + dice - 1].getPenalty();
                players[active].move( displacement );
                cout << " " << players[active].getPosition() << endl;

                // Asking to continue or exit
                if (escape()) 
                {
                    cout << "-- GAME OVER --" << endl;
                    cout << "Thanks for playing!!!" << endl;
                    break;
                }

                // Changing turn
                turn++;
            }

            if (turn > turns) 
            {
                cout << "-- GAME OVER --" << endl;
                cout << "The maximum number of turns has been reached..." << endl;
            }

            for (Tiles pos : table) 
            {
                cout << pos.getType() << " ";
            }
        }
};

int main()
{
    MyGame g;
    g.start();
    return 0;
}