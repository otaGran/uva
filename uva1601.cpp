#include <cstring>
#include <queue>
#include <cstdio>
int w,h,n,head[256+100],start[3],goal[3],cnt,di[]={0,0,1,-1,0},dj[]={1,-1,0,0,0},vis[268][268][268];
char maze[16][17];

struct Node{
    int dis,state[3];

    Node(int dis, int a = -1,int b = -1,int c = -1) : dis(dis) {
            state[0] = a;
            state[1] = b;
            state[2] = c;
    }
};
struct Edge{
    int to,next;
};
Edge e[2000];
void add(int u,int v){
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void init(){
    memset(head,-1, sizeof(head));
    memset(goal,-1,sizeof(goal));
    memset(start,-1,sizeof(start));
    cnt  = 0;
    for(int i = 0;i<h;i++){
        for(int j = 0;j<w;j++){
            if(maze[i][j] == '#')
                continue;
            if(maze[i][j]<='c'&&maze[i][j]>='a')
                start[maze[i][j]-'a'] = i*w+j;
            if(maze[i][j]<='C'&&maze[i][j]>='A')
                goal[maze[i][j]-'A'] = i*w+j;
            for(int d = 0;d<5;d++){
                int newi = i + di[d],newj = j+dj[d];
                if(newi<h&&newi>=0&&newj<w&&newj>=0&&maze[newi][newj]!='#')
                    add(i*w+j,newi*w+newj);
            }
        }
    }

}
int bfs(){
    std::queue<Node> q[2];
    memset(vis,0,sizeof(vis));
    vis[start[0]+10][start[1]+10][start[2]+10] = 1;
    vis[goal[0]+10][goal[1]+10][goal[2]+10] = 2;
    q[0].push(Node(0,start[0],start[1],start[2]));
    q[1].push(Node(0,goal[0],goal[1],goal[2]));
    int cur = 1,visflag[2] = {1,2};
    while(!q[0].empty() || !q[1].empty()){
        cur ^= 1;
        int curdis = q[cur].front().dis;
        while(!q[cur].empty()&&q[cur].front().dis==curdis){
            Node u = q[cur].front();
            q[cur].pop();
            if(n==1){
                for(int i = head[u.state[0]];i!=-1;i=e[i].next){
                    Node nxt = u;
                    nxt.dis = u.dis+1;
                    nxt.state[0] = e[i].to;
                    if(vis[nxt.state[0]+10][nxt.state[1]+10][nxt.state[2]+10] == visflag[cur])
                        continue;
                    if(vis[nxt.state[0]+10][nxt.state[1]+10][nxt.state[2]+10] == visflag[cur^1])
                        return nxt.dis+q[cur^1].front().dis;
                    vis[nxt.state[0]+10][nxt.state[1]+10][nxt.state[2]+10] = visflag[cur];
                    q[cur].push(nxt);
                }
            }
            if(n==2){
                for(int i = head[u.state[0]];i!=-1;i=e[i].next){
                    Node nxt = u;
                    nxt.dis = u.dis+1;
                    nxt.state[0] = e[i].to;
                    for(int j = head[u.state[1]];j!=-1;j=e[j].next) {
                        nxt.state[1] = e[j].to;
                        if(nxt.state[0]==nxt.state[1])
                            continue;
                        if(nxt.state[0]==u.state[1]&&nxt.state[1]==u.state[0])
                            continue;
                        if(vis[nxt.state[0]+10][nxt.state[1]+10][nxt.state[2]+10] == visflag[cur])
                            continue;
                        if(vis[nxt.state[0]+10][nxt.state[1]+10][nxt.state[2]+10] == visflag[cur^1])
                            return nxt.dis+q[cur^1].front().dis;
                        vis[nxt.state[0]+10][nxt.state[1]+10][nxt.state[2]+10] = visflag[cur];
                        q[cur].push(nxt);
                    }
                }
            }
            if(n==3){
                for(int i = head[u.state[0]];i!=-1;i=e[i].next){
                    Node nxt = u;
                    nxt.dis = u.dis+1;
                    nxt.state[0] = e[i].to;
                    for(int j = head[u.state[1]];j!=-1;j=e[j].next) {
                        nxt.state[1] = e[j].to;
                        if(nxt.state[0]==nxt.state[1])
                            continue;
                        if(nxt.state[0]==u.state[1]&&nxt.state[1]==u.state[0])
                            continue;
                        for(int f = head[u.state[2]];f!=-1;f = e[f].next) {
                            nxt.state[2] = e[f].to;
                            if(nxt.state[2]==nxt.state[1]||nxt.state[2]==nxt.state[0])
                                continue;
                            if(nxt.state[2]==u.state[0]&&nxt.state[0]==u.state[2])
                                continue;
                            if(nxt.state[2]==u.state[1]&&nxt.state[1]==u.state[2])
                                continue;
                            if(vis[nxt.state[0]+10][nxt.state[1]+10][nxt.state[2]+10] == visflag[cur])
                                continue;
                            if(vis[nxt.state[0]+10][nxt.state[1]+10][nxt.state[2]+10] == visflag[cur^1])
                                return nxt.dis+q[cur^1].front().dis;
                            vis[nxt.state[0]+10][nxt.state[1]+10][nxt.state[2]+10] = visflag[cur];
                            q[cur].push(nxt);
                        }
                    }
                }
            }
        }
    }
    return -1;
}
void main(){
    while(scanf("%d%d%d\n",&w,&h,&n)!=EOF&&(w||h||n)){
        for(int i = 0;i<h;i++)
            gets(maze[i]);
        init();
        printf("%d\n",bfs());
    }
    return 0;
}