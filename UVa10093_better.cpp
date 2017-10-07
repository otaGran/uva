//
// Created by beans on 3/20/2017.
//
#include <iostream>

using namespace std;

string list = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int maps[128];

int re(string tmp){
    int min = 2;
    //find min char
    for (int i = 0; i < tmp.length(); ++i) {
        if(maps[tmp[i]]>=min)
            min = maps[tmp[i]]+1;
    }
    for (int j = min; j < 63; ++j) {
        int r = 0;
        for (int i = 0; i < tmp.length(); ++i) {
            r = (r*j+maps[tmp[i]])%(j-1);
        }
        if(r==0)
            return j;
    }

    return -1;

}

int main(){
    string tmp;
    for (int i = 0; i<list.length(); i++) {
        maps[list[i]] = i;

    }
    while(cin >> tmp){
        int res = re(tmp);
        if(res==-1)
            cout << "such number is impossible!\n";
        else
            cout << res << endl;
    }
}
