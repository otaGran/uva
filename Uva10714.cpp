//
// Created by beans on 2017/6/13.
//

#include <iostream>

using namespace std;

int T,N,num[1000000+1],fuck;

void slove(){
    //for best situation -> all in same direction
    int cnt = 0,res = 0;
    while(cnt!=N) {
        res++;
        for (int i = 0;i<(T/2);i++) {
            if(num[i]){
                if(i==0) {
                    num[i] = 0;
                    cnt++;
                }
                else{
                    num[i] = 0;
                    num[i-1] = 1;
                }

            }
            int j = (T-i-1);
            cout << i << " " << j << endl;
            if(num[j]){
                num[j] = 0;
                if(j==(T-1))
                    cnt++;
                else
                    num[j+1] = 1;
            }

        }
    for(int i = 0;i<T;i++)
        cout << num[i] << " ";
    cout << endl;
    }
    cout << res << endl;

}

void slove_fuck(){
    int res;
    for(int i = 0;i<T;i++){
        if(num[i]!=0) {
            if (i < (T / 2))
                num[i] = -1;
            else
                num[i] = 1;
        }
    }
    res = inver();
    if(T%2==0&&num[T/2]!=0){
        num[T/2] *= -1;
        int tmp = inver();
        if(tmp > res)
            res = tmp;
    }
    cout << res << endl;

}

int inver(){
    for(int i = 0;i<T;i++){
        if(num[i]!=0) {
           move(i)
        }
    }

}



int main(){
    cin >> fuck;
    while(fuck--){
        cin >> T >> N;
        cout << T << " " <<N;
        for(int i = 0;i<N;i++){
            int tmp;
            cin >> tmp;
            num[tmp] = 1;

        }
        for(int i = 0;i<T;i++)
            cout << num[i] << " ";
        cout << endl;
        slove();
    }
}
