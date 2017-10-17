//
// Created by beans on 2017/10/12.
//
//对于复杂字串输入 考虑白名单方式
//仔细读题  对于不定间隔输入 建表确定顺序 核心算法不调整
#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>

using namespace std;
string s;
int graph[8][8], n, k = 9, A[8], res_A[8], vis[8], getID[8];
set<char> alID;

int fuck(char x) {
    for (int i = 0; i < alID.size(); i++) {
        if (getID[i] == x)
            return i;
    }
    return -1;
}

void dfs(int cur, int cnt) {

    if (cur == n) {//当前最优
        if (cnt < k)
            memcpy(res_A, A, sizeof(A));
        k = cnt;
    } else {
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                for (int j = 0; j < cur; j++) {
                    if (graph[i][A[j]] || graph[A[j]][i]) {
                        if (cur - j > cnt)
                            cnt = cur - j;
                    }
                }
                if (cnt <= k) {
                    vis[i] = 1;
                    A[cur] = i;
                    dfs(cur + 1, cnt);
                    vis[i] = 0;
                }
            }
        }
    }
}

void init() {
    memset(graph, 0, sizeof(graph));
    memset(vis, 0, sizeof(vis));
    k = 9;
    alID.clear();
}

int main() {
    while (getline(cin, s)) {
        //cin >> s;
        if (s[0] == '#')
            return 0;
        init();
        int ok = false;
        int start;

        for (char i : s) {//建表确定输入顺序
            if (i >= 'A' && i <= 'Z') {
                if (!alID.count(i)) {
                    alID.insert(i);
                    getID[alID.size() - 1] = i;
                }
            }
        }
        sort(getID, getID + alID.size());
        for (char i : s) {
            if (i == ';') {
                ok = false;
            }
            if (i == ':') {
                ok = true;
            }
            if (i >= 'A' && i <= 'Z') {//白名单
                if (ok)
                    graph[start][fuck(i)] = 1;
                else
                    start = fuck(i);
            }

        }
        n = alID.size();
        dfs(0, 1);
        for (int i = 0; i < n; i++) {
            cout << (char) (getID[res_A[i]]) << " ";
        }
        cout << "-> " << k << endl;
    }
}