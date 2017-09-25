//前提:所有圆与地面相切
//假设新加入圆与前一圆相切,判断是否与其他圆相交
//不相交即为合法
// Created by beans on 2017/9/23.
//

#include <iostream>
#include <deque>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
int n, m;
double num[100 + 6];
double mun[100 + 6];
const double INF = 0x6ffffff;
double ans = INF;
double front[100 + 6];
double dis(int a, int b) {  //两圆相切之间的距离
    return 2 * sqrt(num[a] * num[b]);
}
double len(int a, int b) {  //两圆相切球心之间的距离
    return sqrt(pow(front[a] - front[b], 2) + pow(num[a] - num[b], 2));
}
bool cmp(double x, double y) {  //判断x< y
    return x < y;
}
void fuck() {
    double tmp_res = 0;
    memset(front, 0, sizeof(front));
    front[0] = num[0];
    tmp_res += num[0] * 2;
    for (int i = 1; i < m; i++) {
        front[i] = front[i - 1] + dis(i, i - 1);
        if (cmp(front[i], num[i]))
            front[i] = num[i];
        for (int j = 0; j < i - 1; j++) {
            if (cmp(len(j, i), num[i] + num[j]))
                front[i] = front[j] + dis(i, j);
        }
        if (cmp(tmp_res, front[i] + num[i]))
            tmp_res = front[i] + num[i];
        if (ans < tmp_res)
            return;
    }
    if (cmp(tmp_res, ans))
        ans = tmp_res;
}
int main() {
    cin >> n;
    while (n--) {
        cin >> m;
        ans = INF;
        for (int i = 0; i < m; i++) {
            cin >> num[i];
        }
        sort(num, num + m);
        do {
            fuck();
        } while (next_permutation(num, num + m));
        printf("%.3lf\n", ans);

    }
}