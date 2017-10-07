//
// Created by beans on 3/13/2017.
//
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
#include <cstring>

using namespace std;

map<string, int> loved;

int main() {
    int time;
    cin >> time;
    string tmp;
    getline(cin, tmp);
    while (time--) {
        getline(cin, tmp);
        stringstream ss(tmp);
        string country;
        ss >> country;
        if (!loved.count(country))
            loved[country] = 0;
        loved[country]++;
        //sort(loved.begin(),loved.end());

    }
    for (map<string, int>::iterator it = loved.begin(); it != loved.end(); it++) {
        cout << it->first << " " << it->second << "\n";

    }

}