//
// Created by beans on 2017/3/28.
//
#include <iostream>

using namespace std;
char map[100][100 + 1];
int M, N;

void boom(int r, int c) {
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0)
                continue;
            if (dr + r < 0 || dr + r >= M || dc + c < 0 || dc + c > N)
                continue;
            if (map[dr + r][dc + c] == '*')
                continue;
            map[dr + r][dc + c]++;


        }
    }

}

int main() {
    // int M,N;
    int cnt = 1;
    while (cin >> M >> N) {
        if(!M&&!N)
            return 0;
        if(cnt!=1)
            printf("\n");
        printf("Field #%d:\n",cnt++);

        for (int i = 0; i < M; ++i) {
            cin >> map[i];
            for (int j = 0; j < N; ++j) {
                if (map[i][j] == '.')
                    map[i][j] = '0';
            }
        }


        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (map[i][j] == '*') {
                    boom(i, j);
                }
            }
        }
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
    }
}
