//
// Created by beans on 2016/12/8.
//

#include <cstdio>
int res[15];
bool check(int i){
    int res[4];
    res[0] = i/1000;
     res[1] = (i-1000*res[0])/100;
     res[2] = (i-1000*res[0]-100*res[1])/10;
     res[3] = (i-1000*res[0]-100*res[1]-10*res[2]);
    for (int j = 0; j < 4; ++j) {
        //printf("%d",res[j]);
        for (int k = 0; k <4 ; ++k) {
            if(j==k)
                continue;
            if(res[j]==res[k])
                return false;
        }
    }
    return true;

}
void main(){
    unsigned  int year;
    scanf("%d",&year);
    //unsigned int x = 2;
    //x = 1<<x;
    //printf("%d",1<<3);
    for(int i = year+1;;i++){
        if(check(i)){
            printf("%d\n",i);
            break;
        }

    }
    return 0;
}
//00000011111011110
//00000011111011101
//00000011111000011