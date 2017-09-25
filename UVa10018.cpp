//
// Created by beans on 2017/9/25.
//
#include <iostream>

using namespace std;
long long int n;
bool ch(long long int n){
    string tmp = to_string(n);
    for(int i =  0;i<tmp.size()/2;i++){
        if(tmp[i]!=tmp[tmp.size()-i-1])
            return false;
    }
    return true;
}

int get(long long int n){
    string tmp = to_string(n);
    long long int re = 0;
    for(int i = tmp.size()-1;i>=0;i--){
        re = re*10+tmp[i]-'0';
    }
    return re;
}

int main(){
    int m;
    cin >> m;
    while(m--) {
       cin >> n;
            int cnt = 0;
            while (!ch(n)) {
                n += get(n);
                cnt++;
            }
            cout << cnt << " " << n << endl;

        }

}