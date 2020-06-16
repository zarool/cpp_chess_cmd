#include "Type.h"


//pawn
bool Pawn::makeMove(int inputX, int inputY, Piece *board[8][8]) {
    bool stateOne = abs(inputY - pieceY) == 1;
    if (inputX == pieceX) {
        bool makeTwoWhite = (color == 0 && pieceY == 6 && abs(inputY - pieceY) == 2);
        bool makeTwoBlack = (color == 1 && pieceY == 1 && abs(inputY - pieceY) == 2);
        if ((stateOne || makeTwoWhite || makeTwoBlack) && board[inputX][inputY] == nullptr) {
            board[inputX][inputY] = new Pawn('P', color, inputX, inputY);
            board[pieceX][pieceY] = nullptr;
            return false;
        }
    } else if ((inputX == pieceX - 1 || inputX == pieceX + 1) && stateOne) {
        if (board[inputX][inputY] != nullptr && board[inputX][inputY]->GetColor() != color) {
            board[inputX][inputY] = new Pawn('P', color, inputX, inputY);
            board[pieceX][pieceY] = nullptr;
            return false;
        }
    }
    return true;
}

//king
bool King::makeMove(int inputX, int inputY, Piece *board[8][8]) {
    bool move = abs(inputX - pieceX) <= 1 && abs(inputY - pieceY) <= 1;
    bool isFree = board[inputX][inputY] == nullptr;
    bool isEnemy = board[inputX][inputY] != nullptr && board[inputX][inputY]->GetColor() != color;

    if (move && (isFree || isEnemy)) {
        board[inputX][inputY] = new King('K', color, inputX, inputY);
        board[pieceX][pieceY] = nullptr;
        return false;
    }
    return true;
}

//queen
bool Queen::makeMove(int inputX, int inputY, Piece *board[8][8]) {
    int lengthX = abs(inputX - pieceX);
    int lengthY = abs(inputY - pieceY);
    bool moveCross = lengthX == lengthY;
    bool moveVertical = (inputX == pieceX && inputY != pieceY);
    bool moveHorizontal = (inputY == pieceY && inputX != pieceX);
    bool move = (moveVertical || moveHorizontal || moveCross);

    bool isFree = false;
    bool isEnemy = false;

    if (moveCross && !moveVertical && !moveHorizontal) {
        int dirX = (inputX - pieceX > 0) ? 1 : -1;
        int dirY = (inputY - pieceY > 0) ? 1 : -1;
        for (int i = 0; i < lengthX; ++i) {
            if (board[i + (pieceX + dirX)][i + (pieceY + dirY)] != nullptr) {
                if (board[i + (pieceX + dirX)][i + (pieceY + dirY)] == board[inputX][inputY] &&
                    board[inputX][inputY]->GetColor() != color) {
                    isFree = true;
                    isEnemy = true;
                } else {
                    break;
                }
            } else isFree = true;
        }
    } else if (moveHorizontal && !moveCross && !moveVertical) {
        int length = abs(inputX - pieceX);
        int dir = (inputX - pieceX > 0) ? 1 : -1;
        for (int i = 0; i < length; ++i) {
            if (board[i + (pieceX + dir)][inputY] != nullptr) {
                if (board[i + (pieceX + dir)][inputY] == board[inputX][inputY] &&
                    board[inputX][inputY]->GetColor() != color) {
                    isFree = true;
                    isEnemy = true;
                } else {
                    break;
                }
            } else isFree = true;
        }
    } else if (moveVertical && !moveCross && !moveHorizontal) {
        int length = abs(inputY - pieceY);
        int dir = (inputY - pieceY > 0) ? 1 : -1;
        for (int i = 0; i < length; ++i) {
            if (board[inputX][i + (pieceY + dir)] != nullptr) {
                if (board[inputX][i + (pieceY + dir)] == board[inputX][inputY] &&
                    board[inputX][inputY]->GetColor() != color) {
                    isFree = true;
                    isEnemy = true;
                } else {
                    break;
                }
            } else isFree = true;
        }
    }


    if (move && (isFree || isEnemy)) {
        board[inputX][inputY] = new Queen('Q', color, inputX, inputY);
        board[pieceX][pieceY] = nullptr;
        return false;
    }
    return true;
}

///bishop
bool Bishop::makeMove(int inputX, int inputY, Piece *board[8][8]) {
    int lengthX = abs(inputX - pieceX);
    int lengthY = abs(inputY - pieceY);
    bool move = lengthX == lengthY;
    bool isFree = false;
    bool isEnemy = false;

    int dirX = (inputX - pieceX > 0) ? 1 : -1;
    int dirY = (inputY - pieceY > 0) ? 1 : -1;
    for (int i = 0; i < lengthX; ++i) {
        if (board[i + (pieceX + dirX)][i + (pieceY + dirY)] != nullptr) {
            if (board[i + (pieceX + dirX)][i + (pieceY + dirY)] == board[inputX][inputY] &&
                board[inputX][inputY]->GetColor() != color) {
                isFree = true;
                isEnemy = true;
            } else {
                break;
            }
        } else isFree = true;
    }
    if (move && (isFree || isEnemy)) {
        board[inputX][inputY] = new Bishop('B', color, inputX, inputY);
        board[pieceX][pieceY] = nullptr;
        return false;
    }
    return true;
}

///rook

bool Rook::makeMove(int inputX, int inputY, Piece *board[8][8]) {
    bool moveVertical = (inputX == pieceX && inputY != pieceY);
    bool moveHorizontal = (inputY == pieceY && inputX != pieceX);
    bool move = moveVertical || moveHorizontal;
    bool isFree = false;
    bool isEnemy = false;


    if (moveVertical) {
        int length = abs(inputY - pieceY);
        int dir = (inputY - pieceY > 0) ? 1 : -1;
        for (int i = 0; i < length; ++i) {
            if (board[inputX][i + (pieceY + dir)] != nullptr) {
                if (board[inputX][i + (pieceY + dir)] == board[inputX][inputY] &&
                    board[inputX][inputY]->GetColor() != color) {
                    isFree = true;
                    isEnemy = true;
                } else {
                    break;
                }
            } else isFree = true;
        }
    } else if (moveHorizontal) {
        int length = abs(inputX - pieceX);
        int dir = (inputX - pieceX > 0) ? 1 : -1;
        for (int i = 0; i < length; ++i) {
            if (board[i + (pieceX + dir)][inputY] != nullptr) {
                if (board[i + (pieceX + dir)][inputY] == board[inputX][inputY] &&
                    board[inputX][inputY]->GetColor() != color) {
                    isFree = true;
                    isEnemy = true;
                } else {
                    break;
                }
            } else isFree = true;
        }
    }
    if (move && (isFree || isEnemy)) {
        board[inputX][inputY] = new Rook('R', color, inputX, inputY);
        board[pieceX][pieceY] = nullptr;
        return false;
    }
    return true;
}

///knight

bool Knight::makeMove(int inputX, int inputY, Piece *board[8][8]) {
    int movesX[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    int movesY[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; ++i) {
        int x = pieceX + movesX[i];
        int y = pieceY + movesY[i];

        bool isMove = (inputX == x && inputY == y);
        bool isFree = board[inputX][inputY] == nullptr;
        bool isEnemy = board[inputX][inputY] != nullptr && board[inputX][inputY]->GetColor() != color;

        if (isMove && (isFree || isEnemy)) {
            board[inputX][inputY] = new Knight('N', color, inputX, inputY);
            board[pieceX][pieceY] = nullptr;
            return false;
        }
    }
    return true;
}