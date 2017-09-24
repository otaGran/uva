#include <cstdio>

//
// Created by beans on 2016/12/8.
//
void main(){
    int n;
    scanf("%d",&n);
    int num[n],o ,e,ev = 0,odd = 0;
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d",&tmp);
        if(tmp%2==0) {

            ev++;
            e = i;
        }
        else {
            odd++;
            o = i;
        }
    }
    if(ev==1)
        printf("%d\n",e+1);
    else
        printf("%d\n",o+1);

}

