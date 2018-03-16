//
// Created by beans on 2018/3/16.
//

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    string num;
    int k,startIndex,ansIndex;
    cin >> num >> k;
    for (int i = 0; i < num.size(); i++) {
        startIndex = ansIndex = i;
        for (int j = i + 1; j < min((int) num.size(), k + i + 1); j++) {
            if (num[j] > num[ansIndex]) {
                ansIndex = j;
            }
        }
        if (ansIndex != startIndex) {//successfully find large bit
            for (int x = ansIndex; x > startIndex; x--)
                swap(num[x], num[x - 1]);
            k -= ansIndex - startIndex;
            //cout << k<<endl;
        }
    }
    cout << num << endl;
}

