#include <cstdio>
#include <cmath>

//
// Created by beans on 2016/12/8.
//
//typedef long long __int64;

bool isp(__int64 tmp){
    if(tmp<2)
        return false;
    for (int i = 2; i*i <=tmp ; ++i) {
        if(tmp%i==0)
            return false;

    }
    return true;
}


bool istp(__int64 tmp){
    //int ok = 0;
    if(tmp<=3)
        return false;
    double x = sqrt((double)tmp);
    if(x!=(__int64)x)
        return false;
    return isp((__int64)x);
}
void main(){
    int n;
    scanf("%d",&n);
    while(n--){
        __int64 tmp;
        scanf("%I64d",&tmp);
        //printf("%d",tmp);
        if(istp(tmp))
            printf("YES\n");
        else
            printf("NO\n");
    }
}

