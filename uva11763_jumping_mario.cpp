//
// Created by beans on 2016/12/8.
//


#include <cstdio>
int num[50+1],time = 1,t;
void main(){
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int high = 0,low =0,pre;
        for (int i = 0; i < n; ++i) {
            int now;
            scanf("%d",&now);
            if(i!=0) {
                if (now > pre)
                    high++;
                if(now<pre)
                    low++;
            }
                pre = now;

        }
        printf("Case %d: %d %d\n",time++,high,low);

    }
}