#include <iostream>
#include <random>


#include "Generator.h"



int main(int argc, char** argv) {

    if(argc > 3){
        std::cout << "Wrong number of arguments. Should be 2." << std::endl;
        return 0;
    }
    int count = std::stoi(argv[1]);
    int length = std::stoi(argv[2]);
    auto * pass = new Generator();




    std::cout << "Alphabet:";
    pass->printAlphabet();
    std::cout << std::endl;

    pass->generatePasswords(count,length);
    return 0;
}