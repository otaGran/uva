//单向亚瑟环 指定最后幸存者 求最小间隔
// 注意:第一个一定要kill
// Created by beans on 2017/9/25.
//
#include <iostream>
#include <cstring>
using namespace std;


int n;
int vis[100+10];

bool ch(int i){
    //cout << "every : " <<i <<endl;
    //cout << endl;
    memset(vis,0, sizeof(vis));
    int cnt = 0,x = 2,total_Cnt = 1,ok = 1;
    vis[1] = 1;
    while(total_Cnt<n-1){
        if(x==n+1)
            x = 1;
        if(!vis[x])
            cnt++;
        if(cnt==i&&!vis[x]){
            if(x == 13)
                return false;
            vis[x] = 1;
            total_Cnt++;
            cnt = 0;
            //cout << "fucked: " << x<<endl;
        }
        //cout << total_Cnt <<" " << x <<endl;
        x++;
    }
    //cout << "res " << ok << endl;
    return true;

}

int slove() {

    for (int i = 1; i <= n; i++) {
        if (ch(i))
            return i;

    }
}
int main(){
    while(cin >> n){
        if(!n)
            return 0;
        cout << slove() << endl;
    }
}
