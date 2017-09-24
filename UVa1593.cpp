//
// Created by beans on 2017/1/11.
//
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <cstring>

using namespace std;

void print(string x,int length,char extra){
    cout << x ;
    while(length-- > x.length()){
        cout << extra;
    }
}

int main(){
    vector<string> filesname[1000+1];
    string x;
    int maxLength[100];
    memset(maxLength,0, sizeof(maxLength));
    int i;
    for (i = 0;getline(cin,x); i++) {
        //cout << x << '\n';
        //cin.get();
        stringstream ss(x);
        string tmp;
        for(int j = 0;ss >> tmp;j++){
            ///cout << tmp << "  " << tmp.length() << '\n';
            if (tmp.length() > maxLength[j])
                maxLength[j] = tmp.length();
            filesname[i].push_back(tmp);
            //cout << filesname[i][j] << '\n';
        }
    }
    for (int k = 0; k < i; ++k) {

        for (int j = 0; j < filesname[k].size()-1; ++j) {
            print(filesname[k][j],maxLength[j]+1,' ');
            //cout << filesname[k][j];
        }
        cout << filesname[k][filesname[k].size()-1];
        cout << '\n';
    }







}
