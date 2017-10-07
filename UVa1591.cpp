//
// Created by beans on 4/23/2017.
//
#include <iostream>

using namespace std;

long long N,SQ,SP,res = 0;

bool check(long long tmp_A,long long tmp_B){
    //cout << "enter check " << tmp_A << " " <<tmp_B <<endl;
    long long  pre_pos = 0;
    for(int i = 2;i<=N+1;i++){
        long long curPos = (i-1)*SP;
        curPos = (curPos+(curPos<<tmp_A))>>tmp_B;
        //cout << curPos << endl;
        if(curPos - pre_pos < SQ)
            return false;
        pre_pos = curPos;
    }
    return true;
}

void slove(){
    long long Qofs = N * SQ,res_A = 0,res_B = 0,res_k = Qofs<<10;
   // cout << Qofs << " " << res_k << endl;
    for(int tmp_A = 0;tmp_A<32;tmp_A++){
        for (int tmp_B = 0; tmp_B < 32; ++tmp_B) {
            long long tmp = (N-1)*SP;

            long long tmp_k = ((tmp+(tmp<<tmp_A))>>tmp_B)+SQ;
            //cout << tmp_k << endl;
            if(tmp_k>=Qofs&&tmp_k<res_k){
                //cout << tmp_k << endl;
                if(check(tmp_A,tmp_B)) {
                    res_A = tmp_A;
                    res_B = tmp_B;
                    res_k = tmp_k;
                }
            }
        }
    }
    cout << res_k << " " << res_A << " " << res_B << endl;


}

int main(){
    while(cin >> N >> SP >> SQ){
        slove();
    }
}