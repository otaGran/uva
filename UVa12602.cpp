//
// Created by beans on 2017/9/25.
//

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int N;
string tmp;
int main(){
    cin >> N;
    while(N--){
        int al_v = 0,di_v = 0;
        cin >> tmp;
        for(int i = 0;i<3;i++)
            al_v = al_v*26+tmp[i]-'A';
        for(int i = 4;i<8;i++)
            di_v = di_v*10+tmp[i]-'0';
        if(abs(al_v - di_v)<100)
            cout << "nice" << endl;
        else
            cout << "not nice" << endl;
    }
}