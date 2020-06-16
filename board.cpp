#include "board.h"
#include "./pieces/Type.h"
#include <iostream>
#include <regex>
#include <string>
#include <windows.h>

board::board() {
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            if (y == (size - 2)) {
                BoardSet[x][y] = new Pawn('P', 0, x, y);
            } else if (y == (size - 1)) {
                if (x == 0 || x == (size - 1))
                    BoardSet[x][y] = new Rook('R', 0, x, y);
                else if (x == 1 || x == (size - 2)) {
                    BoardSet[x][y] = new Knight('N', 0, x, y);
                } else if (x == 2 || x == (size - 3)) {
                    BoardSet[x][y] = new Bishop('B', 0, x, y);
                } else if (x == 3) {
                    BoardSet[x][y] = new Queen('Q', 0, x, y);
                } else if (x == 4) {
                    BoardSet[x][y] = new King('K', 0, x, y);
                }
            } else if (y == 1) {
                BoardSet[x][y] = new Pawn('P', 1, x, y);
            } else if (y == 0) {
                if (x == 0 || x == (size - 1))
                    BoardSet[x][y] = new Rook('R', 1, x, y);
                else if (x == 1 || x == (size - 2)) {
                    BoardSet[x][y] = new Knight('N', 1, x, y);
                } else if (x == 2 || x == (size - 3)) {
                    BoardSet[x][y] = new Bishop('B', 1, x, y);
                } else if (x == 3) {
                    BoardSet[x][y] = new Queen('Q', 1, x, y);
                } else if (x == 4) {
                    BoardSet[x][y] = new King('K', 1, x, y);
                }
            }
        }
    }
}

void board::PrintBoard() const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int max = size * 2;
    int x = 0;
    int y = 0;

    printf("     A   B   C   D   E   F   G   H  \n");
    //board
    for (int i = 0; i <= max; ++i) {
        if (i % 2 != 0) printf(" %d ", y + 1);
        else printf("  ");

        for (int j = 0; j <= max; j++) {
            if (!i) {
                //first row
                if (!j) printf(" %c", 218);
                else if (j == (max)) printf("%c", 191);
                else if (j % 2) printf("%c%c%c", 196, 196, 196);
                else if (!(j % 2)) printf("%c", 194);
            } else if (i == (max)) {
                //last row
                if (!j) printf(" %c", 192);
                else if (j == (max)) printf("%c", 217);
                else if (j % 2)printf("%c%c%c", 196, 196, 196);
                else if (!(j % 2)) printf("%c", 193);
            } else if (i % 2) {
                //2,4,6... row
                if (!(j % 2))
                    printf("%c", 179);
                else if (j % 2) {
                    //pieces
                    char current = ' ';
                    if (BoardSet[x][y] != nullptr) {
                        current = BoardSet[x][y]->GetName();
                        if (BoardSet[x][y]->GetColor() == 1) SetConsoleTextAttribute(hConsole, 4);
                    }
                    printf(" %c ", current);
                    x++;
                    SetConsoleTextAttribute(hConsole, 15);
                }
            } else if (!(i % 2)) {
                //1,3,5... row
                if (!j) printf(" %c", 195);
                else if (j == (max)) printf("%c", 180);
                else if (j % 2) printf("%c%c%c", 196, 196, 196);
                else if (!(j % 2)) printf("%c", 197);
            }
        }
        x = 0;

        if (i % 2 != 0) {
            printf(" %d", y + 1);
            ++y;
        } else printf(" ");
        printf("\n");
    }
    printf("     A   B   C   D   E   F   G   H  \n");
}


bool board::CheckInput(std::string input) {
    std::regex regex("^[prbnqkPRBNQK][a-hA-H][1-8]+$");

    std::smatch matches;
    while (std::regex_search(input, matches, regex)) {
        if (matches.ready()) return true;

        input = matches.suffix().str();
    }

    return false;
}

void board::MakeMove(std::string input) {
    char piece = input[0];

    int x = 0;
    if (islower(input[1])) x = (int) input[1] - 97;
    else if (isupper(input[1])) x = (int) input[1] - 65;

    int y = (int) (input[2]) - 49;

    std::ostringstream oss;
    oss << "Column: " << x << " and row: " << y;
    this->info = oss.str();

    error = false;

    bool stop = false;
    for (int j = 0; j < size && !stop; ++j) {
        for (int i = 0; i < size && !stop; ++i) {
            if (BoardSet[i][j] != nullptr &&
                toupper(piece) == int(BoardSet[i][j]->GetName()) &&
                BoardSet[i][j]->GetColor() == turn) {

                if (!BoardSet[i][j]->makeMove(x, y, BoardSet)) {
                    stop = true;
                    error = false;
                } else {
                    std::cout << "get there at: " << i << " and " << j << "\n";
                    error = true;
                }
            }
        }
    }
}


void board::PrintInfo() {
    std::cout << info << "\n";
}

void board::PrintError() const {
    std::cout << "Error: " << error << "\n";
}

