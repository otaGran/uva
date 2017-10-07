//
// Created by beans on 3/20/2017.
//贪心
//while n <> 0
//  找到第一个不大于自己的Fib数字Fk
//  得到新的n = n - Fk
//end while
//
//输出所有找到的Fk
//
#include <iostream>
#include <cstring>


using namespace std;

int ans[50],fib[50];

int main(){
    int time;
    cin >> time;
    fib[0] = fib[1] = 1;
    for (int i = 2; i < 40; ++i) {
        fib[i] = fib[i-1]+fib[i-2];
    }
    while(time--){
        int n;
        cin >> n;
        cout << n <<" = ";
        int ok = 0;
        memset(ans,0,sizeof(ans));
        for (int i = 39; i>0;i--) {
            if(fib[i]<=n){
                ok = 1;
                ans[i] = 1;
                n -= fib[i];
            }
            if(ok)
                cout << ans[i];
        }
        cout << " (fib)\n";

    }
}

