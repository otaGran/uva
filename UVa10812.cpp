//
// Created by beans on 3/16/2017.
//
#include <iostream>

using namespace std;

int main(){
    int time;
    cin >> time;
    while(time--){
        int sum,diff;
        cin >> sum >> diff;
        int res = 1;
        for (int i = 0; i < sum/2+1; ++i) {
            if(abs((sum-i)-i)==diff){
                cout << sum-i << " " << i << "\n";
                res = 0;
                break;
            }
        }
        if(res == 1)
            cout << "impossible\n";
    }
}

