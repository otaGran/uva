#include <iostream>

using namespace std;

int main(){
    int h1,a1,c1,h2,a2,c2,cnt = -1;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    int fuck[10000];
    bool strake = 0;
    while(h2>0){
        cnt++;

        if(h1<=a2&&h2>a1){
            strake = 1;
            h1 += c1;
        }else{
            strake = 0;
            h2 -= a1;
        }
        fuck[cnt]=strake;
        h1 -= a2;


    }
    cout << cnt+1 <<endl;
    for(int i = 0;i<=cnt;i++)
        cout << (fuck[i]==0?"STRIKE":"HEAL") << endl;


}