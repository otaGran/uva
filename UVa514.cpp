//
// Created by beans on 2017/9/23.
//图有问题 只有一条股道
//注意输入输出
//思路:不考虑全局 一步一步模拟
#include <iostream>
#include <stack>

using namespace std;
int ok = 1,a = 1,b = 1,n;
int target[10000];
stack<int> s;


int main() {
    while (cin >> n) {
        //cout << n << endl;
        if (n == 0)
            return 0;
        while (1) {
           // cout << "here" << endl;
            while (!s.empty())
                s.pop();
            a = b = ok = 1;
            cin >> target[1];
            //cout << target[1] << endl;
            if (target[1] == 0) {
                cout << "" << endl;
                break;
            }
            for (int i = 2; i <= n; i++) {
                cin >> target[i];
                //cout << target[i] << endl;
            }
            while (b <= n) {//直通
                if (a == target[b]) {
                    a++;
                    b++;
                } else if (!s.empty() && s.top() == target[b]) {//stack头相符
                    b++;
                    s.pop();
                } else if (a <= n) {//stack仍有空间暂放
                    s.push(a++);
                } else {//fucked
                    ok = 0;
                    break;
                }
            }
            cout << (ok ? "Yes" : "No") << endl;
        }
    }
}