//
// Created by beans on 2016/12/8.
//

#include <cstdio>
#include <cstring>

//typedef long long __int64;
void main(){
    __int64 n,move = 0;
    __int64 num[300000+100],vis[300000+100];
    memset(vis,0, sizeof(vis));
    scanf("%I64d",&n);
    for (__int64 i = 0; i <n; ++i) {
        scanf("%I64d",&num[i]);
        if(num[i]<1) {
            move+=1-num[i];
            num[i]=1;
        }
        if(num[i]>n){
            move+=num[i]-n;
            num[i]=n;
        }
        vis[num[i]] += 1;
    }
    /*
    for (int j = 1; ; ++j) {
        if(vis[j]>1) {
            move += vis[j] - 1;
            vis[j + 1] += vis[j] - 1;
            vis[j] = 1;
        }
        if(vis[j]==0)
            break;

    }
    for (int k = n; ; --k) {
        if(vis[k]>1) {
            move += vis[k] - 1;
            vis[k - 1] += vis[k] - 1;
            vis[k] = 1;
        }
        if(vis[k]==0)
            break;
1234
    }
     */
    //printf("%d\n",move);
    for(__int64 i = 1,f = n;i<=n/2;i++,f--){
       // printf("%d ",vis[i]);
        if(vis[i]>1){
            __int64 tmp = vis[i]-1;
            //move += tmp;
            vis[i] = 1;
            for (__int64 j = 1; ; ++j) {
                if(i-j>=1&&vis[i-j]==0) {
                    move+=j;
                    tmp -= 1;
                    vis[i - j] = 1;
                    if(tmp==0)
                        break;
                }
                if(i+j<=n&&vis[i+j]==0) {
                    move+=j;
                    tmp -= 1;
                    vis[i+j] = 1;
                    if(tmp==0)
                        break;
                }
            }
        }


        if(vis[f]>1){
            __int64 tmp = vis[f]-1;
            //move += tmp;
            vis[] = 1;
            for (__int64 j = 1; ; ++j) {
                if(i-j>=1&&vis[i-j]==0) {
                    move+=j;
                    tmp -= 1;
                    vis[i - j] = 1;
                    if(tmp==0)
                        break;
                }
                if(i+j<=n&&vis[i+j]==0) {
                    move+=j;
                    tmp -= 1;
                    vis[i+j] = 1;
                    if(tmp==0)
                        break;
                }
            }
        }
        //printf("%d ",vis[i]);
    }
    printf("%I64d\n",move);
    return 0;
}