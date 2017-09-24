//
// Created by beans on 2017/3/30.
//不记录具体排列 length<8
//
#include <iostream>
#include <cstring>

using namespace std;

string tmp;

int num[10000];

long long lac(int deep, int pre_bit) {
    long long tmp_cnt = 0;
    //printf("now_deep : %d   pre_bit : %d\n", deep, pre_bit);
    if (deep == tmp.length())
        return 1;
    for (int i = 1; i <= tmp.length() + 1; i++) {
        if (num[i])
            continue;
        int tmp_value = i;
        if (tmp[deep] == '?' || tmp[deep] == 'I' && pre_bit > tmp_value || tmp[deep] == 'D' && tmp_value > pre_bit) {
            num[i] = 1;
            tmp_cnt += lac(deep + 1, i);
            num[i] = 0;
        }
    }
    return tmp_cnt;
}

long long pre_cal() {
    long long tmp_cnt = 0;
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= tmp.length() + 1; i++) {
        num[i] = 1;
        tmp_cnt += lac(0, i);
        num[i] = 0;
    }
    return tmp_cnt;
}

int main() {
    long long cnt = 9;
    while (getline(cin, tmp))
        cout << pre_cal() << endl;
}