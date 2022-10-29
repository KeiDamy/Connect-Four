/**
 * 勝ち負けの判定を行う
**/
#include<stdio.h>
#include"judg.h"


int judg(int bord[][7],int quan,int play){
    int i,j,k;
    int cnt;
    int temp[4][4];
    for(i = 0;i < 7;i++){//横判定開始
        cnt = 0;
        for(j = 0;j < 7;j++){
            if(bord[i][j] == play){
                cnt++;
                if(cnt == 4){
                    return play;
                }
            }
            else{
                cnt = 0;
            }
        }
    }

    for(j = 0;j < 7;j++){//縦判定開始
        cnt = 0;
        for(i = 0;i < 7;i++){
            if(bord[i][j] == play){
                cnt++;
                if(cnt == 4){
                    return play;
                }
            }
            else{
                cnt = 0;
            }
        }
    }

    for(j = 0;j < 4;j++){//右斜め判定開始
        k = 0;
        cnt = 0;
        for(i = 0;i < 7;i++){
            if(bord[i][j+k] == play){
                cnt++;
                if(cnt == 4){
                    return play;
                }
            }
            else{
                cnt = 0;
            }
            k++;
        }
    }

    for(j = 6;j > 2;j--){//左斜め判定開始
        k = 0;
        cnt = 0;
        for(i = 0;i < 7;i++){
            if(bord[i][j-k] == play){
                cnt++;
                if(cnt == 4){
                    return play;
                }
            }
            else{
                cnt = 0;
            }
            k++;
        }
    }

    return 0;
}
