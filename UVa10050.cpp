//
// Created by beans on 3/20/2017.
//
#include <iostream>

using namespace std;

long long parity[100], parity_cnt[100];

int main() {
    int T;
    cin >> T;
    while(T--) {
        int N, P, cnt = 0;
        cin >> N >> P;
        for (int i = 0; i < P; ++i) {
            cin >> parity[i];
            parity_cnt[i] = 0;
        }
        //start by sunday
        for (int j = 0; j < N; ++j) {
            int ok = 1;
            //every day check each parity
            for (int i = 0; i < P; ++i) {
                parity_cnt[i]++;
                if (parity_cnt[i] == parity[i]) {
                    ok = 0;
                    parity_cnt[i] = 0;
                }
            }
            if (j % 7 == 5 || j % 7 == 6)
                ok = 1;
            if (!ok)
                cnt++;
        }
        cout << cnt << endl;
    }

}

