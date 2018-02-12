//
// Created by beans_pc on 2/12/2018.
//左闭右开区间 注意边界条件
//

#include <iostream>

using namespace std;


int bsearch(int* A, int x, int y, int target){

    int m;
    while(x < y){
        m = x + (y-x)/2;
        if(A[m] == target)
            return m;
        else{
            if(A[m] < target){
                x = m+1;
            }
            else{
                y = m;
            }
        }
    }


    return -1;
}
int main(){
    int target,length,data[100];
    cin >> target >> length;
    for(int i = 0;i<length;i++){
        cin >> data[i];
    }

    cout << bsearch(data,0,length,target);
}
