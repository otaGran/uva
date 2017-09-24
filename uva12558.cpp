#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
//迭代加深搜索--以埃及分数问题为例
// Created by beans on 2016/12/7.
//runtime error ex[1000]企图用线性查找解决 问题是需要搜索的数字可能大于1000
//timelimit 剪枝应该放在判断不能出现的数字之前！！！
using namespace std;
long long v[1000], ans[1000];
int  maxd, t, k,ok;
long long ex[6];
//set<long long>ban;
typedef long long ll;
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}
long long get_first(long long a, long long b) {//满足1/c<=a/b的最小c
    long long c = 1;
    for (c = 1; a * c <= b; c++) {}
    return c;

    //return b / a + 1;
}

bool better(int d) {
    for (int i = d; i >= 0; i--) {
        if (v[i] != ans[i])
            return ans[i] == -1 || v[i] < ans[i];
    }
    return false;
}

bool find(long long y){
    for(int x = 0;x<k;x++)
        if(ex[x]==y)
            return 1;
    return 0;
}

bool dfs(int d, long long form, long long aa, long long bb) {
    //memset(ans, -1, sizeof(ans));
    if (d == maxd) {
        if (bb % aa||find(bb/aa))
            return false;//埃及分数要求分子为1
        v[d] = bb/aa;
        if (better(d)) {
            memcpy(ans, v, sizeof(long long) * (d + 1));
        }
        return true;
    }
    bool ok = false;
    form = max(form, get_first(aa, bb));//枚举起点
    for (int i = form;; i++) {
        if (bb * (maxd + 1 - d) <= i * aa)
            break;//减枝
        if (find(i))
            continue;//jump the number

        v[d] = i;
        long long b2 = bb * i;
        long long a2 = aa * i - bb;
        long long g = gcd(b2, a2);
        if (dfs(d + 1, i + 1, a2 / g, b2 / g))
            ok = true;
    }
    return ok;
}

void main() {
    scanf("%d\n", &t);
    for (int p = 1; p <= t; p++) {
        ok = 0;
        //ban.clear();
        //memset(v, 0, sizeof(v));
        //memset(ex, 0, sizeof(ex));
        ll a,b;
        scanf("%lld %lld %d", &a, &b, &k);
        //printf("%d %d\n",a,b);
        for (int j = 0; j < k; ++j) {
            //int tmp;
            //ll tmp;
            scanf("%lld", &ex[j]);
            //ban.insert(tmp);
            //ex[j] = tmp;
        }
       // getchar();//get an "\n"
        for (maxd = 1;; maxd++) {
            memset(ans, -1, sizeof(ans));
            if (dfs(0, get_first(a, b), a, b)) {
                ok = 1;
                break;
            }
        }
        printf("Case %d: %lld/%lld=", p, a, b);
        for (int i = 0; i <= maxd; ++i) {
            printf("1/%lld", ans[i]);
            if (i != maxd)
                printf("+");
        }
        //printf("yes\n");
        printf("\n");
    }
    return 0;
}
