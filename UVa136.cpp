//
// Created by beans on 2017/1/10.
//
#include <vector>
#include <queue>
#include <iostream>
#include <set>

using namespace std;
typedef long long LL;
int main() {
    priority_queue<LL, vector<LL>, greater<LL> > pq;
    set<LL> s;
    LL coffee[3] = {2,3,5};
    pq.push(1);
    s.insert(1);
    for (int i = 1;; ++i) {
        LL x = pq.top();
        pq.pop();
        if(i==1500) {
            cout << "The 1500'th ugly number is " << x << ".\n";
            return 0;
        }
        for (int j = 0; j < 3; ++j) {
            LL x2 = x * coffee[j];
            if(!s.count(x2)){
                s.insert(x2);
                pq.push(x2);
            }
        }
    }

}