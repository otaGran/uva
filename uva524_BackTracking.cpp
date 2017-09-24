//
// Created by beans on 2016/11/22.
//
#define MAX 16+10

#include <cstdio>
#include <cstring>

//#include <algorithm>
bool isPrime(int n);

void dfs(int cur);

int n;
int A[MAX];
int vis[MAX];
int isp[MAX];

void dfs(int cur) {
    if (cur == n && isp[A[0] + A[n - 1]]) {
        for (int i = 0; i < n; i++) {
            if (i)
                printf(" ");
            printf("%d", A[i]);
        }
        printf("\n");
    } else {

        for (int i = 2; i <= n; i++) {
            //printf("%d      \n",isp[i+A[cur-1]]);
            if (!vis[i] && isp[i + A[cur - 1]]) {
                //printf("hello");
                A[cur] = i;
                vis[i] = 1;
                dfs(cur + 1);
                vis[i] = 0;
            }
        }
    }
}

bool isPrime(int n) {
    if (n == 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;

}

void main() {
    //int n;
    int count = 0;
    while (scanf("%d", &n) == 1) {
        if (count++)
            printf("\n");
        printf("Case %d:\n", count);
        for (int i = 0; i < n * 2; i++) {
            //A[i] = i + 1;
            isp[i + 1] = isPrime(i + 1);
            //printf("%d ",isp[i+1]);
        }
        A[0] = 1;
        //vis[1] = 1;
        std::memset(vis, 0, n * sizeof(*vis));
        dfs(1);
    }
}

