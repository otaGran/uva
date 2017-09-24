//
// Created by beans on 2016/12/8.
//

#include <cstdio>
#include <cstring>

char res[100+1];
void main(){
    gets(res);
    int len = strlen(res);
    for (int i = 0; i < len; ++i) {
        char tmp =res[i];
        if(tmp<'a')
            tmp += 32;
        if(tmp=='a'||tmp=='o'||tmp=='y'||tmp=='e'||tmp=='u'||tmp=='i')
            continue;
        printf(".%c",tmp);
    }
}