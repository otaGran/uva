//
// Created by beans on 2017/1/7.
//
#include <cstdio>
#include <cstring>
#include <ctype.h>
bool check(int des_r,int des_c){
    if(des_r<5&&des_r>=0&&des_c<5&&des_c>=0)
        return true;
    else
        return false;
}
void swap(char s[5][6],int r,int c,int des_r,int des_c){
    char tmp = s[des_r][des_c];
    s[des_r][des_c] = s[r][c];
    s[r][c] = tmp;

    for(int i = 0;i<5;i++) {
        //printf("%s\n", s[i]);
    }
    //printf("\n");

}
int main(){
    int time = 0;
    while(true) {
        int r,c;
        char s[5][6],command[100];
        int count  = 0;
        while(count!=25){
            char tmp = getchar();
            if(tmp=='Z')
                return 0;
            if(!isalpha(tmp)&&tmp!=' ')
                continue;
            if(tmp==' '){
                r = count/5;
                c = count%5;
            }
            s[count/5][count%5] = tmp;
            //printf("%d %d\n",count/5,count%5);
            count++;
        }
        int ok = 1;
        while(true){
            char tmp = getchar();
            //printf("%c\n\n",tmp);  //print the comand
            if(tmp=='0')
                break;
            if(!isalpha(tmp))
                continue;
            int des_r,des_c;
            switch(tmp) {
                //to move an element
                    //1.the target place cor must be legal
                    //2.
                case 'A':
                    des_r = r-1;
                    des_c = c;
                    if(!check(des_r,des_c))
                        ok = 0;
                    else {
                        swap(s, r, c, des_r, des_c);
                        r = des_r;
                        c = des_c;
                    }

                    break;
                case 'B':
                    des_r = r+1;
                    des_c = c;
                    if(!check(des_r,des_c))
                        ok = 0;
                    else {
                        swap(s, r, c, des_r, des_c);
                        r = des_r;
                        c = des_c;
                    }
                    break;
                case 'L':
                    des_r = r;
                    des_c = c-1;
                    if(!check(des_r,des_c))
                        ok = 0;
                    else {
                        swap(s, r, c, des_r, des_c);
                        r = des_r;
                        c = des_c;
                    }

                    break;
                case 'R':
                    des_r = r;
                    des_c = c+1;
                    if(!check(des_r,des_c))
                        ok = 0;
                    else {
                        swap(s, r, c, des_r, des_c);
                        r = des_r;
                        c = des_c;
                    }
                    break;
                default:
                    ok = 0;

            }

        }
        if(time!=0)
            printf("\n");

        printf("Puzzle #%d:\n",++time);
        if(ok){
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    printf("%c",s[i][j]);
                    if(j!=4)
                        printf(" ");
                }

                 printf("\n");
            }
        }
        else{
            printf("This puzzle has no final configuration.\n");
        }
        //printf("\n");

    }
    //printf("%d %d\n",r,c);
}
