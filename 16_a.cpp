//
// Created by beans on 2017/1/16.
//
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int m,n,r,c;
        cin >> n >> m >> r >> c;
        int res = r ^ c;
        res ^= n - r -1;
        res ^= m - c -1;
        if(res)
            cout << "Gretel\n";
        else
            cout << "Hansel\n";
    }
}
