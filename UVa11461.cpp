//
// Created by beans on 3/16/2017.
//
#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int a,b;
    while (cin >> a >> b){
        if(a==0&&b==0)
            return 0;
        int cnt = 0;
        for (int i = a; i <= b; ++i) {
            int tmp = sqrt((double)i);
            if(i==tmp*tmp)
                cnt++;
        }
        cout << cnt << "\n";
    }
}
