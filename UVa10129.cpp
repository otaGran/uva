//
// Created by beans on 2017/9/22.
//
#include <iostream>
#include <set>
#include <cstring>

using namespace std;

int kase,n;
char s[1000+10];
int front,rear;
int cnt_degree[26][2];
set<int> cnt_node;
int G[26][26],vis[26];
int cnt_node_tmp = 0;
int fuck = 0;

void dfs(int u){//求忽略方向的底图连通
    cnt_node_tmp++;
    vis[u] = 1;
    for(int v= 0;v < 26 ;v++){
        if(!vis[v]){
            if(G[u][v]||G[v][u])
                dfs(v);
        }
    }
}

void euler(){//判断是否存在欧拉path
    for(int v = 0;v<26;v++){
       int tmp = abs(cnt_degree[v][0]-cnt_degree[v][1]);
        //cout << tmp << endl;
        if(tmp==1)
            fuck++;
        if(tmp > 1)
            fuck+=100;
    }
}


int main(){
    cin >> kase;
    while(kase--){
        cin >> n;
        fuck = 0;
        memset(G,0, sizeof(G));
        cnt_node.clear();
        memset(vis,0, sizeof(vis));
        memset(cnt_degree,0, sizeof(cnt_degree));
        cnt_node_tmp = 0;
        while(n--){
            scanf("%s",s);
            front = s[0]-97;
            rear = s[strlen(s)-1]-97;
            cnt_degree[front][0]++;//in_degree++
            cnt_degree[rear][1]++;//out_degree++
            cnt_node.insert(front);
            cnt_node.insert(rear);
            G[front][rear] = 1;
        }
        dfs(front);
    /*
        cout << cnt_node_tmp << endl;
        cout << cnt_node.size() << endl;
        if(cnt_node_tmp!=cnt_node.size())
            cout << "no " ;
        else
            cout << "yes " ;

*/
        euler();
        //cout << fuck << endl;
        if(cnt_node_tmp==cnt_node.size()&&fuck<=2)//底图连通且最多有两个点出入度绝对值为1
            cout << "Ordering is possible." << endl;
        else
            cout << "The door cannot be opened." << endl;



    }
}

