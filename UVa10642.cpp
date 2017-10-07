//
// Created by beans on 3/22/2017.
//
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x,y,tar_x,tar_y;
        long long cnt = 0;
        cin >> x >> y >> tar_x >> tar_y;
        //cout << x << y << tar_x << tar_y;
        //处理中间完整链
        cnt = (tar_x+tar_y-x-y)*((x+y)+1+(tar_x+tar_y))/2;

       // x = 0;
       // tar_y = tar_x+tar_y;
        //掐头去尾
        cnt += tar_x - x;
        printf("Case %d: %lld\n",i,cnt);
    }
}


