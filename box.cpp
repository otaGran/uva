#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
const ll kMaxN= 100010;

ll n, m, cntBox[kMaxN];
ll tmpM, tmpBox[kMaxN];

bool check(ll t){
    tmpM = m;
    for(ll i = 1; i <= n; i++) tmpBox[i] = cntBox[i];
    ll position = n; //最远的那个人需要走到的位置
    while(tmpBox[position] == 0) position--;
    while(tmpM--){ //最多可以有m个人
        ll cutCnt = t - position; //总共可以去掉的箱子数，优先从最远的开始去
        while(cutCnt){
            ll minCnt = cutCnt > tmpBox[position] ? tmpBox[position] : cutCnt;
            cutCnt -= minCnt; tmpBox[position] -= minCnt;
            while(tmpBox[position] == 0){
                position--;
                if(position == 0) return true;
            }
        }
    }
    return false;
}

void main(){
    scanf("%lld %lld", &n, &m);
    ll l = 0, r = 0;
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &cntBox[i]);
        r += cntBox[i];
        if(cntBox[i]) l = i;
    }
    r += l;
    ll ans = 0;
    while(l <= r){
        ll mid = (r + l) / 2;
        if(check(mid)){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}