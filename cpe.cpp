//
// Created by beans on 2017/5/24.
//

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int N, mm;
char s[100 + 10][100 + 10];
int gv[100 + 10][100 + 10];
int dp[4][2] = {{0,  1},
                {0,  -1},
                {1,  0},
                {-1, 0}};

struct Node {

    Node(int r, int c, int cnt);

    int r;
    int c;
    int cnt;
    int view[11] = {0,0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
};

Node::Node(int r, int c, int cnt) : r(r), c(c), cnt(cnt) {}


void bfs() {
    queue<Node> fuck;
    fuck.push(Node(0, 0,1));
    while (!fuck.empty()) {
        Node tmp = fuck.front();
        fuck.pop();
        cout << tmp.r << " " << tmp.c << " " << tmp.cnt << endl;
        if (tmp.r == N - 1 && tmp.c == N - 1) {
            mm = tmp.cnt;
            return;
        }
        if(gv[tmp.r][tmp.c]<tmp.cnt&&gv[tmp.r][tmp.c]!=0)
            continue;

        gv[tmp.r][tmp.c] = tmp.cnt;
        int id;
        if(s[tmp.r][tmp.c]>='a'){
            id = s[tmp.r][tmp.c]-'a'+1;
            id*=-1;
        }
        else{
            id = s[tmp.r][tmp.c]-'A'+1;
        }
        if(tmp.view[abs(id)]==(id*-1)) {
            cout << "fuck" << endl;
            continue;
        }
        cout << "here" << endl;
        tmp.view[abs(id)] = id;
        for (int i = 0; i < 4; i++) {
            int dr = tmp.r + dp[i][0];
            int dc = tmp.c + dp[i][1];
            if (dr >= 0 && dr < N && dc >= 0 && dc < N){
                cout << "here" << endl;
                Node dNode = tmp;
                dNode.r = dr;
                dNode.c = dc;
                dNode.cnt++;
                fuck.push(dNode);
            }
        }


    }

}

int slove() {
    mm = -1;
    memset(gv, 0, sizeof(gv));
    bfs();
    cout << mm << endl;
}


int main() {
    while (cin >> N) {
        for (int i = 0; i < N; i++) {
            scanf("%s", s[i]);
        }
        slove();
    }
}
