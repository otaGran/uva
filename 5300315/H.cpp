//
// Created by beans on 2018/3/22.
//
#include <iostream>

using namespace std;

int main(){
    string first,sec;
    cin >> first >> sec;
    int leftPos = -1,rightPos = -1,cnt = 0;
    char target = first[cnt];
    for(int i = 0;i<sec.length();i++){
        if(sec[i]==target){
            cnt++;
            if(cnt==first.length()){
                leftPos = i;
            }else{
                target = first[cnt];
            }
        }
    }
   // cout << leftPos << endl;

    cnt = first.length()-1;
    target = first[cnt];
    for(int i = sec.length()-1 ;i>=0;i--){
        if(sec[i]==target){
            cnt--;
            if(cnt==-1){
                rightPos = i-1;
            }else{
                target = first[cnt];
            }
        }
    }
   // cout << rightPos << endl;
    if(leftPos==-1||rightPos==-1||rightPos<leftPos)
        cout << 0 << endl;
    else
        cout << (rightPos - leftPos) + 1 << endl;
}