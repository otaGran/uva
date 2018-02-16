//
// Created by beans_pc on 2/16/2018.
//bsearch + greedy
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


void pr(long long int* A,long long int k,long long int m, long long int mid){
    long long int tmp = 0,tmpm = m;
    vector<string> fuck;
    for(int i = k-1 ;i >=0;i--){
        if(tmp + A[i] > mid || tmpm > i+1){
            //cout << " /";
            fuck.push_back("/ ");
            tmpm--;
            //cout << tmp << endl;
            tmp = 0;
            tmp += A[i];
        }
        else{
            tmp += A[i];
        }
        if(i!=k-1) {
            fuck.push_back(" ");
            //cout << " ";
        }
        stringstream ss;
        ss << A[i];
        fuck.push_back(ss.str());
        //cout << A[i];
    }
    for(int i = fuck.size()-1;i>=0;i--)
        cout << fuck[i] ;
    cout << endl;
}

bool check(long long int* S, long long int* A,long long int k,long long int m,long long int mid,bool pr){
    int p = 0;

    for(int x = 0;x<m;x++){

        int tmp = mid;
        for(int i = p;i<k;i++){
            if(tmp >= A[i]) {
                tmp -= A[i];
                p++;
            }
            else
                break;
        }
    }
    if(p==k)
        return true;
    else
        return false;
}

void slove(long long int* S, long long int* A, long long int k, long long int m){



    long long int x = 0,y = S[k],mid;
    while(x<y){
        mid = x + (y-x)/2;

        //printf("%d %d %d\n",x,y,mid);
        if(check(S,A,k,m,mid,0)){
            y = mid;
        }else{
            x = mid+1 ;
        }

    }
    //cout << x << endl;
    pr(A,k,m,x);

}

int main(){
    long long int  kase,k,m,data[500+10],S[500+10];
    cin >> kase;
    while(kase--){
        S[0] = 0;
        cin >> k >> m;
        for(int i = 0;i<k;i++) {
            cin >> data[i];
            S[i+1] = S[i] + data[i];
            //cout << S[i+1]<< endl;
        }
        slove(S,data,k,m);
    }
}
