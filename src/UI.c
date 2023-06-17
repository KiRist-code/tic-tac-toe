#include<stdio.h>
#include"UI.h"

void initUI(){
    printf("Tic Tac Toe\n\n");
    printf("[1. Play with P1 & P2]\n");
    printf("[2. Exit]\n");
    printf("Select the mode: ");
}

void printBoard(int map[3][3]){
    for(int i=0;i<5;i++){
        if(i % 2 == 0){ //print players' checker
            for(int j=0;j<3;j++){
                switch(map[i/2][j]){
                    case 1:
                        printf("O");
                        break;
                    case 2:
                        printf("X");
                        break;
                    default:
                        printf(" ");
                        break;
                }
                printf("|");
            }
        }
        else { //print board
            printf("-|-|-");
        }
        printf("\n");
    }
}