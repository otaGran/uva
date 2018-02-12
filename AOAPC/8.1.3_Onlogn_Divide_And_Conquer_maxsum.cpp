//
// Created by beans_pc on 2/10/2018.
//

#include <iostream>

using namespace std;

int maxsum(int* A,int x, int y){
    int v,L,R;
    if(y - x == 1)
        return A[x];
    int m = x + (y-x) / 2;
    int maxes = max(maxsum(A, x, m),maxsum(A, m, y));

    v = 0;
    L = A[m-1];
    for(int i = m-1;i>=x;i--){
        L = max(L,v += A[i]);
        printf("$$$$$$$$$$v: %d\n",v);
    }
    printf("@@@v: %d\n",v);


    v = 0;
    R = A[m];
    for(int i = m;i < y;i++){
        R = max(R, v += A[i]);
    }

    printf("%d %d L: %d   R: %d\n",x,y,L,R);
    return max(maxes,L+R);
}

int main(){
    int length;
    int A[100];
    cin >> length;
    for(int i = 0;i<length;i++) {
        cin >> A[i];
        cout << A[i] << endl;
    }

    cout <<endl << maxsum(A,0,length);
}
