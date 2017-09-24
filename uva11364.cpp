//
// Created by beans on 2016/12/22.
//
#include <cstdio>
#include <algorithm>
using namespace std;
void main(){
    int time;
    scanf("%d",&time);
    while(time--){
        int n;
        scanf("%d",&n);
        int num[n];
        for(int i  = 0;i<n;i++)
            scanf("%d",&num[i]);
        sort(num,num+n);
        int mid = (num[0]+num[n-1])/2;
        int res = (mid - num[0])*2+(num[n-1]-mid)*2;
        printf("%d\n",res);
    }
}