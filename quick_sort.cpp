//
// Created by beans on 2017/4/18.
//
#include <iostream>
using namespace std;

typedef struct _Range {
    int start, end;
} Range;
Range new_Range(int s, int e) {
    Range r;
    r.start = s;
    r.end = e;
    return r;
}
void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}
for(int i = 0;i<len-1;i++){ //这里的每次循环是一个pass
    for(int j = i+1;j<len;j++){
        if(num[i]<num[j]){
            swap!;
        }
    }
}

void quick_sort_recur(int arr[], int start,int end) {
    if(start >= end)
        return;
    int mid = arr[end];
    int left = start,right = end - 1;
    while(left < right){
        while(arr[left]<mid&&left<right)
            left++;
        while(arr[right]>=mid&&left<right)
            right--;
        swap(&arr[left],&arr[right]);
    }
    if(arr[left]>=arr[end])
        swap(&arr[left],&arr[end]);
    else
        left++;
    if(left)
        quick_sort_recur(arr,start,left-1);
    quick_sort_recur(arr,left+1,end);
}

void quick_sort(int arr[],int len){
    quick_sort_recur(arr,0,len-1);
}

int main(){
    int num[] = {9,8,7,6,5,4,3,2,1};
    quick_sort(num,9);
    for (int i = 0; i < 9; ++i) {
        cout << num[i] << " ";
    }
}