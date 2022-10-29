/**
 * 重力四目並べ
 * 　重力四目並べとは重力がある四目並べ。
 * 
 * 追加機能
 * 　画面の端をクリックすると画面がそれぞれ右回転、左回転する。
 * 　回転は自分のターンの間R_QUAN回でもできるものとする。
 * 　回転し終わった時に4つ揃ってもそれは勝ちとしない。相手がそれに気づかず自分のターンがきた時初めて勝ちとなる。
 * 
 * 操作方法
 * 　自分のコマを置きたい列をクリックする。
 * 　今のターンのプレイヤーの色が画面端に出る。
 * 　右端をクリックした場合右回転、左端をクリックした場合左回転する。
 * 　ゲームに勝利した場合勝利した画面がユーザーの色になる。
 * 
 * 工夫した点
 * 　ファイルを複数に分けることでバグが発生した際見つけやすくした。
**/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<handy.h>
#include"judg.h"//勝ち負けの判定を行う
#include"put.h"//コマを置く
#include"draw.h"//グラフィック関係

#define QUAN 4//何目並べにするのか
#define R_QUAN 1

int debag(int bord[][7]);

int main(){
    int bord[7][7];//ゲームのボード盤
    int play=-1;//現在のプレイヤー（1　先手　　-1　後手）
    int i,j;
    int cnt = 0;
    int num,put_num;
    int rCnt;

    for(i = 0;i < 7;i++){
        for(j = 0;j < 7;j++){
            bord[i][j] = 0;
        }
    }
    HgOpen(745,700);

    do{
        play *= -1;
    rCnt = 0;
        do{
            if(play == 1){
            HgSetFillColor(HG_RED);
            }
            else{
                HgSetFillColor(HG_BLUE);
            }
            HgBoxFill(0,0,20,700,0);
            HgBoxFill(720,0,30,700,0);

            if(play == 1){
                printf("user1 ");
            }
            else{
                printf("user2 ");
            }
            puts("input");

            draw(bord);
            system("clear");
            debag(bord);

            num = putDisplay(bord);
            if(judg(bord,QUAN,play) != 0){
                break;
            }
//            scanf("%d",&num);
            if(num == 99 && rCnt < R_QUAN){
                l_rotation(bord);
                rCnt++;
            }
            if(num == 88 && rCnt < R_QUAN){
                r_rotation(bord);
                rCnt++;
            }
        }while(put(bord,num-1,play));
        system("clear");
        debag(bord);
        cnt++;
    }while(judg(bord,QUAN,play) == 0 && cnt != 42);
    if(judg(bord,QUAN,play) == 1){
        printf("user1 win\n");
        HgSetFillColor(HG_RED);
        HgBoxFill(0,0,750,700,0);
    }
    else if(judg(bord,QUAN,play) == -1){
        printf("user2 win\n");
        HgSetFillColor(HG_BLUE);
        HgBoxFill(0,0,750,700,0);
    }
    else{
        printf("draw\n");
    }
    draw(bord);
    HgGetChar();
    HgClose();
    
    return 0;
}

int debag(int bord[][7]){
    int i,j;
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
    return 0;
}