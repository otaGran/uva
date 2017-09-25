//double判断整数精度控制1e-10
// Created by beans on 2017/9/24.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long int  n,m;

int main(){
    while(cin >> n >>m){
         double res = log(n)/log(m);
        //cout << res << endl;
        //cout << (int)res << endl;
        if(m<=1||n<m){
            cout << "Boring!" << endl;
            continue;
        }
        if(ceil(res)-res<1e-10||res-floor(res)<1e-10){
            while(n!=1) {
                cout << n << " ";
                n /= m;
            }
            cout << "1" << endl;
        }else{
            cout << "Boring!" << endl;
        }

    }
}