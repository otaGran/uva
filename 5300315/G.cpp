//
// Created by beans on 2018/3/16.
//
#include <iostream>

using namespace std;
string s;
int k,res = 0;
string fob[13];

bool check(int startPos,int endPos){
    //cout << startPos << " " << endPos<< endl;
    int num = endPos - startPos + 1;
    if(num<2)
        return true;
    for(int x = 0;x<k;x++) {
        if(s[startPos]==fob[x][0]||s[startPos]==fob[x][1]) {
            int cnt = 0;
            for (int i = startPos; i <= endPos; i++) {
                if (s[i] == fob[x][0] || s[i] == fob[x][1])
                    cnt++;
            }
            if (cnt == num)
                return true;
        } else{
            continue;
        }
    }
    return false;
}

int slove(int startPos,int endPos){
        int firstCnt = 0, secondCnt = 0;
        for (int i = startPos; i <= endPos; i++) {
            if (s[i] == s[startPos])
                firstCnt++;
            else
                secondCnt++;
        }

        return min(firstCnt, secondCnt);

}

int main(){

    cin >> s >> k;
    for(int i = 0;i<k;i++) {
        cin >> fob[i];
        //cout << fob[i][1] << endl;
    }
    int startPos = 0,endPos = 0,x = 0;

    while(1){
        if(x>=s.length())
            break;
        else{
            int tmp = x;
            if(check(x,x+1)){
                x++;
                int fuck = 0;
                for(int i = 0;i<k;i++)
                    if(s[tmp]==fob[i][0]||s[tmp]==fob[i][1]){
                        fuck = i;
                        break;
                    }
                while(x < s.length()&&(s[x]==fob[fuck][0]||s[x]==fob[fuck][1])){
                    x++;
                }
               // cout << "finish"<<endl;
                res += slove(tmp,x-1);
            }else{
                x++;
            }
        }
    }
    //res += slove(startPos,s.length()-1);

    cout << res << endl;
}