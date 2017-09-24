//
// Created by beans on 2017/1/18.
//
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
pair<int,int> cash[100];
int target, k, tmp = 0,cnt = 0;
int res = 0;

int fuck(int cur) {
    if(tmp>res)
        res = tmp;
    if (tmp>target||cur>=k) {
        return 0;
    } else {
        for (int i = cur; i < k; ++i) {
            for (int j = 0; j <= cash[i].first; ++j) {
                if (tmp + cash[i].second*j <= target) {
                    tmp += cash[i].second*j;
                    fuck(i+1);
                    tmp-=cash[i].second*j;
                }
                else{
                    return 0;
                }
            }
        }

    }
}

bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    return a.second>b.second;
}
int main() {

    while (cin >> target) {
        cnt = 0;
        tmp = 0;

        res = 0;
       //memset(res,0, sizeof(res));
        memset(cash,0, sizeof(cash));

        cin >> k;

        for (int i = 0; i < k; ++i) {
            cin >> cash[i].first >> cash[i].second;
            //printf("\n");
        }
        //sort(cash,cash+k,cmp);
        /*
        for (int j = 0; j < k; ++j) {
            //printf("%d %d\n",cash[j].first,cash[j].second);
        }
         */
        fuck(0);
        /*

        for (int l = 0; l < ttt; ++l) {
            //printf("%d\n",res[l]);
        }
         */

        //sort(res,res+ttt,ccc);
        cout << res << "\n";
    }
}