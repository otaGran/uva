//
// Created by beans on 4/8/2017.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const double EPS = 1e-5;
struct student {
    //long long CID;

    int score[4];
    string SID, name, CID;
    int rank = 0;
    int fail_cl = 0;
    double ave = 0;
    int total = 0;
    //int id;
};

vector<student> st;
vector<int> r;
//int cnt = 0;

int cc = 0;
void addd() {

    while (1) {
        student tmp;
        cout << "Please enter the SID, CID, name and four scores. Enter 0 to finish.\n";
        cin >> tmp.SID;
        if (tmp.SID.length() == 1 && tmp.SID[0] == '0')
            return;
        cin >> tmp.CID >> tmp.name >> tmp.score[0] >> tmp.score[1] >> tmp.score[2] >> tmp.score[3];
        int ok = 1;
        for (int i = 0; i < 4; ++i) {
            if (tmp.score[i] < 60)
                tmp.fail_cl++;
            tmp.total += tmp.score[i];
        }
        tmp.ave =  (double)tmp.total / 4.0;
        for (vector<student>::iterator it = st.begin(); it != st.end(); it++) {
            if (it->SID == tmp.SID) {
                ok = 0;
            }
        }
        if (ok) {
            //tmp.id = ++cc;
            st.push_back(tmp);
        }
        else
            cout << "Duplicated SID.\n";
    }

}

void rm() {
    while (1) {
        cout << "Please enter SID or name. Enter 0 to finish.\n";
        string tmp;
        cin >> tmp;
        if (tmp.length() == 1 && tmp[0] == '0')
            return;
        int cnt = 0;
        for (vector<student>::iterator it = st.begin(); it != st.end();) {
            if (it->SID == tmp || it->name == tmp) {
                st.erase(it);
                cnt++;
            }
            else{
                it++;
            }
        }
        printf("%d student(s) removed.\n", cnt);

    }
}

void qu() {
    while (1) {
        // int cnt = 0;
        cout << "Please enter SID or name. Enter 0 to finish.\n";
        string tmp;
        cin >> tmp;
        if (tmp.length() == 1 && tmp[0] == '0')
            return;
        //int cnt = 0;
        for (vector<student>::iterator it = st.begin(); it != st.end(); it++) {
            int rank = 0;
            if (it->SID == tmp || it->name == tmp) {
                for (vector<student>::iterator ib = st.begin(); ib != st.end(); ib++) {
                    if (ib->total > it->total) {
                        rank++;
                        it->rank++;//多次查询同一student时 rank结果累加
                    }
                }
                printf("%d %s %s %s %d %d %d %d %d %.2lf\n",it->rank+1, it->SID.c_str(), it->CID.c_str(), it->name.c_str(),
                       it->score[0],it->score[1], it->score[2],
                       it->score[3], it->total,
                       it->ave+EPS);
            }
        }
        //printf("%d student(s) removed.\n", cnt);
    }
}

void stat() {
    cout << "Please enter class ID, 0 for the whole statistics.\n";
    string n;
    cin >> n;

    string cl[4] = {"Chinese", "Mathematics", "English", "Programming"};
    for (int i = 0; i < 4; ++i) {
        int cnt = 0;
        int total_score = 0, fail = 0;
        //if(n==0||n==i)

        cout << cl[i] << endl;
        for (vector<student>::iterator it = st.begin(); it != st.end(); it++) {
            if(n[0]=='0'||it->CID==n) {
                total_score += it->score[i];
                cnt++;
            }
            if (it->score[i] < 60&&(n[0]=='0'||it->CID==n)) {
                fail++;
                //cnt++;
            }
        }
        printf("Average Score: %.2lf\nNumber of passed students: %d\nNumber of failed students: %d\n\n",
               cnt==0?0+EPS:(double)total_score/(double)cnt+EPS, cnt - fail, fail);
    }
    cout << "Overall:";
    int all = 0, xxx = 0, xx = 0, x = 0, zero = 0;
    for (vector<student>::iterator it = st.begin(); it != st.end(); it++) {
        if(n[0]=='0'||it->CID==n) {
            switch (it->fail_cl) {
                case 0:
                    all++;
                case 1:
                    xxx++;
                case 2:
                    xx++;
                case 3:
                    x++;
                    break;
                case 4:
                    zero++;
            }
        }
    }
    printf("\nNumber of students who passed all subjects: %d\nNumber of students who passed 3 or more subjects: %d\nNumber of students who passed 2 or more subjects: %d\nNumber of students who passed 1 or more subjects: %d\nNumber of students who failed all subjects: %d\n\n",
           all, xxx, xx, x, zero);
    return;


}

int main() {
    int command;
    while (1) {
        printf("Welcome to Student Performance Management System (SPMS).\n\n1 - Add\n2 - Remove\n3 - Query\n4 - Show ranking\n5 - Show Statistics\n0 - Exit\n\n");
        cin >> command;
        switch (command) {
            case 1:
                addd();
                break;
            case 2:
                rm();
                break;
            case 3:
                qu();
                break;
            case 4:
                cout << "Showing the ranklist hurts students' self-esteem. Don't do that.\n";
                break;
            case 5:
                stat();
                break;
            case 0:
                return 0;
        }
    }
}