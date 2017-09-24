//
// Created by beans on 2017/1/11.
//
#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    while(cin >> n && n!=0){
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            q.push(i+1);
        }
        cout << "Discarded cards:";
        while(q.size()!=1){
            if(q.size()!=n)
                cout << ",";
            cout << " " << q.front();
            q.pop();
            //int tmp = q.front();
            q.push(q.front());
            q.pop();
        }
        cout << '\n' << "Remaining card: " << q.front() << '\n';
    }
}
