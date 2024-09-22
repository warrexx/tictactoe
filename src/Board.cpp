#include "Board.h"

Board::Board()
{
}

void Board::placeMark(char symbol, int row, int col)
{
    arrayBoard[row][col] = symbol;
}

char Board::getElementSymbol(int row, int col)
{
    return arrayBoard[row][col];
}