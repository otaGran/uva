//
// Created by beans on 3/13/2017.
//
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

string cal(string tmp){
    int tmp_res = 0;
    for (int i = 0; i < tmp.length(); ++i) {
        tmp_res += tmp[i] - '0';
    }
    string res;
    stringstream ss(res);
    ss << tmp_res;
    return ss.str();

}

int main(){
    string s;
    while(cin >> s){
        while(s.length()>1){
            s = cal(s);
        }
        if(s[0]=='0')
            return 0;
        cout << s << "\n";
    }
}

