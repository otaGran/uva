//
// Created by beans on 2017/1/11.
//why (n-1)????
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
string filesname[100+1];
void print(string s,int length,char extra){
    cout << s;
    for (int i = 0; i < length - s.length(); ++i) {
        cout << extra;
    }
}

int main(){
    int n;
    while (cin >> n){
        int maxLength = 0;
        for (int i = 0; i < n; ++i) {
            cin >> filesname[i];
            maxLength = max((int)filesname[i].length(),maxLength);
        }
        sort(filesname,filesname+n);
        int cols = (60-maxLength)/(maxLength+2)+1;
        int rows = (n-1)/cols+1;
        int count = 0;
        for (int j = 0; j < 60; ++j) {
            cout << '-';
        }
        cout << '\n';
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int idx = j*rows+i;
                if(idx<n)
                    print(filesname[idx],j==cols-1?maxLength:maxLength+2,' ');
            }
            cout << '\n';
        }


    }

}
