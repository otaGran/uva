//
// Created by beans on 2016/11/29.
//
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct Node{
    int v[3],dist;
    bool operator < (const Node& rhs) const{
        return dist > rhs.dist;
    }
};
const int maxn = 200 + 5;
int vis[maxn][maxn],cap[3],ans[maxn];
void update_ans(const Node& u){
    for(int i = 0;i<3;i++){
        int d = u.v[i];
        if(ans[d] < 0 || u.dist < ans[d])
            ans[d] = u.dist;
    }
}
void solve (int a,int b,int c,int d){
    cap[0] = a;cap[1] = b,cap[2] = c;//初始化三个杯子的容量
    memset(vis,0, sizeof(vis));
    memset(ans,-1, sizeof(ans));
    priority_queue<Node> q;
    Node start;
    start.dist = 0;//初始化倒水量
    start.v[0] = 0;start.v[1] = 0;start.v[2] = c;//初始状态下 第三个杯子装满 其他两个为空
    q.push(start);
    vis[0][0] = 1;//因总水量恒等于第三个杯子的容量，故对于bfs判重只需要比对前两个杯子当前的水量即可
    while(!q.empty()){
        Node u = q.top();
        q.pop();
        update_ans(u);//更新结果
        if(ans[d] >= 0)//找到结果
            break;
        for(int i = 0;i < 3;i++)//选定源杯子编号
            for(int j = 0;j<3;j++)//选定目标杯子编号
                if(i != j){
                    if(u.v[i] == 0 || u.v[j] == cap[j])//如果源杯子为空或目标杯子已满 则跳过
                        continue;
                    int amount = min(cap[j],u.v[i]+u.v[j]) - u.v[j];//确定最小的倒水量 通过找到源杯水量和目标杯空余量的最小值
                    Node u2;//扩展新的节点
                    memcpy(&u2,&u,sizeof(u));
                    u2.dist = u.dist + amount;//新节点的到水量等于父节点倒水量+新节点的倒水量
                    u2.v[i] -= amount;//从源杯倒出amount水
                    u2.v[j] += amount;//向目标杯倒入amount水
                    if(!vis[u2.v[0]][u2.v[1]]){//判重
                        vis[u2.v[0]][u2.v[1]] = 1;
                        q.push(u2);//向优先队列中插入新节点
                    }
                }
    }
    while(d >= 0){//循环找到目标d或d'
        if(ans[d] >= 0){
            //printf("%d ",q.empty());
            printf("%d %d\n",ans[d],d);
            return;
        }
        d--;
    }

}
void main(){
    int T,a,b,c,d;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        solve(a,b,c,d);
    }
    return 0;
}