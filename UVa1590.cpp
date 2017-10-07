//
// Created by beans on 4/15/2017.
//
#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        int ip[n][4];
        string ip_bin[n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 4; ++j) {
                cin >> ip[i][j];
                getchar();
               // cout << ip[i][j] << ".";
                for (int k = 0; k < 8; ++k) {
                    if((1<<7-k)<=ip[i][j]) {
                        ip_bin[i] += "1";
                        ip[i][j] -= (1<<7-k);
                    }
                    else
                        ip_bin[i]+="0";

                }


            }
           // cout << endl;
           // cout << ip_bin[i] << endl;
        }
        int min_cnt = 32;

        for(int i = 0;i<32;i++){
            char tmp = ip_bin[0][i];
            int ok = 1;
            for (int j = 1; j < n; ++j) {
                if(ip_bin[j][i]!=tmp)
                    ok = 0;
            }
            if(!ok){
                min_cnt = i;
                break;
            }
        }
        //cout << min_cnt << endl;
        for (int i = 0; i < 4; ++i) {
            int res = 0;
            for (int j = 0; j < 8; ++j) {
                if(i*8+j<min_cnt)
                    res += (1<<7-j)*(ip_bin[0][i*8+j]-'0');
            }
            cout << res;
            if(i!=3)
                cout << ".";
            else
                cout << endl;
        }


        for (int i = 0; i < 4; ++i) {
            int res = 0;
            for (int j = 0; j < 8; ++j) {
                if(i*8+j<min_cnt)
                    res += (1<<7-j)*1;
            }
            cout << res;
            if(i!=3)
                cout << ".";
            else
                cout << endl;
        }


    }
}
