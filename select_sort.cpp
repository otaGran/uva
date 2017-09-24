//
// Created by beans on 2017/4/18.
//

#include <iostream>
using namespace std;

void select_sort(int arr[],int len){
    int i,j,min,temp;
    for(i = 0;i<len-1;i++){
        min = i;
        for(j= i+1;j<len;j++){
            if(arr[min]>arr[j])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

    }
}

int main(){
    int num[] = {9,8,7,6,5,4,3,2,1};
    select_sort(num,9);
    for (int i = 0; i < 9; ++i) {
        cout << num[i] << " ";
    }
}