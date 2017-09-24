//
// Created by beans on 2017/1/20.
//HDU-5437
//
#include <cstdio>

#include <queue>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct person{
    char name[200];
    int value;
    int id;

    friend bool operator<(const person& a, const person& b) {
        if(a.value==b.value)
            return a.id>b.id;
        else
            return a.value<b.value;
    }
};

struct fx{
    int t,p;
};

fx fy[150000+10];



bool pmc(const fx& a,const fx& b){
    return a.t<b.t;

}


int res[150000+10];
person a[150000+10];

int main(){
    int fff;
    scanf("%d",&fff);

    while(fff--){

        int res_cnt = 0;
        priority_queue<person> fuck;
        int k,m,q,cnt = 0;
        scanf("%d%d%d",&k,&m,&q);

        for (int i = 0; i < k; ++i) {
            scanf("%s%d",a[i].name,&a[i].value);
            a[i].id = i;
        }
        int pi = 0;
        for (int j = 0; j < m; ++j) {
            scanf("%d%d",&fy[j].t,&fy[j].p);
        }
        sort(fy,fy+m,pmc);

        for (int j = 0; j < m; ++j) {
            for (int f = pi;f<fy[j].t;f++) {
                //printf("pi: %d ",pi);
                fuck.push(a[f]);
                //cout << fuck.top().name << "\n";
            }
            pi = fy[j].t;

            while((fy[j].p--)&&!fuck.empty()){
                res[res_cnt++] = fuck.top().id;
                //memcpy(res[res_cnt++], fuck.top().name, sizeof(fuck.top().name));
                //res[res_cnt++] = fuck.top();
                fuck.pop();
            }

        }
        for (int n = pi; n < k; ++n) {
            fuck.push(a[n]);
        }


        while(!fuck.empty()){
            res[res_cnt++] = fuck.top().id;
            fuck.pop();
        }

        int tmp;
        for (int l = 0; l < (q-1); ++l) {
            scanf("%d",&tmp);
            printf("%s ",a[res[tmp-1]].name);
        }
        scanf("%d",&tmp);
        printf("%s\n",a[res[tmp-1]].name);


    }

}