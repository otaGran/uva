//
// Created by beans on 4/10/2017.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    string tmp;
    while(cin >> tmp) {
        int ok = 0;
        string one = tmp.substr(0,6);
        string two = tmp.substr(6,12);
        //cout << one << " " << two << endl;
        for (int i = 0; i < 6; ++i) {//for six side
            one[0] = tmp[i];//choose i as "1"
            one[5] = tmp[5-i];//so now 5-i is "6"
            if(i==1){
                one[1] = tmp[5];
                one[2] = tmp[2];
                one[3] = tmp[3];
                one[4] = tmp[0];

            }
            if(i==2){
                one[1] = tmp[1];
                one[2] = tmp[5];
                one[3] = tmp[0];
                one[4] = tmp[4];
            }
            if(i==3){
                one[1] = tmp[1];
                one[2] = tmp[0];
                one[3] = tmp[5];
                one[4] = tmp[4];
            }
            if(i==4){
                one[1] = tmp[0];
                one[2] = tmp[2];
                one[3] = tmp[3];
                one[4] = tmp[5];
            }
            if(i==5){
                one[1] = tmp[4];
                one[2] = tmp[2];
                one[3] = tmp[3];
                one[4] = tmp[1];
            }
            for (int j = 1; j < 5; ++j) {//for four rotation

                char cha = one[1];
                one[1] = one[2];
                one[2] = one[4];
                one[4] = one[3];
                one[3] = cha;
                //cout << one << endl;
                if(!one.compare(two))
                    ok = 1;
            }
        }

        if (ok)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;
    }

}

