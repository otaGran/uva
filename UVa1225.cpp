//
// Created by beans on 2017/1/6.
//
#include <cstdio>
#include <cstring>
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        int tmp;
        int res[11];
        std::memset(res,0, sizeof(res));
        scanf("%d",&tmp);
        for(int i = 1;i<=tmp;i++){
            int ttt = i;
            while(ttt>0){
                res[ttt%10]++;
                ttt/=10;
            }
        }
        for (int j = 0; j < 9; ++j) {
            printf("%d ",res[j]);
        }
        printf("%d\n",res[9]);
    }
}
