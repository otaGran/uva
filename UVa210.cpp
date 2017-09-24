//
// Created by beans on 2017/9/23.
//


#include <cstring>
#include <string>
#include <deque>
#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>


using namespace std;
const int N = 1000 + 5;
int kase, proN, quantum;
int commandTime[5];
vector<string> order[N];
deque<int> qr;
queue<int> qb;
string s;
int t[N], p[N], var[26], lim;
bool loc = false;
int fuck = 0;

void run(int cur) {
    int left_time = quantum;
    string cur_order;
    while (left_time > 0) {

        cur_order = order[cur][p[cur]];
        //cout << cur_order << endl;
        if (cur_order[2] == 'd') {
            //left_time -= commandTime[4];
            return;
        }
        if (cur_order[2] == 'i') {
            cout << cur << ": " << var[cur_order[6] - 97] << endl;
            left_time -= commandTime[1];

        }
        if (cur_order[2] == '=') {
            //cout << "here" << endl;
            // int tmp_cnt = 5;
            int tmp_value = cur_order[4] - 48;
            if (cur_order.size() == 6)
                tmp_value = tmp_value * 10 + cur_order[5] - '0';
            //cout << tmp_value << endl;
            var[cur_order[0] - 97] = tmp_value;
            left_time -= commandTime[0];

        }
        if (cur_order[2] == 'c') {//lock
            left_time -= commandTime[2];
            if (loc) {
                qb.push(cur);
                return;
            } else {
                loc = true;


            }
        }
        if (cur_order[2] == 'l') {//unlock
            loc = false;
            left_time -= commandTime[3];
            if (!qb.empty()) {
                int tmp_cur = qb.front();
                qr.push_front(tmp_cur);
                qb.pop();
            }


        }
        ++p[cur];

        //cout << "fucked)))))))))))))))))))))" << endl;

    }

    qr.push_back(cur);
}

int main() {
    cin >> kase;
    //cout << kase << endl;

    while (kase--) {
        cin >> proN;
        for (int i = 0; i < 5; i++) {
            cin >> commandTime[i];
            //cout << commandTime[i] << endl;
        }
        cin >> quantum;
        for (int i = 1; i <= proN; i++) {
            order[i].clear();
            while (getline(cin, s)) {
                if (s == "")
                    continue;
                order[i].push_back(s);
                //cout << order[i].back() << endl;
                if (order[i].back() == "end")
                    break;
            }
            qr.push_back(i);
        }
        memset(p, 0, sizeof(p));
        memset(var, 0, sizeof(var));
        loc = false;
        //cout << qr.size();

        while (!qr.empty()) {
            int cur = qr.front();
            //cout << cur << endl;
            qr.pop_front();
            run(cur);
        }

        if (kase)
            cout << endl;
    }
    return 0;
}