//
// Created by beans_pc on 2/16/2018.
//
#include <iostream>

using namespace std;



int my_upper_bound(int* A,int x,int y,int v){
    int m;
    while(x < y){
        m = x + (y-x)/2;
        if(A[m] <= v){
            x = m + 1;
        }else{
            y = m;
        }
    }
    return x;
}

int my_lower_bound(int* A,int x,int y,int v){
    int m;
    while(x < y){
        m = x + (y-x)/2;
        if(A[m]>=v){
            y = m;
        }else{
            x = m + 1;
        }
    }
    return x;
}

void my_range(int* A,int x,int y,int v){
    int lo = my_lower_bound(A,x,y,v);
    int hi = my_upper_bound(A,x,y,v);
    if(hi == lo)
        printf("v not exist\n");
    else
        printf("[%d,%d)\n",lo,hi);
}

int main(){
    int length,data[100], v;
    cin >> v >> length;
    for(int i = 0;i<length;i++){
        cin >> data[i];
    }

    printf("lowerBound: %d\n",my_lower_bound(data,0,length,v));

    printf("upperBound: %d\n",my_upper_bound(data,0,length,v));

    printf("range: ");
    my_range(data,0,length,v);
}