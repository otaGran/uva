//
// Created by beans on 2017/4/14.
//

#include <map>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<char,string> morse_table;
vector<string> dict;

bool slove_by_sub(int di,string target){

}


bool slove_by_add(int di,string target){

}

bool slove_by_normal(string target){
    int cnt = 0;
    for (vector<string>::iterator it = dict.begin();it!=dict.end();it++) {
        int ok = 1;

        for (int i = 0; i < it->length(); ++i) {
            //cout << (*it)[i] << endl;
            strcmp()
        }

        if(ok){
            if(!cnt)
                cout << *it;
            cnt++;
        }

    }



    if(cnt>1)
        cout << "!" << endl;
    if(cnt==1)
        cout << endl;
    return cnt;

    //return 1;

}

void slove(string target){
    cout << target << endl;
    slove_by_normal(target);

    if(!slove_by_normal(target)){
        int di = 0;
        while(di++){
            if(slove_by_add(di,target))
                break;
            if(slove_by_sub(di,target))
                break;
        }
    }



}

int main(){
    while(cin){
        morse_table.clear();
        dict.clear();
        char tmp_char;
        string tmp_str;

        //read morse table
        while(cin >> tmp_char){
            if(tmp_char=='*')
                break;
            cin >> tmp_str;
            morse_table[tmp_char] = tmp_str;
        }
        cout << "morse_table" << endl;
        for(map<char,string>::iterator it = morse_table.begin();it!=morse_table.end();it++){
            cout << it->first << " " << it->second << endl;
        }
        cout << endl;

        //read dict
        while(cin >> tmp_str){
            if(tmp_str.length()==1&&tmp_str[0]=='*')
                break;
            dict.push_back(tmp_str);
        }
        cout << "dict" << endl;
        for(vector<string>::iterator it = dict.begin();it!=dict.end();it++){
            cout << *it << endl;

        }
        cout << endl;

        //start decoding
        while (cin >> tmp_str){
            if(tmp_str.length()==1&&tmp_str[0]=='*')
                break;
            slove(tmp_str);
        }

    }
}
