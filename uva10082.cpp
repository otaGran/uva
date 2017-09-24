//
// Created by beans on 2017/1/6.
//
#include <cstdio>
#include <cstring>
int main(){
    char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL\;\'ZXCVBNM,./";
    char c;
    while((c = getchar())!=EOF){
        bool ok = 0;
       for(int i = 0;i<strlen(s);i++){
           if(s[i]==c) {
               printf("%c", s[i - 1]);
               ok = 1;
               break;
           }
       }
        if(!ok)
        printf("%c",c);
    }
    return 0;
}
