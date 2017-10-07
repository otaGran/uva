//
// Created by beans on 3/13/2017.
//

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    string a,b;
    while(cin >> a >> b){
        if(a[0]==b[0]&&a[0]=='0')
            return 0;
        while(a.length()!=b.length()){
            if(a.length()<b.length())
                a.insert(0,"0");
            else
                b.insert(0,"0");
        }
        a.insert(0,"0");
        b.insert(0,"0");
        int cnt = 0;

        //printf("%s\n",b.c_str());
        for (int i = a.length()-1; i >= 0; i--) {
            //printf("sssssssssss%d\n ",a[i]+b[i]-96);
            if(a[i]+b[i]-96>=10){
                cnt++;
                a[i-1]++;
                //printf("%s\n",a.c_str());
            }
        }

        if(cnt==0)
            printf("No");
        else
            printf("%d",cnt);
        if(cnt>1)
            printf(" carry operations.\n");
        else
            printf(" carry operation.\n");

    }
}