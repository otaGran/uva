//
// Created by beans on 2017/10/10.
//
//寻找最大连续乘积
//枚举起点终点
//注意单个数字

#include <iostream>


using namespace std;

int n,kase = 0,num[18+1];

long long int res;
int main(){
    while(cin >> n){
        kase++;
        for(int i = 0;i<n;i++){
            cin >> num[i];
        }
        res = 0;//init
        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                long long int tmp = 1;
                for(int k = i;k<=j;k++){
                    tmp *= num[k];
                }
                if(tmp>res)
                    res = tmp;
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n",kase,res);
    }
}
