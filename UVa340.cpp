//
// Created by beans on 2017/1/6.
//
#include <cstdio>
#include <cstring>
int main(){
    int n,count = 0;
    while(scanf("%d",&n)==1&&n){
        int ans[n],guess[n];
        for (int j = 0; j < n; ++j) {
            scanf("%d",&ans[j]);
        }
        printf("Game %d :\n",++count);

        for(;;) {
            int a = 0,b = 0;
            for (int i = 0; i < n; i++) {
                //int tmp;
                scanf("%d", &guess[i]);
                if (ans[i] == guess[i])
                    a++;
            }
            for (int j = 1; j <= 9; ++j) {
                int c1 = 0,c2 = 0;
                for (int x = 0; x < n; ++x) {
                    if(guess[x]==j)
                        c2++;
                    if(ans[x]==j)
                        c1++;
                }
                if(c1<c2)
                    b+=c1;
                else
                    b+=c2;
            }
            if(guess[0]==0)
                break;
            printf("    (%d,%d)\n",a,b-a);
        }
    }
}
