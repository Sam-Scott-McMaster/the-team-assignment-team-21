#include <stdio.h>
#include <stdlib.h>

#define HEIGHT 6
#define WIDTH 7

//frees a malloc array
void freeArray (int **array, int R) {
    for (int i = 0; i < R; i++) {
        free(array[i]);
    }
    free(array);
    return;
}

//creates an empty game board
int **createGameBoard () {
    int **game_board = (int **)malloc(HEIGHT* sizeof(int *));
    if (game_board == NULL) {
        fprintf(stderr, "Memory allocation failed for rows.\n");
        return NULL;
    }

    for (int i = 0; i < HEIGHT; i++) {
        game_board[i] = (int *)malloc(WIDTH * sizeof(int));
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

//updates the gameboard after a button test as well as returning a side effect to hide a GUI button and the placement of the piece
int **updateGameBoard (int placement, int player, int **game_board, int *hide_button, int *placement_height) {
    int **new_game_board = createGameBoard();  // Create a new game board

    // Copy the old game board to the new one
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            new_game_board[i][j] = game_board[i][j];
        }
    }

    // Place the piece in the selected column
    int check = 0;
    for (int k = 0; k < HEIGHT; k++) {
        if (game_board[k][placement] == 0) {
            new_game_board[k][placement] = player;
            *placement_height = k;
            break;
        } else {
            check++;
        }
    }

    // If the column is full, hide the button
    if (check == HEIGHT) {
        *hide_button = 1;
    }
    
    freeArray(game_board, HEIGHT);

    return new_game_board;
}

//changes the current player
void playerSelection (int *player) {
    *player = 3 - *player;
    return;
}

//test main function run
/*
void main () {
    int placement_height = 0;
    int player = 1;
    int **gameboard = createGameBoard();
    while (1) {
        int placement;
        printf("Player %d what row would you like to place it in: ", player);
        scanf("%d", &placement);
        gameboard = updateGameBoard(placement,player,gameboard,0,&placement_height);
        playerSelection(&player);
        for(int j=HEIGHT-1;j>-1; j--) {
            for(int k=0;k<WIDTH; k++) {
                printf("%d",gameboard[j][k]);
            }
            printf("\n");
        }
    }
} */