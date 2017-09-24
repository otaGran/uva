//
// Created by beans on 2017/1/11.
//
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
set<string> s;

int main(){
    string x;

    int start = 0,end = 0;
    while(cin >> x){
        s.insert(x);
    }
    //printf("%d",s.size());
    for (set<string>::iterator it = s.begin();it!=s.end();it++) {
        //cout << i << " ";
        int len = (*it).length();
        for (int j = 0; j < len-1; ++j) {
            string s1 = (*it).substr(0, j+1);
            string s2 = (*it).substr(j+1, len-j);
            if(s.find(s1) != s.end() && s.find(s2) != s.end()) {
                cout << (*it) << endl;
                break;
            }
        }
    }
}