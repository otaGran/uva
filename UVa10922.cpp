//
// Created by beans on 2017/11/10.
//
#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;

int check(string x,int cnt){
    int tmp = 0;
    for(int i = 0;i<x.size();i++){
        tmp += x[i]-'0';
    }
    if(tmp<10){
        if(tmp==9)
            return cnt+1;
        else
            return -1;
    }
    stringstream ss;
    ss << tmp;
    return check(ss.str(),cnt+1);
}

int main(){
    string x;
    while(cin >> x){
        if(x=="0")
            return 0;
        int res = check(x,0);
        if(res<0)
            cout << x << " is not a multiple of 9."<< endl;
        else
            cout << x <<" is a multiple of 9 and has 9-degree "<<res<<"."<<endl;

    }
}
