//
// Created by beans on 3/16/2017.
//
#include <iostream>

using namespace std;

long long num[100+1][100+1],n;

bool check(int x,int y){
    int co_x = n-1-x;
    int co_y = n-1-y;
    if(num[x][y]==num[co_x][co_y])
        return 1;
    else
        return 0;
}

int main(){
    int time,cnt = 0;
    cin >> time;
    while(time--){
        string tmp;
        int ok = 1;
        cin >> tmp >> tmp >> n;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> num[i][j];
                if(num[i][j]<0)
                    ok = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(!check(i,j))
                    ok = 0;
            }
        }
        printf("Test #%d: ",++cnt);
        if(ok)
            printf("Symmetric.\n");
        else
            printf("Non-symmetric.\n");


    }
}