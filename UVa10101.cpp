//
// Created by beans on 3/13/2017.
//
#include <iostream>
#include <cstring>

using namespace std;

string tmp;

void Bangla(int start, int end) {


    for (int j = start; j < end; ++j) {
        if (tmp[j] == '0')
            start++;
        else
            break;
    }
    int between = end - start;
    if (start == end)
        return;

    if (between >= 8) {
        Bangla(start, end - 7);
        cout << " kuti";
        Bangla(end - 7, end);
    } else {
        if (between >= 6) {
            Bangla(start, end - 5);
            cout << " lakh";
            //printf("\nstart:%d end:%d\n",start,end);
            Bangla(end - 5, end);
        } else {
            if (between >= 4) {
                Bangla(start, end - 3);
                cout << " hajar";
                Bangla(end - 3, end);
            } else {
                if (between >= 3) {
                    Bangla(start, end - 2);
                    cout << " shata";
                    Bangla(end - 2, end);
                } else {
                    cout << " ";
                    for (int i = start; i < end; ++i) {
                        printf("%c", tmp[i]);
                    }
                }

            }
        }
    }
}

int main() {
    int cnt = 1;
    while (cin >> tmp) {
        bool ch = false;
        //erase the precursor zero

        printf("%4d.", cnt++);
        if (tmp.length() == 1 && tmp[0] == '0')
            cout << " 0";
        else
            Bangla(0, tmp.length());
        printf("\n");

    }
}
