//
// Created by beans on 2017/1/17.
//

# include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int require[6], nowhave[6];

int whichsize(string x) {
    if (x == "S")
        return 0;
    if (x == "M")
        return 1;
    if (x == "L")
        return 2;
    if (x == "XL")
        return 3;
    if (x == "XXL")
        return 4;
    if (x == "XXXL")
        return 5;
}

string sizewhich[6] = {"S", "M", "L", "XL", "XXL", "XXXL"};
struct youyu {
    int x, y, pos;

};
bool cmp(const youyu &a,const youyu &b){
    return a.x < b.x;
}

youyu ans[1000000];
int cnt = 0;

int fin = 1;

int aaa[1000000];

void dp(int xxx) {
    sort(ans,ans+cnt,cmp);
    for (int cur = 0; cur < cnt; ++cur) {
        if(fin == 0)
            break;
        //int ok = 0;
        if (require[ans[cur].x] < nowhave[ans[cur].x]) {
            //ok = 1;
            require[ans[cur].x]++;
            aaa[ans[cur].pos] = ans[cur].x;
            //dp(cur + 1);
            //require[ans[cur].x]--;
        }
        else {
            if (require[ans[cur].y] < nowhave[ans[cur].y]) {
                //ok = 1;
                require[ans[cur].y]++;
                aaa[ans[cur].pos] = ans[cur].y;
                //dp(cur + 1);
                //require[ans[cur].y]--;
            } else {
                fin = 0;
            }
        }
    }


}


int main() {

    vector<string> out;
    vector<string> cache;
    ///int nowhave[6];
    for (int i = 0; i < 6; ++i) {
        cin >> nowhave[i];
    }
    //int require[6];
    // memset(require,0, sizeof(require));

    for (int j = 0; j < 6; ++j) {
        require[j] = 0;
    }
    int people;
    cin >> people;
    while (people--) {
        string tmp;
        cin >> tmp;
        if (tmp.find_first_of(",") != string::npos) {
            //string tmp2 = tmp.substr(tmp.find(",")+1);
            //tmp =
            youyu &f = ans[cnt++];
            f.x = whichsize(tmp.substr(0, tmp.find(",")));
            f.y = f.x + 1;
            f.pos = cnt-1;
            out.push_back("fuck");
        } else {
            require[whichsize(tmp)]++;
            out.push_back(tmp);
        }
    }

    int ok = 1;


    for (int j = 0; j < 6; ++j) {
        if (require[j] > nowhave[j])
            ok = 0;
    }
    //ok = dp(0);
    dp(0);

    if (fin && ok) {
        cout << "YES\n";
        int cur = 0;
        for (vector<string>::iterator it = out.begin(); it != out.end(); it++) {
            if (*it == "fuck") {
                cout << sizewhich[aaa[cur++]] << "\n";
            } else
                cout << *it << "\n";
        }
    } else
        cout << "NO\n";


}
