#include "game.h"
#include "UI.h"
#include "fileIO.h"
#include<string.h>
#include<stdlib.h>

struct Board* makeNewBoard(){
    struct Board* board = (struct Board*)calloc(0,sizeof(struct Board));
}

struct Game* makeNewGame(){
    //initialize Game Struct
    struct Game* game = (struct Game*)malloc(sizeof(struct Game));

    //initialize map
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            game->board.map[i][j] = 0;
        }
    }

    return game;
}

int checkBoard(struct Board* board, int player_id){
    int count = 0;
    //check width row
    for(int i=0;i<3;i++){ 
        for(int j=0;j<3;j++){
            if(board->map[i][j] == player_id){
                count++;
            }
        }
        if(isRow(count) == 1) return 1;
        count = 0;
    }
    

    //check height row
    for(int i=0;i<3;i++){ 
        for(int j=0;j<3;j++){
            if(board->map[j][i] == player_id){
                count++;
            }
        }
        if(isRow(count) == 1) return 1;
        count = 0;
    }

    //check cross row
    for(int i=0;i<3;i++){ 
        if(board->map[i][i] == player_id){
            count++;
        }
    }

    if(isRow(count) == 1) return 1;
    count = 0;

    for(int i=0;i<3;i++){ 
        if(board->map[i][2-i] == player_id){
            count++;
        }
    }

    if(isRow(count) == 1) return 1;

    return 0;
}



int isRow(int count){
    if(count == 3) return 1;
    else return 0;
}

int checkFilled(struct Board* board){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board->map[i][j] == 0){
                return 0;
            }
        }
    }
    return 1;
}

void pvp(){
    struct Game* game = makeNewGame();
    printf("Plz input the Player1 name: ");
    scanf("%s", &game->player1);
    printf("Plz input the Player2 name: ");
    scanf("%s", &game->player2);
    printf("Starting the game. . .\n\n");

    int turn = 0;
    int placeX = 0;
    int placeY = 0;

    while(1){
        turn++;
        printf("==============================\n");
        printf("Turn: %d\n", turn);
        printBoard(game->board.map);
        if(turn % 2 == 1){ //player 1
            printf("It's Player1's turn\n");
            printf("Place your checker(x:0~2 y:0~2)(ex: 0 2): \n");
            scanf("%d %d", &placeX, &placeY);

            if(placeX >= 0 && placeX < 3 && placeY >= 0 && placeY < 3){
                game->board.map[placeX][placeY] = 1;

                if(checkBoard(game->board.map, 1) == 1){
                    printf("Player1 win!\n\n");
                    fileWrite(game->player1, game->player2, 1);
                    return;
                }
            }
            else{
                printf("Input Again");
                turn--;
            }
        } else { //player 2
            printf("It's Player2's turn\n");
            printf("Place your checker(x:0~2 y:0~2)(ex: 0 2): \n");
            scanf("%d %d", &placeX, &placeY);

            if(placeX >= 0 && placeX < 3 && placeY >= 0 && placeY < 3){
                game->board.map[placeX][placeY] = 2;

                if(checkBoard(game->board.map, 2) == 1){
                    printf("Player2 win!\n\n");
                    fileWrite(game->player1, game->player2, 2);
                    return;
                }
            }
            else{
                printf("Input Again");
                turn--;
            }
        }

        if(checkFilled == 1){
            printf("TIE");
            fileWrite(game->player1, game->player2, 0);
            free(game);
            return;
        }
    }
}