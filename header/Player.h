#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
public:
    Player();

    void setName(std::string name);

    std::string getName();

    void setSymbol(char symbol);

    char getSymbol();

private:
    std::string name;
    char symbol;
};

#endif