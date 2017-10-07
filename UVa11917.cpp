//
// Created by beans on 2017/10/6.
//
#include <iostream>

using namespace std;

string subject[100+10];
int date[100+10];
int main(){
    int kase;
    int cnt = 1;
    cin >> kase;
    while(kase--){

        int n;
        cin >> n;
        for(int i = 0;i<n;i++){
            cin >> subject[i] >> date[i];
        }
        int due_date;
        cin >> due_date;
        string target;
        cin >> target;
        int ok = 0;
        printf("Case %d: ",cnt++);
        for(int i = 0;i<n;i++){
            if(target==subject[i]){
                ok = 1;
                if(date[i]<=due_date)
                    cout << "Yesss" << endl;
                else if(date[i]>due_date+5)
                    cout << "Do your own homework!"<<endl;
                else
                    cout << "Late"<<endl;
                break;
            }
        }
        if(!ok)
            cout << "Do your own homework!"<<endl;

    }
}

