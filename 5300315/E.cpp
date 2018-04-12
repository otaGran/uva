//
// Created by beans on 2018/3/16.
//



////todo
#include <iostream>

using namespace std;

int main(){
    int n,m,map[55][55];
    scanf("%d%d",&n,&m);
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            scanf("%d",&map[i][j]);


    for(int i = 0;i<n;i++){
        for (int j = 0; j < m ; ++j) {
            if((i==0||i==n-1||j==0||j==m-1)&&map[i][j]==1){
                cout << "2" << endl;
                return 0;
            }

        }
    }
    cout << "4" << endl;


}

