//
// Created by beans_pc on 2/11/2018.
//
//Linear solution for maxsum problem
//O(n)

#include <iostream>

using namespace std;

int maxsum(int* A, int length){
    int sum[100];
    sum[0] = A[0];
    int minSum = sum[0],ans = sum[0];
    for(int i = 1;i < length;i++){
        sum[i] = sum[i-1] + A[i];
        if(sum[i] - minSum > ans)
            ans = sum[i] - minSum;
        if(sum[i] < minSum){
            minSum = sum[i];
        }
    }
    return ans;
}
int main(){
    int length, data[100];
    cin >> length;
    for(int i = 0;i < length;i++){
        cin >> data[i];
    }
    cout << maxsum(data,length);
}