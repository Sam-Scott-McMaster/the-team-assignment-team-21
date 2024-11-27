#include <stdio.h>
#include <stdlib.h>
#include "GameLogic.h"

#define HEIGHT 6
#define WIDTH 7

void main () {
    int placement_height = 0;
    int player = 1;
    int **gameboard = createGameBoard();
    int placement;
    int hide_button = 0;
        
    gameboard = updateGameBoard(1,player,gameboard,hide_button,&placement_height);
    playerSelection(&player);
    printf("Player %d", player);
    for(int j=HEIGHT-1;j>-1; j--) {
        for(int k=0;k<WIDTH; k++) {
            printf("%d",gameboard[j][k]);
         }
        printf("\n");
    }

    gameboard = updateGameBoard(2,player,gameboard,hide_button,&placement_height);
    playerSelection(&player);
    printf("Player %d", player);
    for(int j=HEIGHT-1;j>-1; j--) {
        for(int k=0;k<WIDTH; k++) {
            printf("%d",gameboard[j][k]);
         }
        printf("\n");
    }

    gameboard = updateGameBoard(1,player,gameboard,hide_button,&placement_height);
    playerSelection(&player);
    printf("Player %d", player);
    for(int j=HEIGHT-1;j>-1; j--) {
        for(int k=0;k<WIDTH; k++) {
            printf("%d",gameboard[j][k]);
         }
        printf("\n");
    }

    gameboard = updateGameBoard(6,player,gameboard,hide_button,&placement_height);
    playerSelection(&player);
    printf("Player %d", player);
    for(int j=HEIGHT-1;j>-1; j--) {
        for(int k=0;k<WIDTH; k++) {
            printf("%d",gameboard[j][k]);
         }
        printf("\n");
    }

    gameboard = updateGameBoard(6,player,gameboard,hide_button,&placement_height);
    playerSelection(&player);
    printf("Player %d", player);
    for(int j=HEIGHT-1;j>-1; j--) {
        for(int k=0;k<WIDTH; k++) {
            printf("%d",gameboard[j][k]);
         }
        printf("\n");
    }

    gameboard = updateGameBoard(6,player,gameboard,hide_button,&placement_height);
    playerSelection(&player);
    printf("Player %d", player);
    for(int j=HEIGHT-1;j>-1; j--) {
        for(int k=0;k<WIDTH; k++) {
            printf("%d",gameboard[j][k]);
         }
        printf("\n");
    }

    gameboard = updateGameBoard(6,player,gameboard,hide_button,&placement_height);
    playerSelection(&player);
    printf("Player %d", player);
    for(int j=HEIGHT-1;j>-1; j--) {
        for(int k=0;k<WIDTH; k++) {
            printf("%d",gameboard[j][k]);
         }
        printf("\n");
    }

    gameboard = updateGameBoard(6,player,gameboard,hide_button,&placement_height);
    playerSelection(&player);
    printf("Player %d", player);
    for(int j=HEIGHT-1;j>-1; j--) {
        for(int k=0;k<WIDTH; k++) {
            printf("%d",gameboard[j][k]);
         }
        printf("\n");
    }

    gameboard = updateGameBoard(6,player,gameboard,hide_button,&placement_height);
    playerSelection(&player);
    printf("Player %d", player);
    for(int j=HEIGHT-1;j>-1; j--) {
        for(int k=0;k<WIDTH; k++) {
            printf("%d",gameboard[j][k]);
         }
        printf("\n");
    }
}