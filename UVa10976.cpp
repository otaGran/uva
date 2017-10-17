//
// Created by beans on 2017/10/10.
//
//输入正整数k,找到所有的正整数x>=y,使得1/k = 1/x + 1/y
//由于x>=y ==> 1/x<=1/y
//1/k - 1/y = 1/y ==> y <= 2k
//在2k范围内从小到大枚举y 尝试算出x
#include <iostream>

using namespace std;
int k,sum = 0;

void check(int y){
    int un = y*k,up = y - k;
    if(up>0&&un%up==0) {
        //printf("1/%d = 1/%d + 1/%d\n", k, un / up, y);
        sum++;
    }
}

void fuck(int y){
    int un = y*k,up = y - k;
    if(up>0&&un%up==0) {
        printf("1/%d = 1/%d + 1/%d\n", k, un / up, y);
        //sum++;
    }
}

int main(){
    while(cin >> k){
        sum = 0;
        //cout << k << endl;
        for(int i = 1;i<=2*k;i++){
            check(i);
        }
        cout << sum << endl;
        for(int i = 1;i<=2*k;i++){
            fuck(i);
        }
    }
}

