//
// Created by beans_pc on 2/11/2018.
//O(nlogn) Merge Sort
#include <iostream>
#include <cstring>

using namespace std;

void merge_sort(int* A,int x,int y,int* T){
    //cout << "hi" << endl;
    if(y-x==1)
        return;
    int m = x + (y-x)/2;
    merge_sort(A,x,m,T);
    merge_sort(A,m,y,T);

    int p = x, q = m, i = x;
    while(p < m || q < y){ //任意一组非空===》 继续
        if(q >= y || (p < m && A[p] <= A[q]))//第二组空 或者 （第二组非空 且 第一组小于第二组）
            T[i++] = A[p++];
        else
            T[i++] = A[q++];
    }
    for(i = x;i < y;i++)
        A[i] = T[i];
}

int main(){
    int length;
    int data[10000],tmp[10000];
    memset(tmp,0, sizeof(tmp));
    cin >> length;
    for(int i = 0;i<length;i++){
        cin >> data[i];
    }
    for(int i = 0;i<length;i++){
        cout << data[i] << " ";
    }
    cout << endl;
    merge_sort(data,0,length,tmp);

    for(int i = 0;i<length;i++){
        cout << data[i] << " ";
    }
}