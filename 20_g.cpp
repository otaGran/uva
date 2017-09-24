//
// Created by beans on 2017/1/20.
//
#include <iostream>

using namespace std;

int main(){
    int time;
    cin >> time;
    while(time--){
        int n;
        cin >> n;
        int num[n+1];
        for (int i = 1; i <= n ; ++i) {
            cin >> num[i];
        }
        int l,r,q;
        cin >> q;
        for (int j = 0; j < q; ++j) {
            cin >> l >> r;
            int max = num[l];
            for (int i = l; i <= r; ++i) {
                if(num[i]>max)
                    max = num[i];
            }
            cout << max << "\n";
        }
    }
}