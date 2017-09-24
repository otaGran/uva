//
// Created by beans on 2017/1/6.
//
#include <cstdio>
#include <cstring>
#include <ctype.h>
double find(char x){
    switch(x){
        case 'C':
            return 12.01;
        case 'H':
            return 1.008;
        case 'O':
            return 16.00;
        case 'N':
            return 14.01;
    }
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        char s[1000];
        scanf("%s",s);
        double res = 0,danwei = 0;
        int amount = 0;
        for (int i = 0; i < strlen(s); ++i) {
            if(isalpha(s[i])){
                if(amount==0)
                    amount = 1;
                res+=danwei*amount;
                amount = 0;
                danwei = find(s[i]);
            }
            else{
                amount=amount*10+(s[i]-'0');
            }
        }
        if(amount==0)
            amount = 1;
        res+=danwei*amount;
        printf("%.3lf\n",res);
    }
}