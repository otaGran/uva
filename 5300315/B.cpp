#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int main(){
    set<int> numSet;
    int n,num[5000],redCnt = 0;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> num[i];
        if(num[i]<=n)
            numSet.insert(num[i]);

    }
    sort(num,num+n);
    int cnt = 0;

    cout << n-numSet.size();
}