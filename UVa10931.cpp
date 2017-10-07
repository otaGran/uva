//
// Created by beans on 3/20/2017.
//
#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n==0)
            return 0;
        printf("The parity of ");
        int sum = 0;
        int res[10000],cnt = 0;
        while(n){
            res[cnt++] = n % 2;
            sum += n % 2;
            n/=2;
        }
        for (int i = cnt-1; i >=0; --i) {
            cout << res[i];
        }
        printf(" is %d (mod 2).\n",sum);


    }

}