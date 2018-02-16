//
// Created by beans_pc on 2/16/2018.
//棋盘覆盖问题
//有一个2^k*2^k的方格棋盘,恰有一个方格是黑色的,其他为白色,如何用三种L形派覆盖所有的白色格子且任意白色格子只能覆盖一次

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int cnt = 65;

int getbx(int i,int sx,int sy,int k){
    if(i == 1 || i == 3) //sec and third use sx as virtual black pixel
        return sx;
    else
        return sx + (int)pow(2,k) - 1;

}

int getby(int i,int sx,int sy,int k){
    if(i == 0 || i == 1)
        return sy + (int)pow(2,k) - 1;
    else
        return sy;
}

void slove(char map[100][100],int k, int bx, int by, int sx, int sy){
    //printf("%d %d %d %d %d\n",k,bx,by,sx,sy);
    if(k==1){
        for(int i = sx;i<=sx+1;i++){
            for(int j = sy;j<=sy+1;j++){
                if(i!=bx||j!=by)
                    map[i][j] = cnt;
            }
        }
        cnt++;
    }else{

        for(int i = 0;i<4;i++){
            int nextx = (i==0||i==2) ? sx : (sx+(int)pow(2,k)/2);
            int nexty = (i==0||i==1) ? sy : (sy+(int)pow(2,k)/2);
            printf("%d %d\n",nextx,nexty);
            if(bx>=nextx&&bx<nextx+(int)pow(2,k-1) && by>=nexty&&by<nexty+(int)pow(2,k-1)){//already have black pixel
                slove(map,k-1,bx,by,nextx,nexty);
                //printf("%d %d %d %d %d\n",k-1,bx,by,nextx,nexty);
            }else{
                printf("%d %d %d %d %d\n",k-1,getbx(i,nextx,nexty,k-1), getby(i,nextx,nexty,k-1), nextx, nexty);
                slove(map, k-1, getbx(i,nextx,nexty,k-1), getby(i,nextx,nexty,k-1), nextx, nexty);
                map[getbx(i,nextx,nexty,k-1)][ getby(i,nextx,nexty,k-1)] = '#';

            }

        }
    }

}

int main(){
    int k, bx, by;
    cin >> k >> bx >> by;
    char map[100][100];
    memset(map,0,sizeof(map));
    map[bx][by] = '*';


    slove(map,k,bx,by,0,0);

    for(int i = 0;i<pow(2,k);i++){
        for(int j = 0;j<pow(2,k);j++)
            printf("%2c ",map[i][j]);
        cout << endl;
    }

    //for(int i = 0;i<4;i++)
    int i = 0;
       //printf("%d : (%d, %d)\n",i,getbx(i,0,0,2),getby(i,0,0,2));
}

