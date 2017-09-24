#include <cstdio>

//
// Created by beans on 2016/12/8.
//
char stone[51];
void main(){
    int n;
    scanf("%d\n",&n);
    gets(stone);
    int p =0,cnt = 0;
    for (int i = 1; i < n; ++i) {
        //if(stone[])
        //printf("%c",stone)
        if(stone[i]!=stone[p]) {
            //printf("%d %d\n",i,p);
            p = i;
        }
        else
            cnt++;

    }
    printf("%d\n",cnt);
}
