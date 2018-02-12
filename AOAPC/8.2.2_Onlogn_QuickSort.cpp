//
// Created by beans_pc on 2/11/2018.
//
#include <iostream>

using namespace std;

int parition(int* A, int lo,int hi){
    int pivot = A[hi];
    int i = lo - 1;
    for(int j = lo;j<hi;j++){
        if(A[j] < pivot){
            i += 1;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[hi]);
    return i+1;
}
void quickSort(int* A, int lo, int hi){
    if(lo < hi){
        int p = parition(A, lo, hi);
        quickSort(A, lo, p-1);
        quickSort(A, p, hi);
    }
}

int main(){
    int length,data[100];
    cin >> length;
    for(int i = 0;i<length;i++)
        cin >> data[i];
    quickSort(data,0,length-1);

    for(int i = 0;i<length;i++)
        cout << data[i] << " ";
}