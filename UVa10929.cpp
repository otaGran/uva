//
// Created by beans on 3/13/2017.
//
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    const int maxd = 1000;
    int value[maxd];
    string tmp;
    while(cin >> tmp){
        if(tmp.length()==1&&tmp[0]=='0')
            return 0;
        for (int i = 0; i < tmp.length(); ++i) {
            value[i] = tmp[tmp.length()-1-i]-'0';
        }
        for (int j = tmp.length()-1 ; j > 0; j--) {
            value[j-1] += value[j]%11*10;
            //value[j]%= 11;

        }
        printf("%s is ",tmp.c_str());
        if(value[0]%11)
            printf("not ");
        printf("a multiple of 11.\n");
    }
}
