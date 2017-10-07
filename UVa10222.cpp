//
// Created by beans on 3/13/2017.
//
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    string tmp = "qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    string xx;
    getline(cin,xx);
    for (int i = 0; i < xx.length(); ++i) {
        if(xx[i]>=65&&xx[i]<=90)
            xx[i] += 32;
        if(xx[i]==' ')
            cout << " ";
        else
            cout << tmp[tmp.find(xx[i])-2] << "";
    }
    cout << "\n";
}
