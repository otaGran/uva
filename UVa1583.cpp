//
// Created by beans on 2017/1/6.
//
#include <cstdio>
#include <cstring>
#include <string.h>
int main(){
    int n;
    scanf("%d",&n);
    int result[1000000];
    for (int k = 1; k < 100000; ++k) {

            int res = k,t = k;
            while(t>0) {
                res += t % 10;
                t /= 10;
            }
            if (result[res]==0||k<result[res]){
                result[res] = k;
            }
    }

    while (n--){
        int tmp;
        scanf("%d",&tmp);
        printf("%d\n",result[tmp]);
    }
}