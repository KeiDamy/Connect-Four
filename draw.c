/**
 * 盤を表示するプログラム
**/
#include"draw.h"
#include<handy.h>


int draw(int bord[][7]){
    int i,j;
    for(i = 0;i < 7;i++){
        for(j = 0; j < 7;j++){
            if(bord[i][j] == 1){
                HgSetFillColor(HG_RED);
                HgCircleFill(70 +((j) * 100),50 + (i) * 100,50,1);
            }
            else if(bord[i][j] == -1){
                HgSetFillColor(HG_BLUE);
                HgCircleFill(70 +((j) * 100),50 + (i) * 100,50,1);
            }
        }
    }


    HgSetFillColor(HG_BLACK);
    for(i = 20;i <= 720;i += 100){
        HgBoxFill(i,0,5,700,1);
    }

    return 0;
}

