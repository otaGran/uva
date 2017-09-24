//
// Created by beans on 2017/1/9.
//
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctype.h>
char header[1000];
int code[8][1<<8];
int readcode(){
    memset(code,0, sizeof(code));
    while(true){
        int ch = getchar();
        //printf("%d",ch);
        if(ch=='\n'||ch=='\r')
            continue;
        else{
            code[1][0] = ch;
            break;
        }
    }
    for(int len = 2;len<=7;len++){
        for (int i = 0; i < (1<<len)-1; ++i) {
            int ch = getchar();
            if(ch==EOF)
                return 0;
            if(ch=='\n'||ch=='\r')
                return 1;
            code[len][i] = ch;
        }
    }

}
int reader(int length){
    int res = 0;
    while(length>0){
        int tmp = getchar();
        //printf("%c ",tmp);
        if(!isdigit(tmp))
            continue;
        res+=(tmp-'0')*pow(2.0,length-1);
        length--;
    }
    return res;
}
int main(){
    while(readcode()){
        //printf("%d\n",reader(3));
        while (true) {
            int length = reader(3);
            if (length == 0)
                break;
            while (true) {
                int tmp = reader(length);
                if (tmp == (int) pow(2.0, length)-1)
                    break;
                printf("%c",code[length][tmp]);
            }
        }
        printf("\n");

    }
}

