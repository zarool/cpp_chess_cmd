#ifndef CHESS_CMD_PIECE_H
#define CHESS_CMD_PIECE_H

#include <iostream>

class Piece {
protected:
    char name;
    int color;
    int pieceX;
    int pieceY;

public:
    Piece(char n, int c, int x, int y) {
        this->name = n;
        this->color = c;
        this->pieceX = x;
        this->pieceY = y;
    }

    virtual bool makeMove(int inputX, int inputY, Piece *[8][8]) = 0;

    char GetName() const { return this->name; };

    int GetColor() const { return this->color; }
};

#endif //CHESS_CMD_PIECE_H
