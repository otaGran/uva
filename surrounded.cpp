//
// Created by beans on 2016/12/9.
//

#include <cmath>
#include <cstdio>

double a_x, a_y, b_x, b_y, a_dis, b_dis;

double cal() {
    //printf("%f %f %f\n", a_x, a_y, a_dis);
    //printf("%f %f %f\n",b_x,b_y,b_dis);
    double hor = a_x - b_x;
    double ver = a_y - b_y;
    double dis = sqrt(hor * hor + ver * ver);
    if(dis>a_dis+b_dis)
        return (dis-a_dis-b_dis)/2.0;
    if(dis<a_dis+b_dis&&dis>fabs(a_dis-b_dis))
        return 0.0;
    if(dis>0.0&&dis<fabs(a_dis-b_dis))
        return (fabs(a_dis-b_dis)-d is)/2.0;


}

void main() {
    //double x = 2.0;
    //x = sqrt(x);
    //printf("%.15f\n", x);
    //long long x = 2.5;
    //printf("%.15lf",x);
    scanf("%lf %lf %lf", &a_x, &a_y, &a_dis);
    scanf("%lf %lf %lf", &b_x, &b_y, &b_dis);
    double res = cal();
    printf("%.15lf\n", fabs(res));
    return 0;
}