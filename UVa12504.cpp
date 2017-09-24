//
// Created by beans on 2017/1/12.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <map>
using namespace std;

struct pa{
    string key;
    string value;
};

bool cmp(pa a,pa b){
    return a.key < b.key;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        string source,dest;
        getchar();
        getline(cin,source);
        getchar();
        getline(cin,dest);
        //cout << source << '\n' << dest << '\n';
        set<string> xinde,jiude;
        map<string,string> xindecache,jiudecache;
        replace(source.begin(),source.end(),',',' ');
        replace(source.begin(),source.end(),'{',' ');
        replace(source.begin(),source.end(),'}',' ');
        replace(dest.begin(),dest.end(),',',' ');
        replace(dest.begin(),dest.end(),'{',' ');
        replace(dest.begin(),dest.end(),'}',' ');
        stringstream xx(source);
        string tmp;
        while (xx >> tmp){
            int x = tmp.find(":");
            //cout << x << '\n';
            pa fuck;
            fuck.key = tmp.substr(0,x);
            fuck.value = tmp.substr(x+1);
            jiude.insert(fuck.key);
            jiudecache[fuck.key] = fuck.value;
           // cout << fuck.key << ' ' << fuck.value << '\n';
        }
        stringstream yy(dest);
        while (yy >> tmp){
            int x = tmp.find(":");
            //cout << x << '\n';
            pa fuck;
            fuck.key = tmp.substr(0,x);
            fuck.value = tmp.substr(x+1);
            xinde.insert(fuck.key);
            xindecache[fuck.key] = fuck.value;
            //cout << fuck.key << ' ' << fuck.value << '\n';
        }

        
        //vector<string> del,add,change;
        int flag_add = true;
        for (set<string>::iterator it = xinde.begin(); it!=xinde.end() ; ++it) {
            if(!jiude.count(*it)) {
                if(flag_add){
                    flag_add = false;
                    cout << '+';
                }
                else{
                    cout << ',';
                }
                cout << *it;
            }

        }
        if(!flag_add)
            cout << '\n';
        int flag_del = true;
        for (set<string>::iterator it = jiude.begin(); it!=jiude.end() ; ++it) {
            if(!xinde.count(*it)) {
                if (flag_del) {
                    flag_del = false;
                    cout << '-';
                } else {
                    cout << ',';
                }
                cout << *it;
            }

        }
        if(!flag_del)
            cout << "\n";
        int flag_change = true;
        for (set<string>::iterator it = jiude.begin(); it!=jiude.end() ; ++it) {
            if(xinde.count(*it)&&xindecache[*it]!=jiudecache[*it]) {
                if (flag_change) {
                    flag_change = false;
                    cout << '*';
                } else {
                    cout << ',';
                }
                cout << *it;
            }

        }
        if(!flag_change)
            cout << '\n';
        if(flag_add&&flag_change&&flag_del)
            cout << "No changes\n";
        cout << '\n';
        //cout << source << '\n';

    }
}