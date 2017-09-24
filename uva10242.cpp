//
// Created by beans on 2016/12/22.
//
#include <cstdio>
#include <cmath>
using namespace std;
struct point{
    double x,y;

};
bool operator==(const point& one,const point& two){
    return one.x==two.x&&one.y==two.y;
}
struct line{
    point start,end;
};
void main(){
    //point p1,p2,p3,p4;
    line l1,l2;
    while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&l1.start.x,&l1.start.y,&l1.end.x,&l1.end.y,&l2.start.x,&l2.start.y,&l2.end.x,&l2.end.y)!=EOF) {
       //printf("%lf %lf %lf %lf %lf %lf %lf %lf\n", l1.start.x, l1.start.y, l1.end.x, l1.end.y, l2.start.x, l2.start.y,l2.end.x, l2.end.y);
        double x, y;
        if (l1.end == l2.end) {
            x = l1.start.x+l2.start.x-l1.end.x;
            y = l1.start.y+l2.start.y-l1.end.y;
        } else if (l1.start == l2.start) {
            x = l1.end.x + l2.end.x-l2.start.x;
            y = l1.end.y + l2.end.y-l2.start.y;
        } else if (l1.end == l2.start) {
            x = l1.start.x + l2.end.x-l2.start.x;
            y = l1.start.y + l2.end.y-l2.start.y;
        } else {
            x = l1.end.x + l2.start.x-l2.end.x;
            y = l1.end.y + l2.start.y-l2.end.y;
        }

        printf("%.3lf %.3lf\n", x, y);
    }
}