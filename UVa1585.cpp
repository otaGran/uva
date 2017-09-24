//
// Created by beans on 2017/1/6.
//
#include <cstdio>
#include <cstring>
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char s[100];
        scanf("%s",s);
        int count = 0,res = 0;
        for (int i = 0; i < strlen(s); ++i) {
            if(s[i]=='X')
                count = 0;
            else
                res+=++count;
        }
        printf("%d\n",res);
    }
}
