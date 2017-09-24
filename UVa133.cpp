//
// Created by beans on 2017/1/9.
//
#include <cstdio>
#include <cstring>
int xxx[101];
int go(int dir,int start,int how,int n){
    //return 1;
    int res = start;
    while(true){
        //printf("%d\n",res);

        if(xxx[res]==1){
            //xxx[res] = 0;
            how--;
        }
        if(how==0)
            break;
        res = (res+dir+n)%n;
    }
    return res;
}
int main(){
    int n,k,m;
    while(scanf("%d%d%d",&n,&k,&m)==3&&n){
        //std::memset(xxx,1, sizeof(xxx));
       //memset(xxx,1, sizeof(xxx));
        for (int i = 0; i < n; ++i) {
            xxx[i] = 1;
        }
        //printf("%d %d %d",n,m,k);
        int count = n;
        int a = 0,b = n-1;
        //printf("%d",xxx[0]);
        //printf("%3d",go(-1,a,k,n));

        while(count>0){
            a = go(1,a,k,n);
            b = go(-1,b,m,n);
            if(count!=n)
                printf(",");
            if(a==b){
                count--;
                xxx[a] = 0;
                printf("%3d",a+1);
            } else{
                xxx[a] = 0;
                xxx[b] = 0;
                printf("%3d%3d",a+1,b+1);
                count-=2;
            }
        }

        printf("\n");
    }
}