//
// Created by beans on 2017/1/7.
//
#include <cstdio>
#include <cstring>


int main(){
    int r,c,count = 0;
    while (scanf("%d %d",&r,&c)&&r){
        char s[r][c+1];
        int map[r][c+1];
        std::memset(map,0, sizeof(map));
        int a_count = 0,d_count = 0,cnt = 0;
        for (int i = 0; i < r; ++i) {
            //printf("%d",i);
            scanf("%s",s[i]);
            for (int j = 0; j < c; ++j) {
                if(s[i][j]=='*')
                    continue;
                if(i-1<0||s[i-1][j]=='*'||j-1<0||s[i][j-1]=='*')
                    map[i][j] = ++cnt;
            }
            //printf("%s\n",s[i]);
        }

        /*
        for (int k = 0; k <r; ++k) {
            for (int i = 0; i < c; ++i) {
                printf("%d ",map[k][i]);
            }
            printf("\n");
        }
         */


        if(count!=0)
            printf("\n");
        printf("puzzle #%d:\n",++count);
        printf("Across\n");
        for (int j = 0; j < r; ++j) {
            for (int i = 0; i < c; ++i) {
                if(map[j][i]&&(i-1<0||s[j][i-1]=='*')) {
                    printf("%3d.",map[j][i]);
                    int tmp = i;
                    while(tmp<c){
                        if(s[j][tmp]=='*')
                            break;
                        printf("%c",s[j][tmp++]);
                    }
                    printf("\n");
                    //printf("%d %d\n",j,i);
                    //across(s, j, i);
                }
            }
        }

        printf("Down\n");
        for (int j = 0; j < r; ++j) {
            for (int i = 0; i < c; ++i) {
                if(map[j][i]&&((j-1)<0||s[j-1][i]=='*')) {
                    printf("%3d.",map[j][i]);
                    int tmp = j;
                    while(tmp<r){
                        if(s[tmp][i] == '*')
                            break;
                        printf("%c",s[tmp++][i]);
                    }
                    printf("\n");
                    //printf("%d %d\n",j,i);
                    //down(s, j, i);
                }
            }
        }

    }
}