//
// Created by beans on 4/10/2017.
//
#include <iostream>
#include <cstring>

using namespace std;

int n;
int H[9][9], V[9][9];
int first = 1;

bool reachable(int r, int c, int size) {
   // cout << "checking cor : " << r << " " << c <<  endl;
    int hv = 1, vh = 1;
    if (r + size >= n || c + size >= n)
        return 0;
    int target_r, target_c;
//    process vh
    target_r = r;
    target_c = c;
    //int inner_cnt = 0;
    for (int i = 0; i < size; ++i) {
        if (!H[target_r][target_c]) {
            hv = 0;
           // cout << "1" <<endl;
            //cout << target_r << " " <<target_c << endl;
        }
        else
            target_c++;
    }
    for (int i = 0; i < size; ++i) {
        if (!V[target_r][target_c]) {
            hv = 0;
            //cout << "2" << endl;
            //cout << target_r << " " <<target_c << endl;
        }
        else
            target_r++;
    }
//    process hv
    target_r = r;
    target_c = c;
    for (int i = 0; i < size; ++i) {
        if (!V[target_r][target_c]) {
            vh = 0;
            //cout << "3" << endl;
        }
        else
            target_r++;
    }
    for (int i = 0; i < size; ++i) {
        if (!H[target_r][target_c]) {
            vh = 0;
            //cout << "4" << endl;
        } else
        target_c++;
    }

    //cout << (hv&&vh) << endl;
    return hv && vh;
}

bool cnt(int size) {
    //cout << "checking size : " << size << endl;
    int outer_cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {

            if (reachable(i, j, size))
                outer_cnt++;
        }
    }
    if (outer_cnt) {
        printf("%d square (s) of size %d\n", outer_cnt, size);
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int kase = 0;
    while (cin >> n) {
        memset(H, 0, sizeof(H));
        memset(V, 0, sizeof(V));
        int ok = 0;
        if (!first)
            printf("\n**********************************\n\n");
        printf("Problem #%d\n\n", ++kase);
        int i;
        cin >> i;
        //cout << i << endl;
        for (; i > 0; i--) {
            char x;
            int r, c;
            cin >> x >> r >> c;
            if (x == 'H')
                H[r-1][c-1] = 1;
            else
                V[c-1][r-1] = 1;

            //cout << x << " "  << r << " " << c <<endl;

        }

        for(int i = 0;i < n ;i++){
            for (int j = 0; j < n; ++j) {
              //  cout << V[i][j] << " ";
            }
            //cout << endl;
        }



        for (int j = 1; j <= n; ++j) {
            if (cnt(j))
                ok = 1;
        }
        if (!ok)
            printf("No completed squares can be found.\n");
        if (first)
            first = 0;
    }
}