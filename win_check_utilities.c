#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEIGHT 6
#define WIDTH 7

/*
check_vertical

This function checks for a win vertically.
It uses a strategy of starting from the most recently placed piece and checking each space below it
until four of the same pieces are found in a row indicating a win, otherwise it stops checking.

Parameters:
    - int **game_board: A 2D array representing the game board (rows and columns).
    - int current_row: The current row position of the player’s move.
    - int current_col: The current column position of the player’s move.

Output:
    - Returns true if four consecutive pieces from the same player are found
    - Returns false otherwise
*/
bool check_vertical(int **game_board, int current_row, int current_col) {

    int player = game_board[current_row][current_col];
    //printf("Player: %d\n", player);

    if (current_row > 2) {
        for (int i = 0; i < 4; i++) {
            if (game_board[current_row - i][current_col] != player) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}

/*
check_horizontal

This function checks for a win horizontally.
It starts from the most recently placed piece and begins by checking the left side.
If there hasn't been a win after the left side was checked, it would then check the right side.

Parameters:
    - int **game_board: A 2D array representing the game board (rows and columns).
    - int current_row: The current row position of the player’s move.
    - int current_col: The current column position of the player’s move.

Output:
    - Returns true if four consecutive pieces from the same player are found
    - Returns false otherwise
*/
bool check_horizontal(int **game_board, int current_row, int current_col) {
    int connected_pieces = 1;
    int player = game_board[current_row][current_col];
    int left_spaces;
    int right_spaces;

    // Assign amount of spaces to check horizontally to prevent out of bounds error
    if (current_col < 3) {
        left_spaces = current_col;
    } else {
        left_spaces = 3;
    }

    if (current_col > 3) {
        right_spaces = 6 - current_col;
    } else {
        right_spaces = 3;
    }

    // Checking left side of most recently placed piece
    if (current_col != 0) {
        for (int i = 1; i <= left_spaces; i++) {
            if (game_board[current_row][current_col - i] == player) {
                connected_pieces++;
            } else {
                break;
            }
        }
        //puts("Left side checked."); // Testing
    }

    //printf("After left check: %d\n", connected_pieces); // For testing

    if (connected_pieces >= 4) {
        return true;
    }

    // Checking right side of most recently placed piece
    if (current_col != 6) {
        for (int i = 1; i <= right_spaces; i++) {
            if (game_board[current_row][current_col + i] == player) {
                connected_pieces++;
            } else {
                break;
            }
        }
        //puts("Right side checked."); // Testing
    }

    //printf("After right check: %d\n", connected_pieces); // For testing

    if (connected_pieces >= 4) {
        return true;
    } else {
        return false;
    }
}

/*
check_diagonal_ascending

This function checks for a win diagonally in an ascending manner.
It starts from the most recently placed piece and begins by checking the left side.
If there hasn't been a win after the left side was checked, it would then check the right side.

Parameters:
    - int **game_board: A 2D array representing the game board (rows and columns).
    - int current_row: The current row position of the player’s move.
    - int current_col: The current column position of the player’s move.

Output:
    - Returns true if four consecutive pieces from the same player are found
    - Returns false otherwise
*/
bool check_diagonal_ascending(int **game_board, int current_row, int current_col) {
    int connected_pieces = 1;
    int player = game_board[current_row][current_col];
    int left_spaces;
    int right_spaces;

    // Assign amount of spaces to check left diagonally
    if ((current_row < 3) || (current_col < 3)) {
        if (current_row < current_col) {
            left_spaces = current_row;
        } else {
            left_spaces = current_col;
        }
    } else {
        left_spaces = 3;
    }

    // Assign amount of spaces to check right diagonally
    if ((current_row > 2) || (current_col > 3)) {
        if (current_row >= current_col) {
            right_spaces = 5 - current_row;
        } else {
            right_spaces = 6 - current_col;
        }
    } else {
        right_spaces = 3;
    }

    // Checking left diagonal
    if ((current_row != 0) && (current_col != 0)) {
        for (int i = 1; i <= left_spaces; i++) {
            if (game_board[current_row - i][current_col - i] == player) {
                connected_pieces++;
            } else {
                break;
            }
        }
        //puts("Left diagonal checked."); // Testing
    }

    //printf("After left diagonal check: %d\n", connected_pieces); // For testing

    if (connected_pieces >= 4) {
        return true;
    }

    //Checking right diagonal
    if ((current_row != 5) && (current_col != 6)) {
        for (int i = 1; i <= right_spaces; i++) {
            if (game_board[current_row + i][current_col + i] == player) {
                connected_pieces++;
            } else {
                break;
            }
        }
        //puts("Right diagonal checked."); // Testing
    }

    //printf("After right diagonal check: %d\n", connected_pieces); // For testing

    if (connected_pieces >= 4) {
        return true;
    } else {
        return false;
    }
}

/*
check_diagonal_descending

This function checks for a win diagonally in a descending manner.
It starts from the most recently placed piece and begins by checking the left side.
If there hasn't been a win after the left side was checked, it would then check the right side.

Parameters:
    - int **game_board: A 2D array representing the game board (rows and columns).
    - int current_row: The current row position of the player’s move.
    - int current_col: The current column position of the player’s move.

Output:
    - Returns true if four consecutive pieces from the same player are found
    - Returns false otherwise
*/
bool check_diagonal_descending(int **game_board, int current_row, int current_col) {
    int connected_pieces = 1;
    int player = game_board[current_row][current_col];
    int left_spaces;
    int right_spaces;

    // Assign amount of spaces to check left diagonally
    if ((current_row < 3) && (current_col > 2)) {
        left_spaces = 3;
    } else if ((current_row <= 3) && (current_col >= 2)) {
        left_spaces = 2;
    } else {
        left_spaces = 1;
    }

    // Assign amount of spaces to check right diagonally
    if ((current_row > 2) && (current_col < 4)) {
        right_spaces = 3;
    } else if ((current_row >= 2) && (current_col <= 4)) {
        right_spaces = 2;
    } else {
        right_spaces = 1;
    }

    // Checking left diagonal
    if ((current_row != 5) && (current_col != 0)) {
        for (int i = 1; i <= left_spaces; i++) {
            if (game_board[current_row + i][current_col - i] == player) {
                connected_pieces++;
            } else {
                break;
            }
        }
        //puts("Left diagonal checked."); // Testing
    }

    //printf("After left diagonal check: %d\n", connected_pieces); // For testing

    if (connected_pieces >= 4) {
        return true;
    }

    //Checking right diagonal
    if ((current_row != 0) && (current_col != 6)) {
        for (int i = 1; i <= right_spaces; i++) {
            if (game_board[current_row - i][current_col + i] == player) {
                connected_pieces++;
            } else {
                break;
            }
        }
        //puts("Right diagonal checked."); // Testing
    }

    //printf("After right diagonal check: %d\n", connected_pieces); // For testing

    if (connected_pieces >= 4) {
        return true;
    } else {
        return false;
    }
}