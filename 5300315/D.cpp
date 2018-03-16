#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n,k;
    long long int num[100005],minRes = pow(10,9),maxRes = -1*pow(10,9);
    scanf("%d%d",&n,&k);
    for(int i = 0;i<n;i++) {
        scanf("%lld", &num[i]);
        maxRes = max(maxRes, num[i]);
        minRes = min(minRes, num[i]);
    }
    if(k==1)
        cout << minRes;
    else {
        if (k == 2)//k==2时,无论怎么切两个sub必包含第一个和最后一个
            cout << max(num[0],num[n-1]);
        else //k>=3
            cout << maxRes;
    }
    return 0;
}