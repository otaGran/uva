//
// Created by beans on 2017/4/18.
//
#include <iostream>

using namespace std;

void inser_sort(int arr[],int len){
    int temp,j;
    for(int i = 1;i<len;i++){
        temp = arr[i];
        j = i-1;
        for(;j>=0&&arr[j]>temp;j--){
            arr[j+1] = arr[j];
        }
        arr[j+1] = temp;
    }
}


int main(){
    int num[] = {9,8,7,6,5,4,3,2,1};
    inser_sort(num,9);
    for (int i = 0; i < 9; ++i) {
        cout << num[i] << " ";
    }
}