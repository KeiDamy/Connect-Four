/**
 * 画面を回転させるプログラム
**/
#include"put.h"
#include<stdio.h>
#include<handy.h>

int r_rotation(int bord[][7]){
    int i,j;
    int loca;
    int temp[7][7];

    for(i = 0;i < 7;i++){
        loca = -1;
        for(j = 0;j < 7;j++){
            if(bord[i][j] == 0 && loca == -1){
                loca = j;
            }
            if(bord[i][j] != 0 && loca != -1){
                bord[i][loca] = bord[i][j];
                bord[i][j] = 0;
                j = loca;
                loca = -1;
            }
        }
    }
    
    for(i = 6;i >= 0;i--){
        for(j = 0;j < 7;j++){
            if(bord[i][j] == 1){
                printf("1 ");
            }
            else if(bord[i][j] == -1){
                printf("2 ");
            }
            else{
                printf("0 ");
            }

        }
        puts("");
    }

    for(i = 0;i < 7;i++){
        for(j = 0;j < 7;j++){
            temp[i][j] = bord[i][j];
        }
    }
    for(i = 0;i < 7;i++){
        for(j = 0;j < 7;j++){
            temp[i][j] = bord[6-j][i];
        }
    }

    for(i = 0;i < 7;i++){
        for(j = 0;j < 7;j++){
            bord[i][j] = temp[i][j];
        }
    }

    HgClear();
    return 0;
}
