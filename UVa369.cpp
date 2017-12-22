//
// Created by beans on 2017/11/10.
//

#include <iostream>
#include <cstdio>

using namespace std;

long int cal(int n,int m){
    if(n==m)
        return 1;
    long int up = 1;
    for(int i = max(m,n-m)+1,j = 1;i<=n;i++,j++)
        up = up*i/j;


    return up;
}

int main(){
    int n,m;
    while(cin >> n >>m){
        if(n==0&&m==0)
            return 0;
        printf("%d things taken %d at a time is %ld exactly.\n",n,m,cal(n,m));
    }
}

