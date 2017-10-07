//
// Created by beans on 3/16/2017.
//
#include <iostream>
#include <set>

using namespace std;

set<int> dict;

int main(){
    int n;
    int cnt = 1;
    while(cin >> n){
        dict.clear();
        int num[n];
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }
        int ok = 1;
        if(num[0]<1)
            ok = 0;
        for (int k = 1; k < n; ++k) {
            if(num[k-1] > num[k])
            ok = 0;
        }
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i <= j; ++i) {
                int tmp = num[i]+num[j];
                //cout << tmp << "\n";
                if(dict.count(tmp))
                    ok = 0;
                else
                    dict.insert(tmp);
            }
        }
        printf("Case #%d: It is ",cnt++);
        if(!ok)
            printf("not ");
        printf("a B2-Sequence.\n\n");

    }
}
