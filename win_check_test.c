#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "check_win.h"

void reset_game_board(int **game_board, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            game_board[i][j] = 0;
        }
    }
}

int main() {
    // Creating the game board
    int rows = 6, columns = 7;

    int **game_board = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        game_board[i] = malloc(columns * sizeof(int));
    }

    // Initializing the game board with 0s
    reset_game_board(game_board, rows, columns);

    // -------------------------- VERTICAL TEST CASES --------------------------

    // Test Case 1

    /*
    int board[6][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0}
    };
    */
    game_board[0][3] = 1;
    game_board[1][3] = 1;
    game_board[2][3] = 1;
    game_board[3][3] = 1;

    bool win_vert = check_vertical(game_board, 3, 3);

    // Expecting true
    if (win_vert) {
        puts("Vertical Test Case 1 Success");
    } else {
        puts("Vertical Test Case 1 Failure");
    }

    reset_game_board(game_board, rows, columns);

    // Test Case 2

    /*
    int board[6][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 2, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0}
    };
    */
    game_board[0][3] = 1;
    game_board[1][3] = 2;
    game_board[2][3] = 1;
    game_board[3][3] = 1;

    win_vert = check_vertical(game_board, 3, 3);

    // Expecting false
    if (win_vert) {
        puts("Vertical Test Case 2 Failure");
    } else {
        puts("Vertical Test Case 2 Success");
    }

    reset_game_board(game_board, rows, columns);

    // Test Case 3

    /*
    int board[6][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0}
    };
    */
    game_board[0][3] = 1;
    game_board[1][3] = 1;
    game_board[2][3] = 1;

    win_vert = check_vertical(game_board, 2, 3);

    // Expecting false
    if (win_vert) {
        puts("Vertical Test Case 3 Failure");
    } else {
        puts("Vertical Test Case 3 Success");
    }

    reset_game_board(game_board, rows, columns);


    // -------------------------- HORIZONTAL TEST CASES --------------------------

    // Test Case 1

    /*
    int board[6][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 0, 0, 0}
    };
    */
    game_board[0][0] = 1;
    game_board[0][1] = 1;
    game_board[0][2] = 1;
    game_board[0][3] = 1;

    bool win_horiz = check_horizontal(game_board, 0, 1);
    
    // Expecting true
    if (win_horiz) {
        puts("Horizontal Test Case 1 Success");
    } else {
        puts("Horizontal Test Case 1 Failure");
    }

    reset_game_board(game_board, rows, columns);

    // Test Case 2

    /*
    int board[6][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {1, 1, 2, 1, 0, 0, 0}
    };
    */
    game_board[0][0] = 1;
    game_board[0][1] = 1;
    game_board[0][2] = 2;
    game_board[0][3] = 1;

    win_horiz = check_horizontal(game_board, 0, 1);
    
    // Expecting false
    if (win_horiz) {
        puts("Horizontal Test Case 2 Failure");
    } else {
        puts("Horizontal Test Case 2 Success");
    }

    reset_game_board(game_board, rows, columns);

    // Test Case 3

    /*
    int board[6][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 1, 0, 0}
    };
    */
    game_board[0][1] = 1;
    game_board[0][2] = 1;
    game_board[0][3] = 1;
    game_board[0][4] = 1;

    win_horiz = check_horizontal(game_board, 0, 3);
    
    // Expecting true
    if (win_horiz) {
        puts("Horizontal Test Case 3 Success");
    } else {
        puts("Horizontal Test Case 3 Failure");
    }

    reset_game_board(game_board, rows, columns);

    // Test Case 4

    /*
    int board[6][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1}
    };
    */
    game_board[0][3] = 1;
    game_board[0][4] = 1;
    game_board[0][5] = 1;
    game_board[0][6] = 1;

    win_horiz = check_horizontal(game_board, 0, 4);
    
    // Expecting true
    if (win_horiz) {
        puts("Horizontal Test Case 4 Success");
    } else {
        puts("Horizontal Test Case 4 Failure");
    }

    reset_game_board(game_board, rows, columns);

    // Test Case 5

    /*
    int board[6][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1}
    };
    */
    game_board[0][3] = 1;
    game_board[0][4] = 1;
    game_board[0][5] = 1;
    game_board[0][6] = 1;

    win_horiz = check_horizontal(game_board, 0, 6);
    
    // Expecting true
    if (win_horiz) {
        puts("Horizontal Test Case 5 Success");
    } else {
        puts("Horizontal Test Case 5 Failure");
    }

    reset_game_board(game_board, rows, columns);

    // -------------------------- DIAGONAL DESCENDING TEST CASES --------------------------

    // Test Case 1

    /*
    int board[6][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0}
    };
    */
    game_board[2][0] = 1;
    game_board[3][1] = 1;
    game_board[4][2] = 1;
    game_board[5][3] = 1;

    bool win_diagonal_desc = check_diagonal_descending(game_board, 3, 1);
    
    // Expecting true
    if (win_diagonal_desc) {
        puts("Diagonal Descending Test Case 1 Success");
    } else {
        puts("Diagonal Descending Test Case 1 Failure");
    }

    reset_game_board(game_board, rows, columns);

    // Test Case 2

    /*
    int board[6][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {0, 0, 2, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0}
    };
    */
    game_board[2][0] = 1;
    game_board[3][1] = 1;
    game_board[4][2] = 2;
    game_board[5][3] = 1;

    win_diagonal_desc = check_diagonal_descending(game_board, 3, 1);
    
    // Expecting false
    if (win_diagonal_desc) {
        puts("Diagonal Descending Test Case 2 Failure");
    } else {
        puts("Diagonal Descending Test Case 2 Success");
    }

    reset_game_board(game_board, rows, columns);

    // Test Case 3

    /*
    int board[6][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };
    */
    game_board[1][2] = 1;
    game_board[2][3] = 1;
    game_board[3][4] = 1;
    game_board[4][5] = 1;

    win_diagonal_desc = check_diagonal_descending(game_board, 2, 3);
    
    // Expecting true
    if (win_diagonal_desc) {
        puts("Diagonal Descending Test Case 3 Success");
    } else {
        puts("Diagonal Descending Test Case 3 Failure");
    }

    reset_game_board(game_board, rows, columns);

    // Test Case 4

    /*
    int board[6][7] = {
        {0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };
    */
    game_board[0][2] = 1;
    game_board[1][3] = 1;
    game_board[2][4] = 1;
    game_board[3][5] = 1;

    win_diagonal_desc = check_diagonal_descending(game_board, 3, 5);
    
    // Expecting true
    if (win_diagonal_desc) {
        puts("Diagonal Descending Test Case 4 Success");
    } else {
        puts("Diagonal Descending Test Case 4 Failure");
    }

    reset_game_board(game_board, rows, columns);

    // -------------------------- DIAGONAL ASCENDING TEST CASES --------------------------

    // Test Case 1

    /*
    int board[6][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0}
    };
    */
    game_board[5][1] = 1;
    game_board[4][2] = 1;
    game_board[3][3] = 1;
    game_board[2][4] = 1;

    bool win_diagonal_asc = check_diagonal_ascending(game_board, 3, 3);
    
    // Expecting true
    if (win_diagonal_asc) {
        puts("Diagonal Ascending Test Case 1 Success");
    } else {
        puts("Diagonal Ascending Test Case 1 Failure");
    }

    // Test Case 2

    /*
    int board[6][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 2, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0}
    };
    */
    game_board[5][1] = 1;
    game_board[4][2] = 2;
    game_board[3][3] = 1;
    game_board[2][4] = 1;

    win_diagonal_asc = check_diagonal_ascending(game_board, 3, 3);
    
    // Expecting false
    if (win_diagonal_asc) {
        puts("Diagonal Ascending Test Case 2 Failure");
    } else {
        puts("Diagonal Ascending Test Case 2 Success");
    }

    reset_game_board(game_board, rows, columns);

    // Test Case 3

    /*
    int board[6][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
    };
    */
    game_board[4][0] = 1;
    game_board[3][1] = 1;
    game_board[2][2] = 1;
    game_board[1][3] = 1;

    win_diagonal_asc = check_diagonal_ascending(game_board, 2, 3);
    
    // Expecting true
    if (win_diagonal_asc) {
        puts("Diagonal Ascending Test Case 3 Success");
    } else {
        puts("Diagonal Ascending Test Case 3 Failure");
    }

    reset_game_board(game_board, rows, columns);

    // Test Case 4

    /*
    int board[6][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };
    */
    game_board[5][4] = 1;
    game_board[4][5] = 1;
    game_board[3][6] = 1;

    win_diagonal_asc = check_diagonal_ascending(game_board, 4, 5);
    
    // Expecting false
    if (win_diagonal_asc) {
        puts("Diagonal Ascending Test Case 4 Failure");
    } else {
        puts("Diagonal Ascending Test Case 4 Success");
    }

    reset_game_board(game_board, rows, columns);

    // -------------------------- END OF TEST CASES --------------------------

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(game_board[i]);
    }
    free(game_board);
}
