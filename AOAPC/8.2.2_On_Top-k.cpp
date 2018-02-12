//
// Created by beans_pc on 2/11/2018.
//
#include <iostream>

using namespace std;

int parition(int* A,int lo,int hi){
    int pivot = A[hi];//pick an element
    int i = lo - 1;
    for(int j = lo;j < hi;j++){
        if(A[j] < pivot){
            i += 1;
            swap(A[i],A[j]);
        }
    }
    swap(A[hi],A[i+1]);
    return i+1;
}
int topK(int* A, int lo, int hi,int k){
    if(lo < hi){
        int p = parition(A,lo,hi);
        int howManyInHi = hi - p + 1;
        printf("lo: %d hi: %d p: %d\n",lo,hi,p);
        if(howManyInHi == k){
            return A[p];
        }
        if(howManyInHi > k) {
            topK(A, p, hi, k);
        }
        else {
            topK(A, lo, p - 1, k-howManyInHi);
        }
    }
}
int main(){
    int length,data[100],k;
    cin >> k >> length;
    for(int i = 0;i<length;i++){
        cin >> data[i];
    }


    cout << topK(data,0,length-1,k);
}