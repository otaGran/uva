//计算两端点值 根据奇偶判断上升还是下降
// Created by beans on 2017/9/24.
//

#include <iostream>

using namespace std;
int main(){
    int n;
    while(cin >> n){
        cout << "TERM " << n << " IS ";
        int res = 1,value = 1;
        while(res<n)
            res += ++value;
        //cout << res << " " << value << endl;
        int diff = abs(res - n);
        //cout << diff << endl;
        if(value%2==0)
            cout << value - diff << "/" << diff+1 << endl;
        else
            cout <<  diff+1 << "/" << value - diff << endl;
    }
}