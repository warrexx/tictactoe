#include "Player.h"

Player::Player()
{
}

void Player::setName(std::string name)
{
    this->name = name;
}

std::string Player::getName()
{
    return name;
}

void Player::setSymbol(char symbol)
{
    this->symbol = symbol;
}

char Player::getSymbol()
{
    return symbol;
}
