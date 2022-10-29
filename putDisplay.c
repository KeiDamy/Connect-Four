/**
 * 画面のマウス状況からｘ座標を取得する。
 * @return　どの列に置くのかを返す　何らかの問題が起こり、最後まで行った場合0を返す　 画面端をクリックした場合99が返される
**/

#include<handy.h>
#include"draw.h"

int putDisplay(int bord[][7]){
    HgSetEventMask(HG_MOUSE_DOWN);
    while(1){
        hgevent *event = HgEvent();
        if(event->type == HG_MOUSE_DOWN){
            int x = (int) event->x;
            if(x < 20){
                return 88;
            }
            if(x > 720){
                return 99;
            }
            x = (x - 20) /100;
            return x + 1;
        }
    }
    

    return 0;
}