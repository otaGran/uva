//
// Created by beans on 2017/5/5.
//
#include<cstdio> #include<cstring>

const int maxn = 100 + 5;
char pic[maxn][maxn];
int m, n, idx[maxn][maxn];

void dfs(int r, int c, int id) {
    if (r < 0 || r >= m || c < 0 || c >= n)
        return; //"  "    if(idx[r][c] > 0 || pic[r][c] != '@') return; //  "@"           idx[r][c] = id; //
    for (int dr = -1; dr <= 1; dr++)
        for (int dc = -1; dc <= 1; dc++)
            if (dr != 0 || dc != 0) dfs(r + dr, c + dc, id);
}

int main() {
    while (scanf("%d%d", &m, &n) == 2 && m && n) {
        for (int i = 0; i < m; i++) scanf("%s", pic[i]);
        memset(idx, 0, sizeof(idx));
        int cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (idx[i][j] == 0 && pic[i][j] == '@') dfs(i, j, ++cnt);
        printf("%d\n", cnt);
    }
    return 0;
}

int c[maxn];
int topo[maxn], t;

bool dfs(int u) {
    c[u] = -1; //
    for (int v = 0; v < n; v++)
        if (G[u][v]) {
            if (c[v] < 0) return false; //
            else if (!c[v] && !dfs(v)) return false;
        }
    c[u] = 1;
    topo[——t]=u;
    return true;
}

bool toposort() {
    t = n;
    memset(c, 0, sizeof(c));
    for (int u = 0; u < n; u++)
        if (!c[u])
            if (!dfs(u)) return false;
    return true;
}

void euler(int u) {
    for (int v = 0; v < n; v++)
        if (G[u][v] && !vis[u][v]) {
            vis[u][v] = vis[v][u] = 1;
            euler(v);
            printf("%d %d\n", u, v);
        }
}

#include<cstdio>
#include<algorithm> //  next_permutation using namespace std;

int main() {
    int n, p[10];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    sort(p, p + n);
    do {
        for (int i = 0; i < n; i++) printf("%d ", p[i]);
        printf("\n");
    } while (next_permutation(p, p + n));
    return 0;
}


void print_subset(int n, int *B, int cur) {
//       //
    if (cur == n) {
        for (int i = 0; i < cur; i++)
            if (B[i]) printf("%d ", i);
        printf("\n");
        return;
    }
    B[cur] = 1;
    print_subset(n, B, cur + 1);
    B[cur] = 0;
    print_subset(n, B, cur + 1);
}


八皇后
void search(int cur) {
    if (cur == n) tot++;
    else
        for (int i = 0; i < n; i++) {
            if (!vis[0][i] && !vis[1][cur + i] && !vis[2][cur - i + n]) { //
                C[cur] = i;
                vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 1;
                search(cur + 1);
                vis[0][i] = vis[1][cur + i] = vis[2][cur - i + n] = 0;
            }
        }
}

const int dx[ ] = {-1, 1, 0, 0}; const int dy[ ] = {0, 0, -1, 1}; //BFS        st
int bfs( ) {
    init_lookup_table( ); int front = 1, rear = 2; while(front < rear) {
        State& s = st[front];
        if(memcmp(goal, s, sizeof(s)) == 0) return front;//            int z;
        for(z = 0; z < 9; z++) if(!s[z]) break;
        int x = z/3, y = z%3;
        for(int d = 0; d < 4; d++) {
            int newx = x + dx[d];
            int newy = y + dy[d];
            int newz = newx * 3 + newy;
            if(newx>=0&&newx<3&&newy>=0&&newy<3){ //
                State& t = st[rear];
                memcpy(&t, &s, sizeof(s));
                t[newz] = s[z];
                t[z] = s[newz];
                dist[rear] = dist[front] + 1;
                if(try_to_insert(rear)) rear++;

            } }
        front++; //             }
        return 0; //
}
        int main( ){
            for(int i = 0; i < 9; i++) scanf("%d", &st[1][i]); //
            for(int i = 0; i < 9; i++) scanf("%d", &goal[i]); int ans = bfs( );
            if(ans > 0) printf("%d\n", dist[ans]);
            else printf("-1\n");
            return 0; }
//     //