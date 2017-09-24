//
// Created by beans on 2017/1/10.
//
#include <queue>
#include <cstdio>
#include <map>

using namespace std;
const int maxt = 1000 + 10;

int main() {
    int kase = 0, t;
    while (scanf("%d", &t) == 1 && t) {
        printf("Scenario #%d\n", ++kase);
        map<int, int> team;//team member -> team number

        //input team member
        for (int i = 0; i < t; ++i) {
            int n, x;
            scanf("%d", &n);
            while (n--) {
                scanf("%d", &x);
                team[x] = i;
            }
        }
        //input op
        queue<int> q;
        queue<int> q2[maxt];//q2 for local team
        for (;;) {
            int x;
            char op[100];
            scanf("%s", op);
            if (op[0] == 'S')
                break;
            else {
                if (op[0] == 'D') {
                    int front_t = q.front();
                    printf("%d\n", q2[front_t].front());
                    q2[front_t].pop();
                    if (q2[front_t].empty())
                        q.pop();
                } else if (op[0] == 'E') {
                    scanf("%d", &x);
                    int team_number = team[x];
                    if (q2[team_number].empty())
                        q.push(team_number);
                    q2[team_number].push(x);
                }

            }

        }
        printf("\n");

    }
}