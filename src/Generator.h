//
// Created by torbe on 10-May-18.
//

#ifndef PASSWORDGENERATOR_GENERATOR_H
#define PASSWORDGENERATOR_GENERATOR_H

#include <array>
#include <vector>

class Generator {
   private:
    std::vector<std::string> alphabet;

    const std::array<std::string, 26> lowerCase = {{"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n",
                                                    "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"}};
    const std::array<std::string, 26> upperCase = {{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
                                                    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"}};
    const std::array<std::string, 10> numbers = {{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}};
    std::vector<std::string> special = {{std::string(
                                             "!"),
                                         "#", "$", "%", "&", "(", ")", "*", "+", "-", ".", "/", ":", ";", "<", "=", ">", "?", "@", "[", "]", "^", "_", "`", "{", "|", "}", "~"}};

    void buildAlphabet();

   public:
    void printSpecial();
    void printAlphabet();

    void placeSpecialCharacter(std::string character);
    void clearSpecialCharacter(std::string character);

    void generatePasswords(unsigned int count, unsigned int length);
};

#endif  //PASSWORDGENERATOR_GENERATOR_H
