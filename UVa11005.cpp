//
// Created by beans on 3/20/2017.
//
#include <iostream>
#include <cmath>
#include <algorithm>



using namespace std;

int cost[36],res[37];

void cal(long long query){
    //cout << query << endl;
    for (int i = 2; i < 37; ++i) {
        long long tmp = query,cost_sum = 0;
        while(tmp){
            int tmp_res = tmp % i;
            cost_sum += cost[tmp_res];
            tmp = tmp /i;
            //cout << tmp_res << " " <<  cost[tmp_res] << endl;
        }
        res[i] = cost_sum;
        //c/out << "tmp_cost:" << cost_sum << endl;
    }
}
int main(){
    int time;
    cin >> time;
    for (int i = 0; i < time; ++i) {
        if(i!=0)
            printf("\n");
        printf("Case %d:\n",i+1);
        for (int j = 0; j < 36; ++j) {
           cin >> cost[j];
            //cout << cost[j] << " ";
        }
        int query_time;
        cin >> query_time;
        while(query_time--){
            int query;
            cin >> query;
            cal(query);
            printf("Cheapest base(s) for number %d:",query);
            for (int k = 2; k < 37; ++k) {
                //cout << res[k] << " ";
            }
            int min_res = *min_element(res+2,res+37);
            //cout << "min:"<<min_res << endl;
            for (int j = 2; j < 37; ++j) {
                if(res[j]==min_res)
                    printf(" %d",j);
            }
            printf("\n");
        }

}
}