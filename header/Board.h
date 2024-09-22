#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board
{
public:
    Board();

    void placeMark(char symbol, int row, int col);

    char getElementSymbol(int row, int col);

    void printBoard()
    {
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                std::cout << " " << arrayBoard[row][col] << " ";
                if (col < 2)
                {
                    std::cout << "|";
                }
                else
                {
                    std::cout << "\n";
                }
            }
            if (row < 2)
            {
                std::cout << "---+---+---\n";
            }
        }
    }

private:
    char arrayBoard[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}};
};

#endif