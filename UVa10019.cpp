//
// Created by beans on 3/20/2017.
//
#include <iostream>
#include <cmath>

using namespace std;

int cal(int target){
    int res[10000],cnt = 0,cc = 0;
    while(target){
        res[cnt++] = target%2;
        target /= 2;
        if(res[cnt-1]==1)
            cc++;
    }
    //find first zero
    for (int i = cnt-1; i>=0;i--) {
        //cout << res[i];
    }
    return cc;
}

int main(){
    int time;
    cin >> time;
    while(time--){
        int n;
        cin >> n;
        int d_res = n,h_res = 0;
        while(n) {
            h_res *= 16;
            h_res += n%10;
            n /= 10;
        }

        cout << cal(d_res) <<" " << cal(h_res) << endl;
    }
}
