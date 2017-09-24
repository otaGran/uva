//
// Created by beans on 2017/1/8.
//
#include <cstdio>
#include <cstring>
//n ／ m 时 总共有1～m-1个余数 根据鸽笼原理 计算m次必定出现重复！
int main() {
    int n, m, count = 0;
    while (scanf("%d %d", &n, &m)==2) {
        /*
        if (count++ != 0)
            printf("\n");
           */
        //int reminder = n%m;
        int yushu[3001], pos[3001], xiaoshu[3001];
        std::memset(yushu, 0, sizeof(yushu));
        std::memset(pos, 0, sizeof(pos));
        //yushu[reminder] = 1;
        printf("%d/%d = %d.", n, m, n / m);
        int i;
        n %= m;
        yushu[n] = 1;
        for (i = 1; i < m + 10; ++i) {
            n *= 10;
            xiaoshu[i] = n / m;
            //printf("%d", n/m);
            n = n % m;

            //start from here n represent the reminder
            if (yushu[n])
                break;
            yushu[n] = 1;
            pos[n] = i;

        }

        for (int j = 1; j <= pos[n]; ++j) {
            printf("%d", xiaoshu[j]);
        }
        //printf("(0)");

        printf("(");
        for (int j = pos[n]+1; j <= i && j <= 50; ++j) {
            printf("%d", xiaoshu[j]);
        }
        if (i > 50)
            printf("...");
        printf(")");
        printf("\n   %d = number of digits in repeating cycle\n", n == 0 ? 1 : i - pos[n]);
        printf("\n");
    }
}
