//
// Created by beans on 3/23/2017.
//
#include <iostream>

using namespace std;

int main(){
    struct point{
        double x,y;
    };
    struct line{
        point a,b;
    };
    line tmp[2];
    point pt[4];
    while(cin){
        for (int i = 0; i < 4; ++i) {
            cin >> pt[i].x >> pt[i].y;
        }
        for (int j = 0; j < 3; ++j) {
            for (int i = j+1; i < 4; ++i) {
                if(pt[i].x==pt[j].x&&pt[i].y==pt[j].y){

                }
            }
        }
    }
}
