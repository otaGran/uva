//
// Created by beans on 4/8/2017.
//
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    char a[100+1];
    char b[100+1];
    map<char,int> A;
    map<char,int> B;
    while(cin >> a >> b){
        A.clear();
        B.clear();
        for (int i = 0; a[i]!='\0'; i++) {
            if(!A.count(a[i]))
                A[a[i]] = 0;
            A[a[i]]++;
        }
        for (int i = 0; b[i]!='\0'; i++) {
            if(!B.count(b[i]))
                B[b[i]] = 0;
            B[b[i]]++;
        }
        if(A.size()!=B.size()) {
            cout << "NO\n";
            continue;
        }
        int num_a[A.size()],num_b[A.size()];
        int cnt = 0;
        for (map<char,int>::iterator it = A.begin();it!=A.end();it++) {
            num_a[cnt++] = it->second;
        }
        cnt = 0;
        for(map<char,int>::iterator it = B.begin();it!=B.end();it++){
            num_b[cnt++] = it->second;
        }
        sort(num_a,num_a+A.size());
        sort(num_b,num_b+A.size());
        int ok = 1;
        for (int j = 0; j < A.size(); ++j) {
            if(num_a[j]!=num_b[j])
                ok = 0;
        }
        if(ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

}