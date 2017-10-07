//
// Created by beans on 4/23/2017.
//
//有毒！k>=N*SQ

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

double m, n;
int sq[900];
double total;

void slove() {
    int cnt = 1;
    double level = 0,before = 0;
    sort(sq,sq+(int)(m*n));
    before = sq[0];
    for (int i = 1; i < m * n; ++i) {
        //cout << sq[i] << endl;
        double need_to_this_sq = 0;
        need_to_this_sq = (sq[i]-before)*cnt*100;

        if(need_to_this_sq > total){
            break;
        }
        else{
            if(need_to_this_sq==total){
                total -= need_to_this_sq;
                before = sq[i];
                break;
            }
            else{
                cnt++;
                total -= need_to_this_sq;
                before = sq[i];
            }

        }

    }
    if(total!=0){
        before += total/(cnt*100);
    }
    //cout << cnt << endl;



    printf("Water level is %.2lf meters.\n%.2lf percent of the region is under water.\n\n", before,
           (double) cnt / (double) (m * n)*100.00);
}

int main() {
    int cnt = 0;
    while (cin >> m >> n && m && n) {
        printf("Region %d\n", ++cnt);
        memset(sq, 0, sizeof(sq));
        for (int i = 0; i < m * n; ++i) {
            cin >> sq[i];
            //cout << sq[i] << endl;
        }
        cin >> total;
        slove();
    }
}