//
// Created by beans on 2016/11/25.
//

#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 101;
int n, m, t;
int gragh[maxn][maxn], res[maxn], c[maxn];

bool dfs(int u) {
    c[u] = -1;         //访问标志
    for (int v = 0; v < n; v++)//遍历小于情况
    //for(int v = (n-1);v>=0;v--)
        if (gragh[u][v]) {         //存在小于关系
            if (c[v] < 0)     //存在有向环 -> false
                return false;
            else if (!c[v] && !dfs(v)) //大边未访问 -> 递归确认最大边添加到topo数组尾部
                return false;

        }
    c[u] = 1;       //访问结束标志
    res[--t] = u;  //将结果保存到topo数组结尾
    return true;
}

bool toposort() {
    t = n;
    memset(c, 0, sizeof(c));
    for (int u = 0; u < n; u++)
    //for(int u = (n-1);u>=0;u--)
        if (!c[u])
            if (!dfs(u))
                return false;
    return true;
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF && (n || m)) {
        memset(gragh, 0, sizeof(gragh));
        int a, b;
        for (int i = 0; i < m; i++) {
            scanf("%d%d", &a, &b);
            gragh[a-1][b-1] = 1;
        }//for input
        toposort();
        for (int i = 0 ;i <n; i++)
            printf("%d ", res[i] + 1);
        printf("\n");
    }//while
    return 0;
}