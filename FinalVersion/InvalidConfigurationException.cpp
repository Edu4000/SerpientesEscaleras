#include <iostream>
#include <exception>

using namespace std;

class InvalidConfigurationException: public exception {
    private:
        std::string msj;
        int value;

    public:
        InvalidConfigurationException() {
            this->msj = "";
        }

        InvalidConfigurationException(std::string type, int value) {
            this->msj = "Invalid ";
            this->msj += type;
            this->msj += " value: ";
            this->msj +=  std::to_string(value);
        }

        virtual const char* what () const throw(){
            return msj.c_str();
        }
};