//模拟法
// Created by beans on 2016/12/4.
//
#include <cstdio>
#include <cstring>

int d;
char s[100+10];
void main(){
    memset(s,0,sizeof(s));
    while(scanf("%d",&d)!=EOF&&d!=0){
        scanf("%s\n",s);
        //printf("%d %s\n",d,s);
        int t;
        for(t = 0;;t++)
            if(s[t]=='\0')
                break;
        d = t / d;
        for (int i = 0;;i+=d) {
            if(s[i]=='\0')
                break;
            else
                for(int j = i+d-1;j>=i;j--){
                    printf("%c",s[j]);
                }

        }
        memset(s,0,sizeof(s));


        printf("\n");

    }
    return 0;
}
