//BigInteger,mod
// Created by beans on 2016/12/6.
//ascii code foe '0' is 011 0000(ascii & 15 == ascii - '0')
//a * 10 % m == ( ( a % m ) * 10 ) % m？？？？？？？？？？？？？？？
#include<cstdio>
#include<cstring>
int t,n,tmp;
//for integer M < 10^1000 means that there are 1000 digits.
char num[1005];
void main(){
    scanf("%d",&t);
    while(t--){
        getchar();
        gets(num);
        int len = strlen(num);
        scanf("%d",&n);
        int ok = 1;
        while(n--){
            scanf("%d",&tmp);
            int rem = 0;
            for (int i = 0; i <len ; ++i) {
                rem = (rem*10+(num[i]-'0'))%tmp;
            }
            if(rem)
                ok = 0;
        }
        if(ok)
            printf("%s - Wonderful.\n",num);
        else
            printf("%s - Simple.\n",num);
    }
    return 0;
}