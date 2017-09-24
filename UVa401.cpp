//
// Created by beans on 2017/1/6.
//
#include <cstdio>
#include <cstring>
int main(){
    char s[1000];
    char source[] = "AEHIJLMOSTUVWXYZ12358";
    char dest[] = "A3HILJMO2TUVWXY51SEZ8";
    while(gets(s)) {
        printf("%s",s);
        int p = 1, m = 1;
        for (int k = strlen(s)-1; k >=0; --k) {
            int index;
            for (index = 0; source[index] && source[index] != s[k]; ++index);
            //printf("%c %c\n",s[strlen(s)-1-k],dest[index]);
            if(!(source[index]&&s[strlen(s)-k-1]==dest[index]))
                m = 0;
            if(s[k]!=s[strlen(s)-k-1])
                p = 0;
        }
        if(m&&p)
            printf(" -- is a mirrored palindrome.\n");
        else{
            if(m)
                printf(" -- is a mirrored string.\n");
            if(p)
                printf(" -- is a regular palindrome.\n");
            if(!m&&!p)
                printf(" -- is not a palindrome.\n");
        }
        printf("\n");
        //memset(s,, sizeof(s))
    }

}
