//
// Created by beans on 2017/1/8.
//
#include <cstdio>
#include <cstring>
#include <cmath>
#include <math.h>

//化未知为已知
int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    char master[100 + 10], driven[100 + 10];
    while (scanf("%s %s", master, driven) == 2) {
        int res = max(strlen(master), strlen(driven));
        int i, k, ok = 1, close = 0, left = 0, right = 0;
        //偏移量
        for (i = 0; i <= strlen(driven), strlen(master); i++) {
            //向右偏移
            ok = 1;
            for (int j = 0; j < strlen(master); ++j) {
                if (i + j >= strlen(driven))
                    break;
                if (master[j] == '2' && driven[i + j] == '2')
                    ok = 0;
            }
            //找到结果
            if (ok) {
                // printf("right%d\n",i);
                right = max(strlen(master) + i, strlen(driven));
                //printf("%d\n", max(strlen(master) + i, strlen(driven)));
                close = 1;
                break;
            }

        }
        for (i = 0; i <= strlen(driven) + strlen(master); i++) {
            //向左偏移
            ok = 1;
            for (int j = 0; j < strlen(driven); ++j) {
                if (i + j >= strlen(master))
                    break;
                if (driven[j] == '2' && master[i + j] == '2')
                    ok = 0;
            }
            //找到结果
            if (ok) {
                // printf("right%d\n",i);
                left = max(strlen(driven) + i, strlen(master));
                //printf("%d\n", max(strlen(master) + i, strlen(driven)));
                close = 1;
                break;
            }

        }
        printf("%d\n", min(left, right));
    }
}