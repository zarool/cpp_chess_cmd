#ifndef CHESS_CMD_TYPE_H
#define CHESS_CMD_TYPE_H

#include "../Piece.h"

class Pawn : public Piece {
public:
    Pawn(char name, int col, int x, int y) : Piece(name, col, x, y) {};

    bool makeMove(int inputX, int inputY, Piece *[8][8]) override;
};

class King : public Piece {

public:
    King(char name, int col, int x, int y) : Piece(name, col, x, y) {};

    bool makeMove(int inputX, int inputY, Piece *[8][8]) override;
};

class Queen : public Piece {

public:
    Queen(char name, int col, int x, int y) : Piece(name, col, x, y) {};

    bool makeMove(int inputX, int inputY, Piece *[8][8]) override;
};

class Bishop : public Piece {

public:
    Bishop(char name, int col, int x, int y) : Piece(name, col, x, y) {};

    bool makeMove(int inputX, int inputY, Piece *[8][8]) override;
};

class Rook : public Piece {

public:
    Rook(char name, int col, int x, int y) : Piece(name, col, x, y) {};

    bool makeMove(int inputX, int inputY, Piece *[8][8]) override;
};

class Knight : public Piece {

public:
    Knight(char name, int col, int x, int y) : Piece(name, col, x, y) {};

    bool makeMove(int inputX, int inputY, Piece *[8][8]) override;
};


#endif //CHESS_CMD_TYPE_H
