#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

/* Define the exception here */
class BadLengthException: public exception
{
    public:
    char* n;

    BadLengthException(int a){
        if (a == 0){
            char* temp = "0";
            n = temp;
        }
        else if (a == 1){
            char* temp = "1";
            n = temp;
        }
        else if (a == 2){
            char* temp = "2";
            n = temp;
        }
        else if (a == 3){
            char* temp = "3";
            n = temp;
        }
        if (a == 4){
            char* temp = "4";
            n = temp;
        }
    }

    virtual const char* what() const throw() {
        return n;
    }
};
