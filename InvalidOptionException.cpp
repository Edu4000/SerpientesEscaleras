#include <iostream>
#include <exception>

using namespace std;

class InvalidOptionException: public exception {
    private:
        std::string msj;
        int value;

    public:
        InvalidOptionException(int v) {
            if (v == 0) {
                this->msj = "Invalid option, please press C to continue next turn or E to end the game.";
                value = v;
            } else {
                this->msj = "Invalid menu choice exceeded.";
                value = v;
            }
        }

        virtual const char* what () const throw(){
            return msj.c_str();
        }

        int getValue() {
            return value;
        }
};