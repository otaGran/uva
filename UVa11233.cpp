//
// Created by beans on 2017/12/22.
//


#include <cstring>
#include <iostream>

using namespace std;

int main(){
    int L,N;
    string irr[20][2],tmp;
    cin >> L >>N;
    for(int i = 0;i<L;i++){
        cin >> irr[i][0] >> irr[i][1];
    }

    for(int i = 0;i<N;i++){
        cin >> tmp;
        char last = tmp[tmp.size()-1],slast = tmp[tmp.size()-2];
        int ok = 0;
        for(int i = 0;i<L;i++){
            if(tmp==irr[i][0]) {
                cout << irr[i][1] << endl;
                ok = 1;
                break;
            }
        }
        if(!ok) {
            if (last == 'y') {
                if (slast == 'a' || slast == 'e' || slast == 'i' || slast == 'o' || slast == 'u') {
                    cout << tmp << "s" << endl;
                } else {
                    for (int i = 0; i < tmp.size() - 1; i++)
                        cout << tmp[i];
                    cout << "ies" << endl;
                }
            } else {
                if (last == 'o' || last == 's' || last == 'x' || last == 'h' && slast == 's' ||
                    last == 'h' && slast == 'c') {
                    cout << tmp << "es" << endl;
                } else {
                    cout << tmp << "s" << endl;

                }
            }
        }

    }
}