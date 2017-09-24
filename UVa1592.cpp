//
// Created by beans on 2017/1/11.
//
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
using namespace std;

int main(){
    int row,col;
    while(cin >> row >> col) {
        map<int,int> IDcache;
        map<string,int> pre;
        vector<string> vp;
        set<string> stringcache;
        int database[1000+10][10];
        cin.get();

        //pre string -> ID
        for (int i = 0; i < row; ++i) {

            string x;
            getline(cin, x);
            //cout << x << '\n';
            char *pch = strtok((char *) x.c_str(), ",");
            for (int j = 0; pch; ++j) {
                if (!pre.count(pch)) {
                    pre[pch] = pre.size();
                }
                int id = pre[pch];
                database[i][j] = id;
                //cout << id << '\n';
                pch = strtok(NULL, ",");

            }
        }

        bool flag = false;
        for (int i = 0; i < col - 1; ++i) {
            for (int j = 0; j < col; ++j) {
                for (int k = 0; k < row; ++k) {
                    if (i == j)
                        continue;
                    int tmp = database[k][i] * 10000 + database[k][j];
                    if (IDcache.count(tmp)) {
                        flag = true;
                        printf("NO\n%d %d\n%d %d\n", IDcache[tmp] + 1, k + 1, i + 1, j + 1);
                        break;
                    } else {
                        IDcache[tmp] = k;
                    }
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }


        if (!flag)
            cout << "YES" << '\n';

    }


}
