//
// Created by beans on 2017/1/11.
//
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    string x;
    x.
    while(cin >> n&&n){
        vector<int> source;
        vector<int> dest;
        for (int i = 0; i < n; ++i) {
            int tmp;
            cin >> tmp;
            source.push_back(tmp);
            cin >> tmp;
            dest.push_back(tmp);
        }
        sort(source.begin(),source.end());
        sort(dest.begin(),dest.end());
        int flag  = 1;
        for (int j = 0; j < source.size(); ++j) {
            if(source[j]!=dest[j]){
                flag = 0;
                break;
            }
        }
        if(flag)
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
    }

}