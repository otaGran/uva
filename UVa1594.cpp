//
// Created by beans on 2017/1/11.
//
#include <iostream>
#include <set>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

//typedef int[] Set;
void next_ducci(int *x, int n) {
    int tmp = x[0];
    for (int i = 0; i < (n - 1); ++i) {
        x[i] = abs(x[i] - x[i + 1]);
    }
    x[n - 1] = abs(x[n - 1] - tmp);
}

bool check_dup(int *a, int *b, int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i])
            return false;
    }
    return true;

}

bool check_zero(int *x, int n) {
    for (int i = 0; i < n; ++i) {
        if (x[i] != 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int howmany;
        cin >> howmany;
        int num[howmany];
        for (int i = 0; i < howmany; ++i) {
            cin >> num[i];
            //printf("%d " ,num[i]);
        }
        //printf("\n");
//        next()
        int flag = 0;
        for (int j = 0; j < 1000; ++j) {
            int next[howmany];
            memcpy(next, num, sizeof(num));
            next_ducci(next, howmany);
            /*
            for (int i = 0; i < howmany; ++i) {
                printf("%d ",next[i]);
            }
            printf("\n");
             */
            if (check_zero(next,howmany)) {
                flag = 1;
                break;
            }
            if (check_dup(num, next, howmany)) {
                flag = 0;
                break;
            }
            memcpy(num,next, sizeof(num));

        }

        if (flag)
            cout << "ZERO";
        else
            cout << "LOOP";
        cout << '\n';
    }
}
