//
// Created by beans on 2016/12/8.
//

#include <cstdio>
#include <cstring>

int for_prime,a,b,isp[10001];
int cal(int j){
    for (int i = 2; i*i <= j; ++i) {
        if(j%i==0)
            return 0;
    }
    return 1;
}
void main(){
    memset(isp,0, sizeof(isp));
    for (int j = 0; j < 10001; ++j) {
            isp[j] = cal(j*j+j+41);
        //printf("%d %d\n",j,isp[j]);
    }
    while(scanf("%d %d",&a,&b)!=EOF) {
        //åprintf("%d %d\n",a,b);
        // total_prime = 0;
        for_prime = 0;
        for (int i = a; i <= b; ++i) {
            // int  res = i*i+i+41;
            if (isp[i])
                for_prime++;
        }
        //printf("%d\n", for_prime);
        printf("%.2f\n", for_prime * 1.0 / (b - a + 1) * 100 +1e-5);
    }



    return 0;
}