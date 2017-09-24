//
// Created by beans on 2017/1/17.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

//#include <vector>
using namespace std;
struct node{
    int start,end,length;
};
/*
bool cmp(const node &a,const node &b){
    if(a.start==b.start){
        return a.end < b.end;
    }
    else
        return a.start < b.start;
}
 */
bool cmp(const node &a,const node &b){
    if(a.end==b.end)
        return a.start<b.start;
    else
        return a.end<b.end;
}
int n,minlength = 10000+10,maxend = 1;
node cache[1000];
bool fuck(int target){
    int vis[1000];
    for (int i = 0; i < 1000; ++i) {
        vis[i] = 0;
    }
    for (int k = 0; k < n; ++k) {
        for (int l = cache[k].start; l < cache[k].end; ++l) {
            if(vis[l]<target){
                vis[target]
            }
        }
    }





    /*
    //printf("length : %d\n",j);
    //priority_queue<pair<int,int>> tmp;
    int eachtime[n];
    //init eachtime
    for (int k = 0; k < n; ++k) {
        eachtime[k] = 0;
    }
    //start to end
    int tmplength = 0;

    for (int i = 1; i < maxend; ++i) {
        int pos = -1;
        //printf("%dth seconed\n",i);
        for (int k = 0; k < n; ++k) {
            if(i>=cache[k].start&&i<cache[k].end&&eachtime[k]!=j){
                // printf("\t %d : ok for check\n",k );
                if((cache[k].length-(i-cache[k].start))>tmplength)
                    pos = k;
            }
        }
        if(pos!=-1) {
            //printf("\t\tchoose : %d\n", pos);
            eachtime[pos]++;
        }
    }

    int ok = 1;
    for (int l = 0; l < n ; ++l) {
        if(eachtime[l]!=j)
            ok = 0;
    }
    if(ok){
        return true;
    } else
        return false;
     */


}

//priority_queue<node> cache;



int main(){

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> cache[i].start >> cache[i].end;
        cache[i].length = cache[i].end - cache[i].start;
        if(cache[i].end>maxend)
            maxend = cache[i].end;
        if(cache[i].length<minlength)
            minlength = cache[i].length;
    }
    sort(cache,cache+n,cmp);

    for (int m = 0; m < n; ++m) {
        //printf("%dth : %d %d\n",m,cache[m].start,cache[m].end);
    }


    //int res = 1;
    int ans = 0;
    int low = 1,high = minlength+1,mid;
    while(low<=high){
        mid=(low+high)>>1;
        if(fuck(mid)){
            ans=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    cout<<ans*n<<endl;



    //cout << "0\n";


}