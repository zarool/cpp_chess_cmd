#include <iostream>
#include "board.h"

board board;

int main() {

    while (true) {
        std::string input;

        //print board
        board.setError(false);
        board.PrintBoard();
        board.PrintInfo();

        //get input
        printf("It's: %s turn!", board.GetTurn().c_str());
        printf("\nEnter your move: ");
        getline(std::cin, input);

        //validate input and make move
        if (board::CheckInput(input)) board.MakeMove(input);
        if (!board.isError()) board.NextTurn();

        //exit
        if (input == "exit" || input == "q") break;
        system("cls");
    }
    return 0;
}
