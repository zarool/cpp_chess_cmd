

#ifndef CHESS_CMD_BOARD_H
#define CHESS_CMD_BOARD_H

#include <vector>
#include "Piece.h"

class board {
private:
    int const size = 8;
    char letters[8] {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    std::vector<Piece> BoardSet;

public:
    void PrintBoard();
    board();
};


#endif //CHESS_CMD_BOARD_H
