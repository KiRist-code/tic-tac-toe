#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include "game.h"
#include "UI.h"


int main(void){
    int selectMode = 0;
    while(1){
        initUI();
        scanf("%d", &selectMode);
        switch(selectMode)
        {
        case 1: //pvp mode
            pvp();
            break;
        case 2: //game exit
            return 0;
        default:
            printf("please select the right number.\n");
            sleep(2);
        }
    }

    return 0;
}