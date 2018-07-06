//
// Created by torbe on 10-May-18.
//


#include "Generator.h"
#include <ctime>
#include <ctime>
#include <random>
#include <algorithm>
#include <sstream>
#include <iostream>

void Generator::buildAlphabet() {
    this->alphabet.clear();
    this->alphabet.reserve(
            this->upperCase.size() + this->lowerCase.size() + this->numbers.size() + this->special.size());
    this->alphabet.insert(this->alphabet.end(), this->upperCase.begin(), this->upperCase.end());
    this->alphabet.insert(this->alphabet.end(), this->lowerCase.begin(), this->lowerCase.end());
    this->alphabet.insert(this->alphabet.end(), this->numbers.begin(), this->numbers.end());
    this->alphabet.insert(this->alphabet.end(), this->special.begin(), this->special.end());
}

void Generator::printSpecial() {        //just for debugging
    std::cout << "(  ";
    for (const auto &i : this->special) {
        std::cout << i << ",";
    }
    std::cout << "  )\n";
}

void Generator::printAlphabet() {
    this->buildAlphabet();
    std::cout << "[  ";
    for (const auto &i : this->alphabet) {
        std::cout << i << ",";
    }
    std::cout << "  ]\n";

}


void Generator::placeSpecialCharacter(std::string character) {
    std::vector<char> toPlaceChars(character.begin(), character.end());

    /*
     * Check input for multiple occurrences of characters
     */

    for (int j = 0; j < toPlaceChars.size(); ++j) {
        for (int h = 0; h < toPlaceChars.size(); ++h) {
            if (toPlaceChars[j] == toPlaceChars[h] && j != h) {
                std::cout << "Character \'" << toPlaceChars[j]
                          << "\' occurs multiple times in the input. Multiples got deleted." << std::endl;
                toPlaceChars.erase(toPlaceChars.begin() + h);
            }
        }

    }

    /*
     * Check for double inclusion of characters
     */

    this->buildAlphabet();
    std::string buff;
    for (const auto &k : this->alphabet) {
        for (int i = 0; i < toPlaceChars.size(); ++i) {
            buff = toPlaceChars[i];
            if (k == buff) {
                toPlaceChars.erase(toPlaceChars.begin() + i);
                std::cout << "Character \'" << buff << "\' already in the alphabet." << std::endl;
            }
        }
    }

    /*
     * Place character
     */

    std::string buffer;
    for (char toPlaceChar : toPlaceChars) {
        buffer = toPlaceChar;
        this->special.push_back(buffer);
    }
    /*
     * Sort special
     */

    std::sort(this->special.begin(), this->special.end());


}

void Generator::clearSpecialCharacter(std::string character) {

    std::vector<char> toDelChars(character.begin(), character.end());
    std::sort(toDelChars.begin(), toDelChars.end());

    for (int i = 0; i < this->special.size(); ++i) {
        if (this->special[i][0] == toDelChars.front()) {
            this->special.erase(this->special.begin() + i);
            if (i != 0) { i--; }
            toDelChars.erase(toDelChars.begin());
        }


    }
    if (!toDelChars.empty()) {

        std::cout << "Error: Characters: ";
        for (char toDelChar : toDelChars) {
            std::cout << toDelChar << ", ";
        }
        std::cout << "are invalid special characters.\n";

    }
    this->buildAlphabet();
}


std::string Generator::generatePasswords(unsigned int count, unsigned int length) {
    this->buildAlphabet();
    std::vector<std::string> passwordList;
    std::random_device rd;
    for (int i = 0; i < count; ++i) {
        std::string buffer;
        for (int j = 0; j < length; ++j) {
            buffer += this->alphabet[rd() % this->alphabet.size()];

        }
        passwordList.push_back(buffer);

    }

    for (const auto &k : passwordList) {
        std::cout << k << std::endl;
    }
    passwordList.clear();
}