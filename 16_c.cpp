
#include <string.h>
#include <iostream>
using namespace std;

int fib[21];
int sg[1001];//
bool mex[1001];//mex{}

void get_sg(int n) {
    int i, j;
    memset(sg, 0, sizeof(sg));
    for (i = 1; i <= n; i++) {
        memset(mex, 0, sizeof(mex));
        for (j = 1; fib[j] <= i; j++)
            mex[sg[i - fib[j]]] = 1;
        for (j = 0; j <= n; j++)
            if (!mex[j])
                break;
        sg[i] = j;
    }
}

int main() {
    int i, m, n, p;
    //开fib
    fib[0] = 1, fib[1] = 1;
    for (i = 2; i < 21; ++i)
        fib[i] = fib[i - 1] + fib[i - 2];
    get_sg(1000);
    while (cin >> m >> n >> p && m && n && p){
        if((sg[m]^sg[n]^sg[p])==0)
            cout << "Nacci\n";
        else
            cout << "Fibo\n";

    }
    return 0;
}