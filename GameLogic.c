#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define HEIGHT 6
#define WIDTH 7

void freeArray (double **array, int R) {
    for (int i = 0; i < R; i++) {
        free(array[i]);
    }
    free(array);
    return;
}

int **createGameBoard () {
    double **game_board = (double **)malloc(HEIGHT* sizeof(double *));
    if (game_board == NULL) {
        fprintf(stderr, "Memory allocation failed for rows.\n");
        return NULL;
    }

    for (int i = 0; i < HEIGHT; i++) {
        game_board[i] = (double *)malloc(WIDTH * sizeof(double));
        if (game_board[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for row %d.\n", i);
            return NULL;
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            game_board[i][j] = 0;
        }
    }
    return game_board;
}

int **updateGameBoard (int placement, int player, int **game_board, bool *hide_button) {
    double **new_game_board = (double **)malloc(HEIGHT * sizeof(double *));
    if (new_game_board == NULL) {
        fprintf(stderr, "Memory allocation failed for rows.\n");
        return NULL;
    }

    for (int i = 0; i < HEIGHT; i++) {
        new_game_board[i] = (double *)malloc(WIDTH * sizeof(double));
        if (new_game_board[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for row %d.\n", i);
            return NULL;
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            new_game_board[i][j] = game_board[i][j];
        }
    }

    freeArray(game_board, HEIGHT);

    int check = 0;
    for (int i = 0; i < HEIGHT; i++) {
        if (new_game_board[i][placement] == 0) {
            new_game_board[i][placement] = player;
            check = 1;
            break;
        }
    }
    if (check == 1) {
        hide_button = true;
    }

    return new_game_board;
}

void playerSelection (int *player) {
    *player = 3 - *player;
    return;
}