//
// Created by beans on 2017/9/27.
//
#include <iostream>
#include <vector>
using namespace std;
vector<int> s,num;
int res = 0,n,kase;

void slove(){
    int cnt = 1;
    for(int i = n-2;i>=0;i--){
        if(s[i-1]>num[i])
            continue;
        else{
            cnt++;
            //cout << num[i] << endl;
        }
    }
    res = cnt;
}


int main(){
    cin >> kase;
    while(kase--){
        s.clear();
        num.clear();
        cin >> n;
        for(int i = 0;i<n;i++){
            int tmp;
            cin >> tmp;
            num.push_back(tmp);
            if(i!=0)
                s.push_back(num[i]+s[i-1]);
            else
                s.push_back(num[i]);
        }
        slove();
        cout << res << endl;
    }
}




