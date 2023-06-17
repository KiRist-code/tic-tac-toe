#include<stdio.h>
#include<string.h>
#include "fileIO.h"

void fileWrite(char* player1, char* player2, int winner_id){
    FILE *fp;

    fp = fopen("gameLog.txt","w+");

    if(fp == NULL){
        printf("[ERROR] File cannot open!");
        return;
    } 

    fseek(fp,0,SEEK_END);

    fputs("\np1: ", fp);
    fputs(player1, fp);
    fputs(" p2: ", fp);
    fputs(player2, fp);

    switch(winner_id){
        case 1:
            fputs(" winner: ", fp);
            fputs(player1, fp);
            break; 
        case 2:
            fputs(" winner: ", fp);
            fputs(player2, fp);
            break;
        default:
            fputs(" TIE", fp);
            break;
    }

    fclose(fp);
}