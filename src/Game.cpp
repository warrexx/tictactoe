#include "Game.h"

Game::Game() {}

void Game::startGame()
{
    std::string name;
    char symbol;
    std::cout << "Player 1, please set your name: ";
    std::cin >> name;
    std::cout << "Okay " << name << ", please set your symbol: ";
    std::cin >> symbol;
    player_1.setName(name);
    player_1.setSymbol(symbol);

    std::cout << "Player 2, please set your name: ";
    std::cin >> name;
    std::cout << "Okay " << name << ", please set your symbol: ";
    std::cin >> symbol;
    player_2.setName(name);
    player_2.setSymbol(symbol);

    currentPlayer = &player_1;

    while (true)
    {
        board.printBoard();
        int position;
        std::cout << currentPlayer->getName() << ", choose position (1-9): ";
        std::cin >> position;

        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        board.placeMark(currentPlayer->getSymbol(), row, col);

        if (checkWin() || checkTie())
        {
            break;
        }

        changePlayer();
    }
    std::cout << "The winner is " << currentPlayer->getName() << "\n";
}

bool Game::checkWin()
{
    for (int row = 0; row < 3; row++)
    {
        if (checkRow(row))
        {
            return true;
        };
    }
    for (int col = 0; col < 3; col++)
    {
        if (checkCol(col))
        {
            return true;
        };
    }

    return checkDiagonal();
}

bool Game::checkRow(int row)
{
    char symbol = currentPlayer->getSymbol();
    for (int col = 0; col < 3; col++)
    {
        if (board.getElementSymbol(row, col) != symbol)
        {
            return false;
        }
    }
    return true;
}

bool Game::checkCol(int col)
{
    char symbol = currentPlayer->getSymbol();
    for (int row = 0; row < 3; row++)
    {
        if (board.getElementSymbol(row, col) != symbol)
        {
            return false;
        }
    }
    return true;
}

bool Game::checkDiagonal()
{
    char symbol = currentPlayer->getSymbol();

    if (
        board.getElementSymbol(0, 0) == symbol &&
        board.getElementSymbol(1, 1) == symbol &&
        board.getElementSymbol(2, 2) == symbol)
    {
        return true;
    }

    if (
        board.getElementSymbol(0, 2) == symbol &&
        board.getElementSymbol(1, 1) == symbol &&
        board.getElementSymbol(2, 0) == symbol)
    {
        return true;
    }
    return false;
}

bool Game::checkTie()
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (board.getElementSymbol(row, col) == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

void Game::changePlayer()
{
    currentPlayer = currentPlayer->getName() == player_1.getName() ? &player_2 : &player_1;
}