#include <iostream>
#include <ctime>
#include <random>


#include "Generator.h"



int main() {

    auto * pass = new Generator();
    pass->generatePasswords(25,50);
    return 0;
}