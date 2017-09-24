#include <cstdio>
#include <cstring>
//#include <stack>

//
// Created by beans on 2016/12/8.
//
long long fib[50], t, maxd, ans[1000], tmp, goal;

bool dfs(int cur) {
    if (cur == 0) {
        if (tmp == goal)
            return true;
        return false;
    } else {
        //printf("hello");
        if(tmp>goal)
            return false;
        for (int i = 1; i >=0; i--) {
            //printf("%d\n",i);
            ans[cur] = i;
            tmp += (ans[cur] == 0 ? 0 : fib[cur]);
            if (dfs(cur - 1))
                return true;
            tmp -= (ans[cur] == 0 ? 0 : fib[cur]);
            //ans[i] = 0;
        }
        return false;
    }
}


void main() {
    fib[0] = 0;
    fib[1] = 1;

    ///int xxx = 0;
    for (int i = 2; i < 50; i++) {
        int xxx = fib[i - 1] + fib[i - 2];
        if (xxx == fib[i - 1])
            xxx += fib[i - 1];
        fib[i] = xxx;
        //printf("%d\n", fib[i]);
    }
    scanf("%d\n",&t);
    while(t--) {
        memset(ans, 0, sizeof(ans));
        tmp = 0;
        //printf("%d",goal);
        scanf("%d", &goal);
        //printf("ssss",goal);
        for (maxd = 40; maxd > 0; maxd--) {
            if (fib[maxd] > goal)
                continue;
            if (dfs(maxd))
                break;

            //printf("%d",maxd);
        }
        printf("%d = ",goal);
        //int ok = 0;
        for (int i = maxd; i >= 1; i--) {
            //if (ans[i] == 1)
            //  ok = 1;
            //if (ok)
            printf("%d", ans[i]);
        }
        printf(" (fib)\n");
    }

    return 0;
}
