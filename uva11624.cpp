#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
//bfs
//fire！
// Created by beans on 2016/12/6.
//
char maze[1000][1000 + 1];
int t, R, C, dr[] = {0, 0, -1, 1}, dc[] = {1, -1, 0, 0};
std::set<int> vis;
struct State {
    int row, col, dis;

    State(int row, int col, int dis) : row(row), col(col), dis(dis) {

    }
};

//State st[1000];
std::queue<State> fire, joe;

void init_lookup_table() {
    vis.clear();
}

int try_to_insert(int row, int col) {
    int v = row * 10000 + col;
    if (vis.count(v))
        return 0;
    vis.insert(v);
    return 1;
}

int bfs() {
    //try_to_insert();
    //std::queue<State> q;
    //q.push(State(Joe_row, Joe_col, 0));
    while (!joe.empty()) {
        //
        if (!fire.empty()) {
            int curdis = fire.front().dis;
            while (!fire.empty() && fire.front().dis == curdis) {
                State u = fire.front();
                fire.pop();
                //printf("%d %d\n",u.row,u.col);
                for (int d = 0; d < 4; ++d) {
                    State nxt = u;
                    nxt.dis = u.dis + 1;
                    nxt.row = u.row + dr[d];
                    nxt.col = u.col + dc[d];
                    //printf("%d %d\n",nxt.row,nxt.col);
                    //out of boundry
                    if (nxt.row < 0 || nxt.row >= R || nxt.col < 0 || nxt.col >= C)
                        continue;
                    //only empty space can catch fire
                    if (maze[nxt.row][nxt.col] != '.')
                        continue;
                    maze[nxt.row][nxt.col] = 'F';
                    fire.push(nxt);
                }
            }
        }
        int curdis = joe.front().dis;
        //degree++;
        //fire();
        for (int h = 0; h < R; ++h) {
            // printf("%s\n",maze[h]);
        }
        while (!joe.empty() && curdis == joe.front().dis) {
            State u = joe.front();
            joe.pop();
            for (int d = 0; d < 4; d++) {
                State nxt = u;
                nxt.dis += 1;
                nxt.row += dr[d];
                nxt.col += dc[d];
                if (nxt.row < 0 || nxt.row >= R || nxt.col < 0 || nxt.col >= C)
                    return nxt.dis;
                if (maze[nxt.row][nxt.col] == '#' || maze[nxt.row][nxt.col] == 'F')
                    continue;
                if (try_to_insert(nxt.row, nxt.col))
                    joe.push(nxt);
            }
        }
    }
    return -1;
}

void init() {
    //degree = 0;
    init_lookup_table();
    while (!fire.empty())
        fire.pop();
    while (!joe.empty())
        joe.pop();
    //memset(st, 0, sizeof(st));
    //located the Fire and Joe
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (maze[i][j] == 'F') {
                fire.push(State(i, j, 0));
                //printf("%d %d\n",i,j);
            }
            if (maze[i][j] == 'J') {
                joe.push(State(i, j, 0));
                try_to_insert(i, j);
            }

        }

    }

}

void main() {
    scanf("%d\n", &t);
    while (t--) {
        scanf("%d %d\n", &R, &C);
        for (int j = 0; j < R; ++j)
            gets(maze[j]);
        init();
        int ans = bfs();
        if (ans == -1)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", ans);
    }
}