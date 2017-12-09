//
// Created by beans_pc on 12/9/2017.
//
#include <iostream>
using namespace std;
int main(){
    int m,n;
    while(cin >> m >> n){
        if(m==n&&n==0)
            return 0;
        int res = 0;
        if(n==0||m==0)
            res = 0;
        else {
            if (m==1||n==1) {
                res = max(m,n);
            }
            else {
               if(m==2||n==2){
                   res = m*n/8*4+(m*n%8<=4?m*n%8:4);
               }
                else {
                    int tmp;
                    if (n % 2 == 0)
                        tmp = n / 2;
                    else
                        tmp = n / 2 + 1;
                    for (int i = 0; i < m; i++) {
                        if (i % 2 == 0)
                            res += tmp;
                        else
                            res += n - tmp;
                    }
                }

            }
        }
        printf("%d knights may be placed on a %d row %d column board.\n",res,m,n);
    }
}