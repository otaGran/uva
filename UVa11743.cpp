//
// Created by beans_pc on 12/9/2017.
//

#include <iostream>

using namespace std;

int n;
int main(){
    cin >> n;
    while(n--){
        int serial_number[16];
        for(int i = 0;i<4;i++){
            string tmp;
            cin >> tmp;
            for(int j = 0;j<4;j++){
                serial_number[i*4+j] = tmp[j]-'0';
            }
        }


        int feture_1 = 0,feture_2 = 0;
        for(int i = 14;i>=0;i-=2){
            //cout << i << " " << serial_number[i] << endl;
            int tmp = serial_number[i]*2;
            if(tmp>=
                    10){
                feture_1+=tmp%10;
                tmp/=10;
            }
            feture_1+=tmp;
        }
       // cout << feture_1 <<endl << feture_2 << endl;

        for(int i= 15;i>=0;i-=2)
            feture_2+=serial_number[i];

        int total = feture_1+feture_2;
        if(total%10) v
            cout << "Invalid";
        else
            cout << "Valid";
        cout << endl;
    }
}