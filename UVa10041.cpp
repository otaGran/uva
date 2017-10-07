//
// Created by beans on 3/13/2017.
//
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){

    int time;
    cin >> time;
    while (time--){
        int how_many;
        cin >> how_many;
        int tmp,sum = 0,num[how_many];
        for (int i = 0; i < how_many; ++i) {
            cin >> num[i];
            sum += num[i];
        }
        int res = 0;
        sort(num,num+how_many);
        int v = num[how_many/2];
        for (int j = 0; j < how_many; ++j) {

            res += abs(num[j]-v);
        }
        printf("%d\n",res);

    }
}