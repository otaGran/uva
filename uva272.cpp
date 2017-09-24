//
// Created by beans on 2017/1/5.
//
#include <string>
#include <stdio.h>
int main(){
    char c;
    bool flag = false;
    while((c = getchar())!=EOF){
        if(c == '"'){
            printf("%s",flag?"''":"``");
            flag = !flag;
        } else
            printf("%c",c);
    }
    return 0;
    //printf("%s\n",s);

}
