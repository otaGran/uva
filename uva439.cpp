#include <cstdio>
#include <cstring>
#include <queue>
//bfs
//国际象棋中的knight走2*3格子中的对角线，通过bfs求出从某点到另一点的最小步数
//状态数：8 空间大小：8*8
//注意input的col实际从1开始数！！！
//c++不支持转型！
// Created by beans on 2016/12/4.
//
char s[10];
int goal_int,dc[] = {1,1,2,2,-1,-1,-2,-2},dr[] = {2,-2,1,-1,2,-2,1,-1};
struct Node{
    int row,col,dis;

    Node(int row, int col, int dis) : row(row), col(col), dis(dis) {

    }

};
int vis[100];
int bfs(){
    std::queue<Node> q;
    q.push(Node(s[0]-'a',s[1]-'1',0));
    //printf("%d %d\n",q.front().row,q.front().col);
    while(!q.empty()){
        Node u = q.front();
        q.pop();
        //printf("%d %d\n",u.row,u.col);
        if(goal_int==u.row*10+u.col)
            return u.dis;
        for(int i = 0;i<8;i++){
            Node nxt = u;
            nxt.dis = u.dis+1;
            nxt.row+=dr[i];
            nxt.col+=dc[i];
            if(nxt.row>7||nxt.row<0||nxt.col>7||nxt.col<0)
                continue;
            if(vis[nxt.row*10+nxt.col])
                continue;
            vis[nxt.row*10+nxt.col] = 1;
            q.push(nxt);
        }
    }
    return -1;

}
void init(){
    int tx = s[3]-'a';
    int ty = s[4]-'1';
    goal_int = tx*10+ty;
    //printf("s%d %d %d\n",s[3]-'a',s[4]-'0',goal_int);
}
void main(){
    while(gets(s)){
        //printf("%s\n",s);
        memset(vis,0, sizeof(vis));
        init();
        //bfs();
        printf("To get from %c%c to %c%c takes %d knight moves.\n",s[0],s[1],s[3],s[4],bfs());
    }
    return 0;
}