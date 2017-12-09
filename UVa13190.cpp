//
// Created by beans_pc on 12/9/2017.
//

#include <iostream>
#include <stdlib.h>
#include <set>

using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k,fre[3000+10];
        char name[3000+10][16];
        scanf("%d%d",&n,&k);
        set<pair<int,int>> S;
        for(int i = 0;i<n;i++){
            scanf("%s%d",name[i],&fre[i]);
            S.insert(make_pair(fre[i],i));
        }
        int cnt = 0,now_time=1;
       for(int i = 0;i<k;i++){
           pair<int,int> t = *S.begin();
           S.erase(t);
           printf("%d %s\n",t.first,name[t.second]);
           S.insert(make_pair(t.first+fre[t.second],t.second));
       }
    }
}