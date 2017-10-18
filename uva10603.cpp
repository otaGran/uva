//
// Created by beans on 2017/10/17.
//

//优先队列确保以最小值到达每个节点
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct Node {
    int v[3], dist;

    bool operator<(const Node &rhs) const {
        return dist > rhs.dist;
    }

};

const int maxn = 200 + 5;
int vis[maxn][maxn], cap[3], ans[maxn];

void update_ans(const Node &u) {
    for (int i = 0; i < 3; i++) {//遍历杯编号
        int d = u.v[i];
        if (ans[d] < 0 || u.dist < ans[d])//未到达该结果 或 较小水量到达该结果
            ans[d] = u.dist;
    }
}

void slove(int a, int b, int c, int d) {
    cap[0] = a;
    cap[1] = b;
    cap[2] = c;
    memset(vis, 0, sizeof(vis));
    memset(ans, -1, sizeof(ans));
    priority_queue<Node> q;

    Node start;
    start.dist = 0;
    start.v[0] = 0;
    start.v[1] = 0;
    start.v[2] = c;
    q.push(start);

    vis[0][0] = 1;
    while (!q.empty()) {
        Node u = q.top();//取出当前最小水量节点
        q.pop();
        update_ans(u);//更新结果
        if (ans[d] >= 0) {
            break;

        }
        for (int i = 0; i < 3; i++)//选定源杯编号
            for (int j = 0; j < 3; j++)//选定目标杯编号
                if (i != j) {
                    if (u.v[i] == 0 || u.v[j] == cap[j]) {//源杯子为空或目标杯已满
                        continue;
                    }
                    int amount = min(cap[j], u.v[i] + u.v[j]) - u.v[j];//确定最小水量 case_1:倒满目标杯 case_2:倒空源杯
                    Node u2;//扩展新节点
                    memcpy(&u2, &u, sizeof(u));
                    u2.dist = u.dist + amount;//新节点最小水量
                    u2.v[i] -= amount;
                    u2.v[j] += amount;
                    if (!vis[u2.v[0]][u2.v[1]]) {//判重
                        vis[u2.v[0]][u2.v[1]] = 1;
                        q.push(u2);
                    }
                }
    }
    while (d >= 0) {//从 d 逼近 d'
        if (ans[d] >= 0) {//存在此结果
            printf("%d %d\n", ans[d], d);
            return;
        }
        d--;

        
    }


}

int main() {
    int T, a, b, c, d;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        slove(a, b, c, d);

    }
    return 0;
}