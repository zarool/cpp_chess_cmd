

#ifndef CHESS_CMD_BOARD_H
#define CHESS_CMD_BOARD_H

#include <vector>
#include "Piece.h"

class board {
private:
    //0 = white, 1 = black
    int turn = 0;
    int enemy = 1;
    bool error = false;
    int const size = 8;
    Piece *BoardSet[8][8];
    std::string info = "";

public:
    void PrintBoard() const;

    void PrintInfo();

    void NextTurn() {
        this->turn = 1 - this->turn;
        this->enemy = 1 - this->enemy;
    }

    static bool CheckInput(std::string);

    void MakeMove(std::string);

    void PrintError() const;

    void setError(bool s) { error = s; }

    bool isError() const { return error; }

    std::string GetTurn() const { return (this->turn == 0) ? "white" : "black"; };

    board();
};


#endif //CHESS_CMD_BOARD_H
