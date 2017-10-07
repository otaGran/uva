//
// Created by beans on 4/9/2017.
//
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;

int cnt = 0;
int fuck = 0;
int fuck_cnt = 0;
int translate_data[4];
int disk_number, size_of_block, b;
int data[6][6400+10];
char E;

void cal() {
    int tmp = 0;
    for (int i = 0; i < 4; ++i) {
        tmp += pow(2, 3 - i) * translate_data[i];
       // cout << translate_data[i] << " ";
    }
    //cout << endl;
    if (tmp > 9)
        switch (tmp) {
            case 10:
                cout << "A";
                break;
            case 11:
                cout << "B";
                break;
            case 12:
                cout << "C";
                break;
            case 13:
                cout << "D";
                break;
            case 14:
                cout << "E";
                break;
            case 15:
                cout << "F";
                break;
        }
    else
        cout << tmp ;
    //cout << endl;
    memset(translate_data, 0, sizeof(translate_data));
}

void pr() {
    int parity_cnt = 0, translate_cnt = 0;
    for (int j = 0; j < b * disk_number * size_of_block; j++) {
        if ((j / size_of_block) == fuck ) {
            fuck_cnt++;
            if(fuck_cnt%disk_number==0&&fuck_cnt!=0)
                fuck++;
            else
             fuck+=disk_number+1;
               // cout << endl <<fuck << endl;
            //cout << "jump" << j <<endl;
            j += size_of_block - 1;
            //cout << j << endl;
            continue;//jump the parity block
        }
        translate_data[translate_cnt % 4] = data[j / (size_of_block) % (disk_number)][j % size_of_block +
                                                                                    j / (size_of_block * disk_number) *
                                                                                    size_of_block];
        //cout << "hah"<< j << " " << j/(size_of_block)%(disk_number) << " " << j%size_of_block+j/(size_of_block*disk_number)*size_of_block << endl;
        translate_cnt++;
        if (translate_cnt % 4 == 0)
            cal();
    }
    if (translate_cnt % 4 != 0)
        cal();
}

bool fixable(int *how_many_damage_bit, int *check_data, int i, int which_section) {
    bool ok = 0;

    if(how_many_damage_bit[i]==1) {
        ok = 1;
        for (int j = 0; j < disk_number; ++j) {
            if (data[j][which_section * size_of_block + i] == 72){
                if(check_data[i]==(E=='E'?0:1))//both x
                    data[j][which_section * size_of_block + i] = 0;
                else
                    data[j][which_section * size_of_block + i] = 1;
            }
                //data[j][which_section * size_of_block + i] = (check_data[i] != (E == 'E' ? 0 : 1)) ==!check_data[i];
        }
    }


    return ok;
}

int main() {
//    row_number == d
//    each row contains s * b col

    while (cin >> disk_number) {
        memset(translate_data,0,sizeof(translate_data));
        fuck = 0;
        fuck_cnt = 0;
        //cnt = 0;
        if (disk_number == 0)
            return 0;
        cin >> size_of_block >> b >> E;
        for (int i = 0; i < disk_number; ++i) {
            getchar();//for "\n"
            for (int j = 0; j < size_of_block * b; ++j) {
                data[i][j] = getchar() - '0';
                 //cout << data[i][j] << " ";
            }
           // cout << endl;
        }
        int ok = 1;

        for (int i = 0; i < b; ++i) {
            int check_data[size_of_block];
            bool damaged = 0;
            memset(check_data, 0, sizeof(check_data));
            int how_many_damage_bit[size_of_block];
            memset(how_many_damage_bit, 0, sizeof(how_many_damage_bit));
            for (int j = 0; j < disk_number; ++j) {
                for (int k = 0; k < size_of_block; ++k) {
                    if (data[j][i * size_of_block + k] == 72) {
                        how_many_damage_bit[k]++;
                        damaged = 1;
                    } else
                        check_data[k] ^= data[j][i * size_of_block + k];
                }
            }
            for (int k = 0; k < size_of_block; ++k) {
                //cout << check_data[k] << " ";
                if ( how_many_damage_bit[k]||check_data[k] != (E == 'E' ? 0 : 1)) {
                   // cout << "fucked" << endl;
                    if (!fixable(how_many_damage_bit, check_data, k, i)) {
                        ok = 0;
                    }
                }
            }
        }
        if (ok) {
            printf("Disk set %d is valid, contents are: ", ++cnt);
            pr();
            cout << endl;
        } else {
            printf("Disk set %d is invalid.\n", ++cnt);
        }
    }
}
