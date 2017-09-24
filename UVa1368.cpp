//
// Created by beans on 2017/1/8.
//
#include <cstdio>
#include <cstring>
int main(){
    int n;
    scanf("%d",&n);
    char tmp[5] = "ACGT";
    while(n--){
        int r,c,res_value = 0;
        scanf("%d %d",&r,&c);
        char s[r][c+1];
        for (int i = 0; i < r; ++i) {
            scanf("%s",s[i]);
        }
        char ans[c+1];
        for (int j = 0; j <c; ++j) {
            //count the frequency of dna
            int cnt[4];
            std::memset(cnt,0, sizeof(cnt));
            for (int i = 0; i < r; ++i) {
                for (int k = 0; k < 4; ++k) {
                    if (s[i][j]==tmp[k])
                        cnt[k]++;
                }
            }
            int max_value = 0,max_pos = 0;
            for (int l = 0; l < 4; ++l) {
                if(cnt[l]>max_value){
                    max_pos = l;
                    max_value = cnt[l];
                }
            }
            res_value+=(r-max_value);
            printf("%c",tmp[max_pos]);
        }
        printf("\n%d\n",res_value);
    }
}
