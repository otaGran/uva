#include <cstdio>
#include <cstring>
#include <stdarg.h>
#include <stdio.h>
//模拟法
//使用cnt++作为当前vis标识
// Created by beans on 2016/12/4.
//
int t,vis[11],res[11],cnt;
char s[200+10];


int fuck(int count, ...)
{
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i)
    {
        int arg = va_arg(args, int);
        //printf("%d",arg);
        if(vis[arg]==0){
            //for(int i = 0;i<11;i++)
              //  printf("%d ",vis[i]);
            //printf("hhh%dhhh\n",vis[arg]);
            //printf("\n");
            //vis[arg]=cnt;
            res[arg]++;
        }
        vis[arg] = cnt;
    }
    va_end(args);
    return 0;
}
void check(char x){
    switch(x){
        case 'c':
            fuck(7,2,3,4,7,8,9,10);
            break;
        case 'd':
            fuck(6,2,3,4,7,8,9);
            break;
        case 'e':
            fuck(5,2,3,4,7,8);
            break;
        case'f':
            fuck(4,2,3,4,7);
            break;
        case 'g':
            fuck(3,2,3,4);
            break;
        case 'a':
            fuck(2,2,3);
            break;
        case 'b':
            fuck(1,2);
            break;
        case 'C':
            fuck(1,3);
            break;
        case 'D':
            fuck(7,1,2,3,4,7,8,9);
            break;
        case 'E':
            fuck(6,1,2,3,4,7,8);
            break;
        case 'F':
            fuck(5,1,2,3,4,7);
            break;
        case 'G':
            fuck(4,1,2,3,4);
            break;
        case 'A':
            fuck(3,1,2,3);
            break;
        case 'B':
            fuck(2,1,2);
            break;

    }
}
void main(){
    scanf("%d",&t);
    gets(s);
    for (int i = 0; i < t; i++) {
        cnt = 0;
        memset(s,0, sizeof(s));
        memset(vis,0, sizeof(vis));
        memset(res,0, sizeof(res));
        gets(s);
        //scanf("%s",s);
        //printf("%s",s);
        for (int j = 0;; j++) {
            if(s[j]=='\0')
                break;
            cnt++;
            check(s[j]);
            for(int f = 0;f<11;f++) {
                //printf("%d %d\n",vis[f],cnt);
                if (vis[f] != cnt)
                    vis[f] = 0;
            }
           // printf("\n");
        }
        for (int k = 1; k < 10; ++k) {
            printf("%d ",res[k]);
        }
        printf("%d\n",res[10]);
    }

}
