//
// Created by beans on 4/16/2017.
//
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct character {
    string type;
    int r, c;
};

character red[10];
character black;
int N;
char mapp[12][12];
int d[4][2]{
        0, 1,
        1, 0,
        -1, 0,
        0, -1
};
int hourse_moves[8][2] = {
        -2, -1,
        -2, 1,
        -1, 2,
        1, 2,
        2, 1,
        2, -1,
        1, -2,
        -1, -2
};
int leg[8][2] = {
        -1, 0,
        -1, 0,
        0, 1,
        0, 1,
        1, 0,
        1, 0,
        0, -1,
        0, -1

};

int hx[] = { -2, -1, -2, -1, 1, 2, 1, 2};  //马将军
int hy[] = { -1, -2, 1, 2, -2, -1, 2, 1};
int tx[] = { -1, -1, -1, -1, 1, 1, 1, 1};  //马蹩脚
int ty[] = { -1, -1, 1, 1, -1, -1, 1, 1};

bool find_horse(int r,int c){
    //cout << "horse" << endl;
    for (int i = 0; i < 8; ++i) {
        int tmp_r = r + hx[i],tmp_c = c + hy[i];
        if(tmp_r<1||tmp_r>10||tmp_c<1||tmp_c>9)
            continue;
        if(mapp[tmp_r][tmp_c]=='H'&&mapp[r+tx[i]][c+ty[i]]==0)
            return 1;
    }
    return 0;
}

bool find_cannon(int r,int c){
    //for hor
    //cout << "cannon" << endl;

    int left_c = c - 1,right_c = c + 1;
    //for left hor
    int left_cnt = 0,left_ok = 0;
    while(left_c>=1&&left_c<=9){
        if(mapp[r][left_c]!=0){
            if(mapp[r][left_c]=='C'&&left_cnt==1)
                left_ok = 1;
            left_cnt++;
        }
        left_c--;
    }
    //cout << "fin" << endl;
    //for right hor
    int right_cnt = 0,right_ok = 0;
    while(right_c<=9&&right_c>=1){
        if(mapp[r][right_c]!=0){
            if(mapp[r][right_c]=='C'&&right_cnt==1)
                right_ok = 1;
            right_cnt++;
        }
        right_c++;
    }

    //for ver
    int up_cnt = 0,up_ok = 0;
    int up_r = r - 1,down_r = r+1;
    while(up_r>=1&&up_r<=10){
        if(mapp[up_r][c]!=0){
            if(mapp[up_r][c]=='C'&&up_cnt==1)
                up_ok = 1;
            up_cnt++;
        }
        up_r--;

    }

    int down_cnt = 0,down_ok = 0;
    while(down_r<=10&&down_r>=1){
        if(mapp[down_r][c]!=0){
            if(mapp[down_r][c]=='C'&&down_cnt==1)
                down_ok = 1;
            down_cnt++;
        }
        down_r++;
    }

    return up_ok||down_ok||right_ok||left_ok;
}

bool find_chariot(int r,int c){
    //cout << "chariot" << endl;
    //for hor
    int ok = 0;
    int left_c = c - 1,right_c = c + 1;
    //for left hor
    while(left_c>=1&&left_c<=9){
        if(mapp[r][left_c]!=0){
            if(mapp[r][left_c]=='R')
                ok = 1;
            break;
        }
        left_c--;
    }
    //for right hor
    while(right_c<=9&&right_c>=1){
        if(mapp[r][right_c]!=0){
            if(mapp[r][right_c]=='R')
                ok = 1;
            break;
        }
        right_c++;
    }

    //for ver
    int up_r = r - 1,down_r = r+1;
    while(up_r>=1&&up_r<=10){
        if(mapp[up_r][c]!=0){
            if(mapp[up_r][c]=='R')
                ok = 1;
            break;
        }
        up_r--;
    }

    while(down_r<=10&&down_r>=1){
        if(mapp[down_r][c]!=0){
            if(mapp[down_r][c]=='R')
                ok = 1;
            break;
        }
        down_r++;
    }

    return ok;

}

bool find_general(int r,int c){
    //cout << "find_ger" << endl;
    int tmp_r = r + 1;
    while(tmp_r<=10){
        //cout << r << endl;
        if(mapp[tmp_r][c]!=0){
            if(mapp[tmp_r][c]=='G')
                return 1;//find general and no inter piece
            else
                return 0;//find inter pieces
        }
        tmp_r++;
    }
    return 0;//general not in this col
}

bool init_check() {
    return find_general(black.r,black.c);
}

bool slove() {
    for (int k = 0; k < 4; k++) {
        int tmp_r = black.r + d[k][0], tmp_c = black.c + d[k][1];
        if (tmp_r <= 3 && tmp_r >= 1 && tmp_c <= 6 && tmp_c >= 4) {
            //cout << tmp_r << " " << tmp_c <<endl;//legal moves
            int tmp_ok = 1;
            if (find_horse(tmp_r, tmp_c) || find_cannon(tmp_r, tmp_c) || find_general(tmp_r, tmp_c) ||
                find_chariot(tmp_r, tmp_c))
                tmp_ok = 0;
            if(tmp_ok)
                return 1;
        }
    }
    return 0;
}

int main() {
    while (cin >> N >> black.r >> black.c) {
        memset(mapp, 0, sizeof(mapp));
        black.type = 'G';
        if (N == 0 && black.r == 0 && black.c == 0)
            return 0;
        // mapp[black.r][black.c]='G';
        for (int i = 0; i < N; ++i) {
            cin >> red[i].type >> red[i].r >> red[i].c;
            mapp[red[i].r][red[i].c] = red[i].type[0];
        }
        if (init_check()) {
            cout << "NO" << endl;
            continue;
        }
        if (!slove())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}