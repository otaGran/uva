//
// Created by beans on 3/16/2017.
//
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int re(char x){
    //char x = max;
    int res = 0;
    if (isalpha(x)) {
        if (x >= 'a')
            res = x - 'a' + 36;
        else
            res = x - 'A' + 10;
    } else
        res = x - '0';
    //cout << res << endl;
    return res;
}

int main(){
    string tmp;
    //cout  << "here";



    while(cin >> tmp){
        //cout << tmp;
        //cin >> tmp;
        bool ok = 0;
        int max = 0;
        for (int i = 0; i < tmp.length(); ++i) {
            if(i==0&&(tmp[i]=='+'||tmp[i]=='-'))
                    continue;
            if(tmp[i]>max)
                max = tmp[i];

        }
        //cout << re(max) << endl;
        //
        for (int j = re(max)+1; j < 63; ++j) {

            int res = 0;

            for (int i = 0; i < tmp.length(); ++i) {
                if(i==0&&(tmp[i]=='+'||tmp[i]=='-'))
                    continue;
                res *= j;
                res += re(tmp[i]);
                if(res!=0)
                    res %= (j-1);
            }
            //cout << res << "  " << j <<endl;

            if(res ==0||res % (j-1) == 0){
                ok = 1;
                cout << (j<2?2:j) << endl;
                break;
            }
        }

        if(!ok)
            cout << "such number is impossible!\n";
    }
    //cout << "end" <<  endl;

}