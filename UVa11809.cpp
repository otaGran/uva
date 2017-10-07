//
// Created by beans on 4/8/2017.
//
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int first;

    int mantissa[15];
    int power;
    double res[10][31];
    long long res_b[10][31];
    double a,c,x;
    long long b,d;
    for(int i = 0;i<=9;i++){
        for (int j = 1; j <= 30; ++j) {
            a = 1 - pow(2,-i-1);
            b = pow(2,j)-1;
            x = log10(a)+b*log10(2);
            d = floor(x);
            c = pow(10,x-d);
            res[i][j] = c;
            res_b[i][j] = d;

        }
    }
    while(first = getchar() - '0'){
        getchar();//for "."
        double mt = first;
        for (int i = 1; i < 16; ++i) {
            mantissa[i] = getchar() - '0';
            mt += (double)mantissa[i] * pow(10.0,-1.0*i);
            //printf("%.15lf\n",mt);
            // cout << mantissa[i] << endl;
        }
        getchar();//for "e"
        cin >> power;
        getchar();//for "\n"
        if(power==0&&mt==0)
            return 0;
        for(int i = 0;i<=9;i++){
            for (int j = 1; j <= 30; ++j) {
                if(mt<=res[i][j]+0.0000005&&mt>=res[i][j]-0.0000005&&power==res_b[i][j])
                    cout << i << " " << j << endl;

            }
        }
        //max_E(power,mt);

        //cout << power << endl;

    }
}