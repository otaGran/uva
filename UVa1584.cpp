//
// Created by beans on 2017/1/6.
//
#include <cstdio>
#include <cstring>
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char s[100+1];
        scanf("%s",s);
        int min = 0,min_count = 0;
       // std::memcpy(s,min, sizeof(s));
        for(int i = 1;i<strlen(s);i++){//枚举起始位置

            int ok = 1,tmp = 0;
            for (int k = 0; k < strlen(s); ++k) {//检查字典序
                //printf("%d\n",i);
                if(s[(k+i)%strlen(s)]!=s[(k+min)%strlen(s)]) {
                    //printf("%c %c\n",s[(k+i)%strlen(s)],s[(k+min)%strlen(s)]);
                    if(s[(k+i)%strlen(s)]<s[(k+min)%strlen(s)])
                        min = i;
                    break;
                }
            }

        }
        //printf("%d ",min);
        for (int j = 0; j < strlen(s); ++j) {
            printf("%c",s[(j+min)%strlen(s)]);

        }
        printf("\n");

    }
}
