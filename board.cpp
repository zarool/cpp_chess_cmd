#include "board.h"
#include <iostream>

board::board() {
    for (int y = 0; y < size; ++y) {
        for (int x = 0; x < size; ++x) {
            BoardSet.push_back(Piece());
        }
    }
}

void board::PrintBoard() {
    /*
 *
 * (218)(196)(194)(196)(191)
 * (179) (32)(179) (32)(179)
 * (195)(196)(197)(196)(180)
 * (179) (32)(179) (32)(179)
 * (192)(196)(193)(196)(217)
 */
    int max = size * 2;
    int x = 0;
    int y = 0;

    //first row
    for (int letter = 0; letter < size; ++letter) {
        std::cout << " " << letters[letter] << " ";
    }
    std::cout << "\n";
    //board
    for (int i = 0; i < max; ++i) {
        if (i % 2 != 0) printf("%d ", y + 1);
        else printf(" ");

        for (int j = 0; j < max; j++) {
            if (!i) {
                if (!j) printf("%c", 218);
                else if (j == (max - 1)) printf("%c", 191);
                else if (j % 2) printf("%c%c%c", 196, 196, 196);
                else if (!(j % 2)) printf("%c", 194);
            } else if (i == (max - 1)) {
                if (!j) printf("%c", 192);
                else if (j == (max - 1)) printf("%c", 217);
                else if (j % 2)printf("%c%c%c", 196, 196, 196);
                else if (!(j % 2)) printf("%c", 193);
            } else if (i % 2) {
                if (!(j % 2)) printf("%c", 179);
                else if (j % 2) printf(" X ");
            } else if (!(i % 2)) {
                if (!j) printf("%c", 195);
                else if (j == (max - 1)) printf("%c", 180);
                else if (j % 2) printf("%c%c%c", 196, 196, 196);
                else if (!(j % 2)) printf("%c", 197);
            }
        }

        if (i % 2 != 0) {
            printf("%d ", y + 1);
            ++y;
        } else printf(" ");
        printf("\n");
    }
    printf("\n");
}

/*    a     b
 * #############
 * #     #     #
 * #  K  #  Q  #
 * #     #     #
 * #############
 *
 */
