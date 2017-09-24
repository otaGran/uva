//
// Created by beans on 2017/8/25.
//
#include <iostream>
#include <cstring>
#include <stack>
#include <sstream>

using namespace std;

const int maxn = 100;
int G[maxn][maxn],vis[maxn][maxn];
int n;
stack<string> st;


void euler(int u){
    for(int v = 0;v < n;v++)            //遍历终点 
        if(G[u][v] &&  !vis[u][v]){     //确认存在边且未访问
            vis[u][v] = vis[v][u] = 1;  //访问标志（无向图）
            euler(v);                   //递归寻找下一条边
            //printf("%d %d\n",u,v);
            string x;
            stringstream out;
            out <<  u << "->" << v << "\n";
            //sprintf(x,"%d->%d\n",u,v);
            st.push(out.str());
        }
}

int main(){
    int a,b;
    while(scanf("%d",&n)==1&&n) {
        memset(vis,0,sizeof(vis));
        memset(G,0,sizeof(G));
        while (scanf("%d%d", &a, &b) == 2 && (a || b)) {
            G[a][b] = G[b][a] = 1;
        }
        euler(1);                   //访问起点
        while(!st.empty()){
            cout << st.top();
            st.pop();
        }
    }
}

