//
// Created by beans on 2017/1/20.
//
#include <iostream>

#include <vector>

#include <queue>
#include <set>
#include <cstring>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int p, m;
        cin >> p >> m;
        int tmp[p + 1][p + 1];
        int degree[p + 1];
        queue<int> q;
        //set<int> fuck[p];
        memset(degree, 0, sizeof(degree));
        memset(tmp, 0, sizeof(tmp));
        int value[p + 1];
        for (int i = 1; i <= p; ++i) {
            cin >> value[i];
            q.push(i);
        }
        for (int j = 0; j < m; ++j) {
            int from, to;
            cin >> from >> to;
            tmp[from][to] = 1;
            degree[from]++;
            degree[to]++;
           // printf("%d %d\n", from, to);
            //fuck[from].insert(to);
        }
        for (int l = 1; l <= p; ++l) {
            //printf("%d\n", degree[l]);
        }
        while (!q.empty()) {
            int k = q.front();
            q.pop();
            if (degree[k] ==1) {
                int i;
                for (i = 1; i <= p; ++i) {
                    if (tmp[k][i] == 1) {
                        tmp[k][i] == 0;
                        q.push(i);
                        break;
                    }
                }
                degree[k]--;
                degree[i]--;
                //int to = fuck[k][0];
                //cout << k << "\n";
            }
        }
        int res = 0;
        for (int n = 1; n <= p; ++n) {
            if(degree[n]>0) {
                //printf("%d %d\n",degree[n], value[n]);
                res+=value[n];
            }
        }
        cout << res << "\n";

    }
}