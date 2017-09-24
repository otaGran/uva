#include <cstdio>
#include <cstring>
//
// Created by beans on 2016/12/8.
//
using namespace std;
char s[100000],t[100000];
int s_len,t_len,pos;

bool find(int p,char c){
    if(p>=t_len)
        return false;
    for(int i = p;i<t_len;i++){
        if(t[i]==c) {
            pos = i + 1;
            return true;
        }
    }
    return false;
}

int main(){
    while(scanf("%s%s",s,t)!=EOF){
        pos = 0;
        s_len = strlen(s);
        t_len = strlen(t);
        //printf("s:%d t:%d\n",s_len,t_len);
        //zijishengcheng
        //check();
        /*
        int B[t_len];
        memset(B,0, sizeof(B));

        subset(t_len,B,0);
        if(ok)
            printf("yes\n");
        else
            printf("no\n");
            */
        int o = 1;
        for (int i = 0; i <s_len; ++i) {
            char tmp = s[i];
            if(!find(pos,tmp)) {
                o = 0;
                break;
            }
        }
        if(o)
            printf("Yes\n");
        else
            printf("No\n");

    }

}