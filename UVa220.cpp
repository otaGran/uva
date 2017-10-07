//
// Created by beans on 4/10/2017.
//
#include <iostream>

using namespace std;

char map[8][9];
char now_player;

void Q() {
    for (int i = 0; i < 8; ++i) {
        cout << map[i] << endl;
    }
    //cout << endl;
}

void put(int r, int c) {
    r -= 1;
    c -= 1;
    //cout << "now_player : " << now_player << endl;
    int target_r, target_c;
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (!(dr==dc&&dc==0)) {
                //int find_same = 0, find_ops = 0;
                target_r = r + dr;
                target_c = c + dc;
                if (target_r < 8 && target_r >= 0 && target_c < 8 && target_c >= 0 &&
                    map[target_r][target_c] == (now_player == 'W' ? 'B' : 'W')) {
                    //cout << "found the ops : " << target_r+1 << " " << target_c+1 << endl;
                    while (target_r < 8 && target_r >= 0 && target_c < 8 && target_c >= 0) {
                        target_r += dr;
                        target_c += dc;
                        if(map[target_r][target_c]=='-')
                            break;
                        if (map[target_r][target_c] == now_player) {
                            //cout << "found the same : " << target_r+1 << " " << target_c+1 << endl;
                            target_r -= dr;
                            target_c -= dc;
                            while (target_r < 8 && target_r >= 0 && target_c < 8 && target_c >= 0) {

                               // cout << "back to : " << target_r+1 << " " << target_c+1 << endl;
                                if (map[target_r][target_c] == (now_player == 'B' ? 'W' : 'B')) {
                                    map[target_r][target_c] = now_player;
                                   // cout << "chang : " << target_r+1 << " " << target_c+1 << endl;
                                }
                                if(target_r == r && target_c == c)
                                    break;
                                target_r -= dr;
                                target_c -= dc;
                            }
                            break;
                        }
                    }
                }
            }

        }

    }
}

bool is_putable(int print_or_not, int r, int c) {
    //Q();
    int print_ok = 0, check_ok = 0;
    int target_r, target_c;
    int first = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {

            if (map[i][j] == '-') {//only the unocc area
                //cout << "not_occ : " << i+1 << " " << j+1 << endl;
                //Q();
                int at_least_ok = 0;
                for (int dr = -1; dr <= 1; ++dr) {
                    for (int dc = -1; dc <= 1; ++dc) {
                        if (!(dr==dc&&dc==0) && !at_least_ok) {
                           // printf("dir : (%d,%d)\n",dr,dc);
                            int find_same = 0;
                            target_r = i + dr;
                            target_c = j + dc;
                            if (target_r < 8 && target_r >= 0 && target_c < 8 && target_c >= 0 &&
                                map[target_r][target_c] == (now_player == 'W' ? 'B' : 'W')) {
                                //cout << "found the ops : " << target_r+1 << " " << target_c+1 << endl;
                                target_r += dr;
                                target_c += dc;
                                while (target_r < 8 && target_r >= 0 && target_c < 8 && target_c >= 0) {
                                    //cout << "searching : " << target_r+1 << " " << target_c+1 << endl;
                                    if (map[target_r][target_c] == now_player) {
                                        find_same = 1;
                                       // cout << "found the same : " << target_r+1 << " " << target_c+1 << endl;
                                        break;
                                    }
                                    if(map[target_r][target_c]=='-')
                                        break;
                                    target_r += dr;
                                    target_c += dc;
                                }
                            }
                            if (find_same) {
                                at_least_ok = 1;
                                if (print_or_not) {
                                    //printf("dir : (%d,%d)-->",dr,dc);
                                    if(!first) {

                                        first = 1;
                                    }
                                    else{
                                        printf(" ");
                                    }
                                    printf("(%d,%d)", i+1, j+1);
                                    print_ok = 1;
                                } else if (i == r-1 && j == c-1) {
                                    check_ok = 1;
                                    map[i][j] = now_player;
                                }
                                break;//just one is ok
                            }
                        }

                    }

                }
            }
        }
    }
    if (print_or_not)
        return print_ok;
    else
        return check_ok;
}

void pr_number() {
    int B = 0, W = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (map[i][j] == 'B')
                B++;
            if (map[i][j] == 'W')
                W++;
        }
    }
    printf("Black - %2d White - %2d\n", B, W);
}



void L() {

    if (!is_putable(1, 0, 0)) {
        cout << "No legal move.";
        //is_putable(1,(now_player=='W'?'B':'W'),0,0);
    }
    cout << endl;


}

void M(int r, int c) {
    //cout << r << " " << c << endl;
    if (!is_putable(0, r, c)) {
        now_player = (now_player == 'W' ? 'B' : 'W');
        is_putable(0, r, c);
    }

    put(r, c);
    //Q();
    pr_number();
    now_player = (now_player == 'W' ? 'B' : 'W');

}

int main() {
    int N;
    cin >> N;
    while (N--) {
        for (int i = 0; i < 8; ++i) {
            cin >> map[i];
            //cout << map[i] << endl;
        }
        cin >> now_player;
        //cout << "now_player : " << now_player << endl;
        char command[3];

        while (cin >> command[0]) {
            if (command[0] == 'L')
                L();
            if (command[0] == 'M') {
                cin >> command[1] >> command[2];
                //cout << command[1] - '0' << " " << command[2] - '0' << endl;
                M(command[1] - '0', command[2] - '0');
            }
            if (command[0] == 'Q')
                break;
        }
        Q();
        if(N!=0)
            cout << endl;
    }
}
