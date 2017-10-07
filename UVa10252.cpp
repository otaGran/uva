//
// Created by beans on 3/13/2017.
//
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

string a,b;

set<string> dict;

vector<string> f;

int cmp(const string& lhs,const string& rhs){
    if(lhs.length()!=rhs.length())
        return lhs.length() > rhs.length();
     else{
        for (int i = 0; i < lhs.length(); ++i) {
            if(lhs[i]==rhs[i])
                continue;
            else
                return lhs[i] < rhs[i];
        }
    }
    return 1;
}


void  max_find(string prefix,int a_pos,int b_pos){
    for (int i = a_pos; i < a.length(); ++i) {
        if(b.find(a[i],b_pos)!=string::npos) {
            //prefix += a[i];
            //cout << prefix << "  " <<b.find(a[i],b_pos) << "   " << b_pos << "\n";
            max_find(prefix+a[i],i+1,b.find(a[i],b_pos)+1);
        }
    }
    reverse(prefix.begin(),prefix.end());
    f.push_back(prefix);
    dict.insert(prefix);
}

int main(){

    while(cin >> a >> b){
        max_find("",0,0);
        sort(f.begin(),f.end(),cmp);
        /*for (vector<string>::iterator it = f.begin();it != f.end();it++) {
            cout << *it << "\n";
        }*/
        cout << f[0] << "\n";
        //cout << b.find(a[2],4) << "\n";
        dict.clear();
        f.clear();
    }

}