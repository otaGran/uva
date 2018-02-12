//
// Created by beans on 2017/8/24.
//
//6.4.3 拓扑排序
//假设有n个变量，还有m个二元组(u,v)，分别表示变量u小于v
//sample input:
//4
//0 1
//2 1
//3 2
//0 0
//
//sample output
//a < d < c < b


#include <cstring>
#include <iostream>

using namespace std;


const int maxn = 100;
int c[maxn];           //c[u] 0没有访问 -1递归中 1已访问
int topo[maxn], t, n;  //topo数组储存排序结果
int G[maxn][maxn];     //存图

bool dfs(int u) {
    c[u] = -1;         //访问标志
    for (int v = 0; v < n; v++)//遍历小于情况
        if (G[u][v]) {         //存在小于关系
            if (c[v] < 0)     //存在有向环 -> false
                return false;
            else if (!c[v] && !dfs(v)) //大边未访问 -> 递归确认最大边添加到topo数组尾部
                return false;

        }
    c[u] = 1;       //访问结束标志
    topo[--t] = u;  //将结果保存到topo数组结尾
    return true;
}

bool toposort() {
    t = n;
    memset(c, 0, sizeof(c));
    for (int u = (n - 1); u >= 0; u--) //遍历起点
        if (!c[u] && !dfs(u))
                return false;
    return true;
}

int main() {
    while(scanf("%d",&n)==1&&n) {
        //scanf("%d", &n);
        memset(G, 0, sizeof(G));
        int a, b;
        while (scanf("%d%d", &a, &b) == 2 && (a || b)) {
            //cout << a << " " << b << endl;
            G[a][b] = 1;
            //printf("%d\n", G[a][b]);
        }
        //printf("here\n");
        if (toposort()) {

            //printf("finish\n");
            for (int i = 0; i < n - 1; i++)
                printf("%c < ", topo[i] + 97);
            printf("%c\n", topo[n - 1] + 97);
        } else {
            printf("Failed!\n");
        }
        printf("*********\n");
    }

    return 0;
}
