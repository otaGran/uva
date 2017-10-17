//
// Created by beans on 2017/10/10.
//
//abcde / fghij = n
//仅枚举后五位 for循环从1234 -> 98765
//枚举前五位=>需要除法 精度问题

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int ok;

bool check(int ab,int fg){
    if(ab>98765||ab<1234)//剪枝
        return 0;
    int num[10],sum = 0;
    memset(num,0,sizeof(num));
    if(ab<10000||fg<10000)//补前导0 不存在多补情况 一共十个数字 最后sum判断
        num[0] = 1;
    while(ab){
        num[ab%10] = 1;
        ab /= 10;
    }
    while(fg){
        num[fg%10]  =1;
        fg /= 10;
    }
    for (int i : num)
        sum += i;
    return (sum==10);
}

int main(){
    int n,m = 0;
    while(cin >> n){
        if(!n)
            return 0;
        if(m++>0)
            cout << endl;
        ok = 0;
        for(int i = 1234;i<=98765;i++){
            if(check(i*n,i)){
                ok = 1;
                printf("%05d / %05d = %d\n",i*n,i,n);
            }
        }
        if(!ok)
            cout << "There are no solutions for " << n << "." << endl;
    }
}