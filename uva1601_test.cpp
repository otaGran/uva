#include<cstdio>
#include<cstring>
#include<queue>

//
// Created by beans on 2016/12/1.
//
const int maxn = 16;
int w, n, h, start[3], goal[3], vis[268][268][268], cnt, head[256 + 10];
int di[] = {0, 0, -1, 1, 0}, dj[] = {-1, 1, 0, 0, 0};
char maze[maxn][maxn + 1];
struct edge {
    int to, nxt;
};

struct node {
    int now[3], t;

    node(int t, int a = -1, int b = -1, int c = -1) : t(t) {
        now[0] = a;
        now[1] = b;
        now[2] = c;
    }
};

edge e[2000];

int bfs() {
    std::queue<node> q[2];
    vis[start[0] + 10][start[1] + 10][start[2] + 10] = 1;
    vis[goal[0] + 10][goal[1] + 10][goal[2] + 10] = 2;
    q[0].push(node(0, start[0], start[1], start[2]));
    q[1].push(node(0, goal[0], goal[1], goal[2]));
    int cur = 1, visflg[2] = {1, 2};
    while (!q[0].empty() || !q[1].empty()) {
        cur ^= 1;
        int curct = q[cur].front().t;
        while (!q[cur].empty() && q[cur].front().t == curct) {
            node u = q[cur].front();
            q[cur].pop();
            /*
            if (memcmp(u.now, goal, sizeof(goal)) == 0)
                return u.t;

            if (n == 1) {
                for (int i = head[u.now[0]]; i != -1; i = e[i].nxt) {
                    node s = u;
                    n.now[0] = e[i].to;
                    n.t = u.t + 1;
                    if (vis[n.now[0] + 10][n.now[1] + 10][n.now[2] + 10] == 1)
                        continue;
                    vis[n.now[0] + 10][n.now[1] + 10][n.now[2] + 10] = 1;
                    q.push(s);
                }
            }
             */
            if (n == 2) {
                for (int i = head[u.now[0]]; i != -1; i = e[i].nxt) {
                    node n = u;
                    n.now[0] = e[i].to;
                    for (int j = head[u.now[1]]; j != -1; j = e[j].nxt) {
                        n.now[1] = e[j].to;
                        if (n.now[0] == n.now[1])
                            continue;
                        if (n.now[1] == u.now[0] && n.now[0] == u.now[1])
                            continue;
                        if (vis[n.now[0] + 10][n.now[1] + 10][n.now[2] + 10] == visflg[cur ^ 1])
                            return n.t + q[cur ^ 1].front().t + 1;
                        vis[n.now[0] + 10][n.now[1] + 10][n.now[2] + 10] = visflg[cur];
                        n.t = u.t + 1;
                        q[cur].push(n);
                    }
                }

            }
            /*
            if (n == 3) {
                for (int i = head[u.now[0]]; i != -1; i = e[i].nxt) {
                    node s = u;
                    n.now[0] = e[i].to;
                    n.t = u.t + 1;
                    for (int j = head[u.now[1]]; j != -1; j = e[j].nxt) {
                        n.now[1] = e[j].to;
                        if (n.now[0] == n.now[1])
                            continue;
                        if (n.now[1] == u.now[0] && n.now[0] == u.now[1])
                            continue;
                        for (int f = head[u.now[2]]; f != -1; f = e[f].nxt) {
                            n.now[2] = e[f].to;
                            if (n.now[0] == n.now[2] || n.now[1] == n.now[2])
                                continue;
                            if (n.now[2] == u.now[0] && n.now[0] == u.now[2] ||
                                n.now[2] == u.now[1] && n.now[1] == u.now[2])
                                continue;
                            if (vis[n.now[0] + 10][n.now[1] + 10][n.now[2] + 10] == 1)
                                continue;
                            vis[n.now[0] + 10][n.now[1] + 10][n.now[2] + 10] = 1;
                            q.push(s);
                        }
                    }
                }
                */


        }
    }
    return -1;
}

void add(int u, int v) {
    e[cnt].to = v;
    e[cnt].nxt = head[u];
    head[u] = cnt++;
}

void init() {
    memset(start, -1, sizeof(start));
    memset(goal, -1, sizeof(goal));
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            //printf("%c", maze[i][j]);
            if (maze[i][j] == '#')
                continue;
            if (maze[i][j] <= 'c' && maze[i][j] >= 'a')
                start[maze[i][j] - 'a'] = i * w + j;
            if (maze[i][j] <= 'C' && maze[i][j] >= 'A')
                goal[maze[i][j] - 'A'] = i * w + j;
            for (int d = 0; d < 5; d++) {
                int newi = i + di[d], newj = j + dj[d];
                if (newi >= 0 && newi < h && newj < w && newj >= 0)
                    add(i * w + j, newi * w + newj);
            }
        }
        //printf("\n");
    }
    //printf("above are the input from maze\n");

}

void main() {
    while (scanf("%d%d%d\n", &w, &h, &n) != EOF && (w || h || n)) {
        //getchar();
        for (int i = 0; i < h; i++)
            gets(maze[i]);
        init();
        printf("%d\n", bfs());
    }
    return 0;
}
