//
// Created by beans on 2017/1/9.
//
#include <cstdio>
#include <cstring>

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n>0) {
        //printf("%d");
        char computer[100 + 10], ans[100 + 10];
        scanf("%s %s",computer,ans);
        int cache[26], count = 0, left_guess = 0;
        std::memset(cache, 0, sizeof(cache));
        for (int i = 0; i < strlen(computer); ++i) {
            if (!cache[computer[i] - 'a']) {
                left_guess++;
                cache[computer[i] - 'a'] = 1;
            }
        }
        for (int j = 0; j < strlen(ans); ++j) {
            if (cache[ans[j] - 'a']>=0) {
                if(cache[ans[j] - 'a']==1) {
                    left_guess--;
                    cache[ans[j] - 'a'] = -100;
                }
                if(cache[ans[j]-'a']==0){
                    count++;
                }
                cache[ans[j] - 'a']--;
                //continue;
            }
            //printf("%c %d\n",ans[j],count);
            if(!left_guess)
                break;
            if(count==7)
                break;
        }
        printf("Round %d\n",n);
       // printf("wrong:%d  ",count);
        if (count == 7)
            printf("You lose.\n");
        else {

            if (left_guess > 0)
                printf("You chickened out.\n");
            else
                printf("You win.\n");
        }

    }
}