//
// Created by beans on 3/8/17.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;
struct condition {
    int a, b, c;
};
condition fuck[21];
int m, n, cnt = 0, tmp[8];

bool check(int index, int target) {
    int ok = 1;
    for (int i = 0; i < index; ++i) {//go through all previous target
        for (int j = 0; j < m; ++j) {
            if (fuck[j].a == target && fuck[j].b == tmp[i] || fuck[j].b == target && fuck[j].a == tmp[i])
                if (fuck[j].c < 0 && (index - i) < (-fuck[j].c) || fuck[j].c > 0 && (index - i) > (fuck[j].c))
                    ok = 0;
        }
    }
    return ok;
}


void fk(int index) {
    if (index == n)
        cnt++;
    else {
        //find a unsit target
        for (int i = 0; i < n; ++i) {
            bool ok = 1;
            for (int j = 0; j < index; ++j) {
                if (tmp[j] == i)
                    ok = false;
            }
            if (!ok)
                continue;
            if (check(index, i)) {
                tmp[index] = i;
                fk(index + 1);
            }

        }

    }
}


int main() {
    while (cin >> n >> m) {
        cnt = 0;
        memset(tmp, -1, sizeof(tmp));
        if (m == n && m == 0)
            return 0;
        for (int i = 0; i < m; ++i)
            cin >> fuck[i].a >> fuck[i].b >> fuck[i].c;
        fk(0);
        printf("%d\n", cnt);
    }
}
