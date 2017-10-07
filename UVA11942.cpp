#include <cstdio>

//
// Created by beans on 2016/12/8.
//
int t,num[10];
void main(){
    scanf("%d\n",&t);
    printf("Lumberjacks:\n");
    while(t--){
        for (int i = 0; i < 10; ++i) {
            scanf("%d",&num[i]);
        }
        int ok = 1;
        if(num[0]<num[1]){
            for (int i = 0; i < 9; ++i) {
                for (int j = i+1; j < 10; ++j) {
                    if(num[i]>num[j])
                        ok = 0;

                }
            }
        }
        else{
            for (int i = 0; i < 9; ++i) {
                for (int j = i+1; j < 10; ++j) {
                    if(num[i]<num[j])
                        ok = 0;

                }
            }

        }
        if(ok)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
}