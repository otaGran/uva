//
// Created by beans on 2016/11/22.
//only for demo
//will not been accepted by uva
//

#include <cstdio>
#include <algorithm>
using namespace std;
bool isP(int i);
void main(){
    //printf("hello");
    int n;
    scanf("%d",&n);
    bool isp[n*2];
    int A[n];
    for(int i = 2;i<=n*2;i++)
        isp[i] = isP(i);
    for(int i = 0;i<n;i++)
        A[i] = i + 1;
    do{
        int ok = 1;
        for(int i = 0;i<n;i++)
            if(!isp[A[i]+A[(i+1)%n]]){
                ok = 0;
                break;
            }
        if(ok){
            for(int i = 0;i<n;i++)
                printf("%02d ",A[i]);
            printf("\n");
        }
    }while(next_permutation(A+1,A+n));

}
bool isP(int n){
    for(int i = 2;i<n;i++){
        if(n%i==0)
            return false;
    }
    return true;
}//
// Created by beans on 2016/11/22.
//

