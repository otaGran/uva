//
// Created by beans on 2017/9/23.
//

#include <iostream>

using namespace std;
int mr = 1;

int fuck(int x){
    int cnt = 1;
    while(x!=1){
        cnt++;
        if(x%2==1)
            x = 3*x+1;
        else
            x = x / 2;
    }
    return cnt;
}

int main(){
    int a,b;
    while(cin >> a >> b){
        mr = 1;
        for(int i = (a<b?a:b);i<=(a>b?a:b);i++){
            if(fuck(i)>mr)
                mr = fuck(i);
        }
        cout << a << " " << b <<  " " << mr << endl;
    }
}