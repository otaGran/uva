//
// Created by beans on 4/9/2017.
//
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

struct student{
    int awaken,sleeping,initial,total,now,left;
};

student st[10+1];
int n;
int cbt;

bool checked(){
    cbt = 0;
    for (int i = 0; i < n; ++i) {
        if(!st[i].now)
            cbt++;
    }
    if(cbt==n)
        return true;
    else
        return false;

}

void gothrough(){

    for (int i = 0; i < n; ++i) {
        if(st[i].left==0){
            if(st[i].now){//sleeping
                st[i].now = 0;
                st[i].left = st[i].awaken;
            }else{
                if(n-cbt>cbt){
                    st[i].now = 1;
                    st[i].left = st[i].sleeping;
                }
            }
        }
        if(st[i].left!=0)
            st[i].left--;
    }
}

int main(){
    int cnt = 0;//,n;
    while(cin >> n){
        if(n==0)
            return 0;
        printf("Case %d: ",++cnt);
        for (int i = 0; i < n; ++i) {
            cin >> st[i].awaken >> st[i].sleeping >> st[i].initial;
            st[i].total = st[i].awaken + st[i].sleeping;
            st[i].now = (st[i].initial<=st[i].awaken?0:1);
            if(st[i].now)
                st[i].left = st[i].sleeping - st[i].initial + st[i].awaken;
            else
                st[i].left = st[i].awaken - st[i].initial;
            //cout << st[i].now << " left : " << st[i].left << endl;
        }
        int ok = 0;
        for (int j = 1; j < 100000; ++j) {
            if(checked()){
                ok = 1;
                cout << j;
                break;
            }
            gothrough();


        }
        if(!ok)
         cout << "-1";
        cout << endl;
    }
}