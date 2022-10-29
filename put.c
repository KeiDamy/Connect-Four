/**
 * put.c
 * ボードにコマを置くユーザー関数
 * @return コマがおける場合0が、置けない場合(異常がある場合)1が戻り値としてint型で返される。
**/


#include"put.h"

int put(int bord[][7],int num,int play){
    int i;

    if(num < 0 || 6 < num){
        return 1;
    }
    for(i = 0;i < 7;i++){
        if(bord[i][num] == 0) break;
    }
    if(i < 7){
        bord[i][num] = play;
        return 0;
    }
    if(i == 6){
        return 1;
    }

    return 1;
}

