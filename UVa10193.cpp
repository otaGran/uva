//
// Created by beans on 3/20/2017.
//最大公约数模板
//
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

char s1[31],s2[31];

int gcd(int a,int b){
    if(b)
        while ((a%=b)&&(b%=a));
    return a+b;
}

int cal(char *tmp){
    int res = 0;
    for (int i = 0; tmp[i]!='\0'; ++i) {
        res*=2;
        res+=tmp[i]-'0';
    }
    return res;
}

int main(){
    int N;
    scanf("%d",&N);
    int cnt = 1;
    while(N--){
        printf("Pair #%d: ",cnt++);
        //string s1,s2;
        scanf("%s%s",s1,s2);
        int d1 = 0,d2 = 0;
        d1 = cal(s1);
        d2 = cal(s2);
        int ok = gcd(d1,d2);
        if(ok!=1)
            printf("All you need is love!\n");
        else
            printf("Love is not all you need!\n");

    }
}
