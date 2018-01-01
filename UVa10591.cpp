//
// Created by beans on 2017/12/22.
//
#include <iostream>
#include <sstream>
#include <cstring>


using namespace std;


int main(){
    int kase = 1,n;
    cin >> n;
    while(n--){

        int target,num = 0;
        cin >> target;
        string s;
        stringstream ss;
        ss << target;
        ss >> s;
        ss.clear();
        printf("Case #%d: %d is a",kase++,target);
        for(int i = 0;i<1000;i++){
            num = 0;
            for(int j = 0;j<s.size();j++){
                num += (s[j]-'0')*(s[j]-'0');
            }
            //cout << num <<endl;
            ss << num;
            ss >> s;
            ss.clear();
            if(s.size()==1)
                break;
        }
        if(s[0]=='1')
            cout << " Happy number."<<endl;
        else
            cout << "n Unhappy number."<<endl;

    }
}