//
// Created by beans on 2017/1/11.
//
//对全部x求平均 set<point>存坐标 对于每个坐标 求是否有对成坐标

//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct point {
    int x;
    int y;
};
point p[1000 + 1];

bool cmp(point a, point b) {//若y相同，依照x由小到大排序，否則依照y由小到大排序
    if (a.y == b.y) return a.x < b.x;
    else return a.y < b.y;
}

double cal(int start, int end) {
    //printf("cor :: %d %d\n", start, end);
    double tmp = 0;
    for (int i = start; i <= end; ++i) {
        tmp += (double)p[i].x;
    }

    tmp = tmp / (end - start+1);
    //printf("tmp:: %lf\n",tmp);
    return tmp;

}

int main() {
    int n;
    cin >> n;
    while (n--) {
        vector<double> cache;
        bool flag = true;
        double res = 0;
        bool first = true;
        int howmany;
        cin >> howmany;
        for (int i = 0; i < howmany; ++i) {
            int xx, yy;
            cin >> xx >> yy;
            p[i].x = xx;
            p[i].y = yy;
        }
        sort(p, p + howmany, cmp);

        /*
        for (int k = 0; k < howmany; ++k) {
            printf("%d %d\n",p[k].x,p[k].y);
        }
         */
        int check = p[0].y;
        int pos = 0;
        for (int j = 0; j < howmany; ++j) {
            if (p[j].y != check) {
                check = p[j].y;
                double tmp = cal(pos, j - 1);
                pos = j;
                //cout << tmp << '\n';
                cache.push_back(tmp);
            }
        }
        //check = p[howmany].y;
        double tmp = cal(pos, howmany-1);
       // cout << tmp << '\n';
        cache.push_back(tmp);

        double fuck = cache[0];
        for (int l = 0; l < cache.size(); ++l) {
            if(cache[l]!=fuck)
                flag  = false;
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }


}
