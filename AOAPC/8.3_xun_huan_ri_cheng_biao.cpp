//
// Created by beans_pc on 2/16/2018.
//循环日程表 

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;


void re_slove(int A[100][100],int sx, int sy, int k){
    if(k==0)
        return;
    else{
        int tmpk = k -1;
        A[sx][sy+(1<<tmpk)] = A[sx][sy] + (1<<tmpk);
        A[sx+(1<<tmpk)][sy] = A[sx][sy+(1<<tmpk)];
        A[sx+(1<<tmpk)][sy+(1<<tmpk)] = A[sx][sy];

        re_slove(A,sx,sy,k-1);
        re_slove(A,sx+(1<<tmpk),sy,k-1);
        re_slove(A,sx,sy+(1<<tmpk),k-1);
        re_slove(A,sx+(1<<tmpk),sy+(1<<tmpk),k-1);

    }


}

void slove(int k){
    int size = pow(2,k);

    int data[size][size];
    memset(data,0, sizeof(data));

    data[0][0] = 1;


    int tmpSize = 0;
    while(tmpSize < k){
        for(int i = 0;i<pow(2,tmpSize);i++){
            for(int j = 0;j<pow(2,tmpSize);j++){
                data[i][j+(int)pow(2,tmpSize)] = data[i][j] + (int)pow(2,tmpSize);
                data[i+(int)pow(2,tmpSize)][j] = data[i][j+(int)pow(2,tmpSize)];
                data[i+(int)pow(2,tmpSize)][j+(int)pow(2,tmpSize)] = data[i][j];
            }
        }
        tmpSize++;

    }
    for(int i = 0;i<(1<<k);i++){
        for(int j = 0;j<(1<<k);j++)
            printf("%2d ",data[i][j]);
        cout << endl;
    }
}


int main(){
    int k;
    cin >> k;
    slove(k);
    int data[100][100];
    memset(data,0, sizeof(data));
    data[0][0] = 1;
    re_slove(data,0,0,k);
    cout << endl;
    for(int i = 0;i<(1<<k);i++){
        for(int j = 0;j<(1<<k);j++)
            printf("%2d ",data[i][j]);
        cout << endl;
    }

}