//
// Created by beans on 2017/1/6.
//
#include <cstdio>
#include <cmath>
#include <cstring>
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char s[100];
        scanf("%s",s);
        int res = strlen(s);
        for (int i = 1; i <= (strlen(s))/2; ++i) {
            //printf("round:%d ",i);
            int ok = 1;
            for (int j = 1; j < ceil(strlen(s))/i; ++j) {
                //printf("%d ",j);
                for (int k = 0; k < i; ++k) {
                    //printf("check:%d %d    ",k,j*i+k);
                    if(s[k]!=s[j*i+k])
                        ok = 0;
                }
                //printf("\n");
            }
            //printf("\n");
            if(ok){
                res = i;
                break;
            }
        }
        printf("%d\n",res);
        if(n!=0)
            printf("\n");
    }
}