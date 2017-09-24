//
// Created by beans on 2016/11/30.
//

#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

struct Node {
    int t, now[3];
    Node(int _t, int a = -1, int b = -1, int c = -1) : t(_t) {
        now[0] = a;
        now[1] = b;
        now[2] = c;
    }
};

struct Edge {
    int to, nxt;
};
Edge e[2000];
char mp[17][17];
int w, h, n, cnt, head[265 + 2];
int goal[3], start[3], vis[268][268][268];
int d[5][2] = {{0,  0},
               {-1, 0},
               {1,  0},
               {0,  1},
               {0,  -1}};

void add(int u, int v) {
    e[cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

void init() {
    cnt = 0;
    memset(start, -1, sizeof(start));
    memset(goal, -1, sizeof(goal));
    memset(head, -1, sizeof(head));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (mp[i][j] == '#')
                continue;
            if (mp[i][j] >= 'a' && mp[i][j] <= 'c')
                start[mp[i][j] - 'a'] = i * w + j;
            if (mp[i][j] >= 'A' && mp[i][j] <= 'C')
                goal[mp[i][j] - 'A'] = i * w + j;
            for (int k = 0; k < 5; ++k) {
                int ni = i + d[k][0], nj = j + d[k][1];
                //printf("%d %d\n",ni,nj);
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && mp[ni][nj] != '#')
                    add(i * w + j, ni * w + nj);
            }
        }
    }
}

int bfs() {
    queue<Node> q[2];
    memset(vis, 0, sizeof(vis));
    vis[start[0] + 10][start[1] + 10][start[2] + 10] = 1;
    vis[goal[0] + 10][goal[1] + 10][goal[2] + 10] = 2;
    q[0].push(Node(0, start[0], start[1], start[2]));
    q[1].push(Node(0, goal[0], goal[1], goal[2]));
    int cur = 1, visflg[2] = {1, 2};
    while (!q[0].empty() || !q[1].empty()) {//任意一个queue为空无解
        cur ^= 1;
        int curct = q[cur].front().t;
        while (!q[cur].empty() && q[cur].front().t == curct) {
            Node u = q[cur].front();
            q[cur].pop();
            if (n == 1) {
                for (int i = head[u.now[0]]; i != -1; i = e[i].nxt) {
                    Node nxt = u;
                    nxt.now[0] = e[i].to;
                    if (vis[nxt.now[0] + 10][nxt.now[1] + 10][nxt.now[2] + 10] == visflg[cur ^ 1])
                        return u.t + q[cur ^ 1].front().t + 1;
                    if (vis[nxt.now[0] + 10][nxt.now[1] + 10][nxt.now[2] + 10] == visflg[cur]) continue;
                    vis[nxt.now[0] + 10][nxt.now[1] + 10][nxt.now[2] + 10] = visflg[cur];
                    nxt.t = u.t + 1;
                    q[cur].push(nxt);
                }
            } else if (n == 2) {
                for (int i = head[u.now[0]]; i != -1; i = e[i].nxt) {
                    Node nxt = u;
                    nxt.now[0] = e[i].to;
                    for (int j = head[u.now[1]]; j != -1; j = e[j].nxt) {
                        nxt.now[1] = e[j].to;
                        if (nxt.now[0] == nxt.now[1]) continue;
                        if (nxt.now[0] == u.now[1] && nxt.now[1] == u.now[0]) continue;
                        if (vis[nxt.now[0] + 10][nxt.now[1] + 10][nxt.now[2] + 10] == visflg[cur ^ 1])
                            return u.t + q[cur ^ 1].front().t + 1;
                        if (vis[nxt.now[0] + 10][nxt.now[1] + 10][nxt.now[2] + 10] == visflg[cur]) continue;
                        vis[nxt.now[0] + 10][nxt.now[1] + 10][nxt.now[2] + 10] = visflg[cur];
                        nxt.t = u.t + 1;
                        q[cur].push(nxt);
                    }
                }
            } else {
                for (int i = head[u.now[0]]; i != -1; i = e[i].nxt) {
                    Node nxt = u;
                    nxt.now[0] = e[i].to;
                    for (int j = head[u.now[1]]; j != -1; j = e[j].nxt) {
                        nxt.now[1] = e[j].to;
                        if (nxt.now[0] == nxt.now[1]) continue;
                        if (nxt.now[0] == u.now[1] && nxt.now[1] == u.now[0]) continue;
                        for (int k = head[u.now[2]]; k != -1; k = e[k].nxt) {
                            nxt.now[2] = e[k].to;
                            if (nxt.now[2] == nxt.now[0] || nxt.now[2] == nxt.now[1]) continue;
                            if (nxt.now[2] == u.now[0] && nxt.now[0] == u.now[2]) continue;
                            if (nxt.now[2] == u.now[1] && nxt.now[1] == u.now[2]) continue;
                            if (vis[nxt.now[0] + 10][nxt.now[1] + 10][nxt.now[2] + 10] == visflg[cur ^ 1])
                                return u.t + q[cur ^ 1].front().t + 1;
                            if (vis[nxt.now[0] + 10][nxt.now[1] + 10][nxt.now[2] + 10] == visflg[cur]) continue;
                            vis[nxt.now[0] + 10][nxt.now[1] + 10][nxt.now[2] + 10] = visflg[cur];
                            nxt.t = u.t + 1;
                            q[cur].push(nxt);
                        }
                    }
                }
            }
        }
    }
    return -1;
}

void main() {
    while (scanf("%d%d%d\n", &w, &h, &n) != EOF && (w || h || n)) {
        //getchar();
        for (int i = 0; i < h; i++)
            gets(mp[i]);
        init();
        printf("%d\n", bfs());
    }
    return 0;
}