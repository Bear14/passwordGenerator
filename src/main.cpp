#include <iostream>
#include <random>


#include "Generator.h"

#define STD_NUMBER_OF_PASSWORDS 1
#define STD_PASSWORD_LENGTH 16

enum CommandlineOptions {
    c,
    l,
    add,
    rm,
};



CommandlineOptions resolve(const std::string& input){
    if(input == "-c") return c;
    if(input == "-l") return l;
    if(input == "-add") return add;
    if(input == "-rm") return rm;
    throw std::invalid_argument("not an option");
}



int main(int argc, char** argv) {

    int count = STD_NUMBER_OF_PASSWORDS;
    int length = STD_PASSWORD_LENGTH;

    std::vector<std::string> arguments(argv,argv + argc);
    arguments.erase(arguments.begin());


    auto * pass = new Generator();


    for(int i = 0; i < argc -1;i++){

        switch (resolve(arguments[i])){
            case c:
                i++;
                count = std::stoi(arguments[i]);
                break;
            case l:
                i++;
                length = std::stoi(arguments[i]);
                break;
            case add:
                i++;
                pass->placeSpecialCharacter(arguments[i]);
                break;
            case rm:
                i++;
                pass->clearSpecialCharacter(arguments[i]);
                break;
            default:
                std::cout << "Invalid argument." << std::endl;
                return 0;
        }

    }

    std::cout << "Alphabet:";
    pass->printAlphabet();
    std::cout << std::endl;

    pass->generatePasswords(count,length);
    return 0;
}