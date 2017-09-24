//
// Created by beans on 3/1/17.
//

#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct person
{
    char name[200];
    int value;
    int id;
    friend bool operator<(const person& a,const person& b){
        if(a.value == b.value)
            return a.id>b.id;
        else
            return a.value < b.value;
    }
};

struct opendoor
{
    int t,p;

};


bool pmc(const opendoor& a,const opendoor& b){
    return a.t<b.t;

}


opendoor timetime[150000+10];
person people[150000+10];


int res[150000+10];


int main()
{
    /* code */
    int T,k,m,q;
    // k is the bumber of friends
    //the door will open m times before all friends arrive
    //q is the query
    //cin >> T;
    scanf("%d",&T);
    while(T--){
        //printf("%d \n",T );
        priority_queue<person> waiting;
        //cin >> k >> m >> q;
        scanf("%d%d%d",&k,&m,&q);
        for (int i = 0; i < k; ++i)
        {
           // cin >> people[i].name >> people[i].value;
            scanf("%s%d",people[i].name,&people[i].value);
            people[i].id = i;
            //printf("%s %d\n",people[i].name,people[i].id);
        }

        for (int i = 0; i < m; ++i)
        {
            //cin >> timetime[i].t >> timetime[i].p;
            scanf("%d%d",&timetime[i].t,&timetime[i].p);
        }

        sort(timetime,timetime+m,pmc);
        //process the data
        int now = 0,res_point = 0;

        for (int j = 0; j < m; ++j) {
            //printf("t = %d p = %d\n",timetime[j].t,timetime[j].p);
            for (int f = now;f < timetime[j].t; f++) {
                waiting.push(people[f]);
                //printf("%s %d\n",people[now].name,people[now].id);
            }
            now = timetime[j].t;
            //printf("%d\n",waiting.size());
            for (int i = 0; i < timetime[j].p; ++i) {
                if(waiting.empty())
                    break;
                else {
                    //printf("top:%s\n",waiting.top().name);
                    res[res_point++] = waiting.top().id;
                    waiting.pop();
                }
            }

        }
        for (int n = now; n < k; ++n) {
            waiting.push(people[n]);
        }
        while(!waiting.empty()){
            res[res_point++] = waiting.top().id;
            waiting.pop();
        }



        for (int i = 0; i < (q-1); ++i)
        {
            int query_tmp;
            scanf("%d",&query_tmp);
            printf("%s ",people[res[query_tmp-1]].name);
        }
        int query_tmp;
        scanf("%d",&query_tmp);
        printf("%s\n",people[res[query_tmp-1]].name);



    }
    return 0;
}