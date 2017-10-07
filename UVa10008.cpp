//
// Created by beans on 3/13/2017.
//
#include <map>
#include <utility>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<char, int> PAIR;


int cmp(const PAIR &lhs, const PAIR &rhs) {
    return lhs.second > rhs.second;
}

map<char, int> dict;


int main() {
    int time;
    cin >> time;
    string tmp;
    getline(cin, tmp);
    while (time--) {
        getline(cin, tmp);
        for (int i = 0; i < tmp.length(); ++i) {
            if (isalpha(tmp[i])) {
                if (tmp[i] > 96)
                    tmp[i] -= 32;
                if (!dict.count(tmp[i]))
                    dict[tmp[i]] = 0;
                dict[tmp[i]]++;
            }
        }

    }
    vector<PAIR> res(dict.begin(), dict.end());
    sort(res.begin(), res.end(), cmp);
    for (vector<PAIR>::iterator it = res.begin(); it != res.end(); it++) {
        cout << it->first << " " << it->second << "\n";
    }


}