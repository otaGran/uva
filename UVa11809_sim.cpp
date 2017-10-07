//
// Created by beans on 4/8/2017.
//
#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

void max_E(int power,double mt){
    //cout << power << endl;
    //cout << mt << endl;
    int res_power = 0;
    double tmp = 1;
    int cnt = 0;
    while(res_power<power&&power!=0){
        cnt++;
        tmp*=2.0;
        if(tmp>10){
            tmp/=10.0;
            res_power++;
        }

    }
    double m_tmp = 0.5;
    double m_cnt = 0;
    double fuck = mt / tmp;
    //cout << tmp << endl << mt << endl;
    //cout << fuck << endl;
    while(fuck>=1.0-0.0000001){
        cnt++;
        fuck /= 2.0;
       // cout << "fucked" << endl;
    }

    while(1){
        if(m_tmp>fuck){
            cout << m_cnt << " ";
            break;
        }
        m_cnt++;
        m_tmp += pow(2,(m_cnt+1)*-1.0);


    }

    tmp = 1;
    int res = 0;
    int ff = 0;
    while(1){
        if((1<<res++)>cnt){
            cout << --res << endl;
            break;
        }
    }

}

int main(){
    int first;

    int mantissa[15];
    int power;
    while(first = getchar() - '0'){
        getchar();//for "."
        double mt = first;
        for (int i = 1; i < 16; ++i) {
            mantissa[i] = getchar() - '0';
            mt += (double)mantissa[i] * pow(10.0,-1.0*i);
            //printf("%.15lf\n",mt);
           // cout << mantissa[i] << endl;
        }
        getchar();//for "e"
        cin >> power;
        getchar();//for "\n"
        if(power==0&&mt==0)
            return 0;
        max_E(power,mt);

        //cout << power << endl;

    }
}