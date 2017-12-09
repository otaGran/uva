//
// Created by beans_pc on 12/9/2017.
//

#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int L,num[50],cnt = 0;
        cin >> L;
        for(int i = 0;i<L;i++){
            cin >> num[i];
        }

        for(int i = 0;i<L-1;i++){
            for(int j = i+1;j<L;j++){
                if(num[i]>num[j]){
                    int tmp = num[i];
                    num[i] = num[j];
                    num[j] = tmp;
                    cnt++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n",cnt);
    }
}