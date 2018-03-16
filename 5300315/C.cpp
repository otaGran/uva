#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n,num[100005],test[100005],rep[100005],r = 0;
    memset(num,0, sizeof(num));
    memset(test,0, sizeof(test));
    memset(rep,0, sizeof(rep));

    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&num[i]);
        if(num[i]<=n&&test[num[i]]==0){
            test[num[i]] = 1;
        }
        else{
            num[i] = -1;
        }
    }

    /*
    int tt = 1;
    for(int i = 1;i<=n;i++){
        if(num[i]==-1){
            while(test[tt])
                tt++;
            num[i] = tt;
            test[tt] = true;
        }
    }
    for(int i = 1;i<n;i++)
        printf("%d ",num[i]);
    printf("%d\n",num[n]);

     */
    for(int i =  1;i<=n;i++){
        if(test[i] == 0)
            rep[r++] = i;
    }
    r = 0;
    for(int i  =1;i<n;i++)
        printf("%d ",(num[i]==-1?rep[r++]:num[i]));
    printf("%d\n",(num[n]==-1?rep[r++]:num[n]));


}