#ifndef TIC_TAC_TOE_h
#define TIC_TAC_TOE_h

#include "Player.h"
#include "Board.h"

class Game
{
public:
    Game();
    void startGame();
    bool checkWin();
    bool checkRow(int row);
    bool checkCol(int col);
    bool checkDiagonal();
    bool checkTie();

private:
    Player player_1, player_2, *currentPlayer;
    Board board;

    void changePlayer();
};

#endif