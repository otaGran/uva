#include <cstdio>
#include <queue>
#include <stack>

//
// Created by beans on 2016/12/8.
//
int t,a,b;
void main(){
    while(scanf("%d",&t)!=EOF) {
        std::queue<int> q;
        std::priority_queue<int> pq;
        std::stack<int> st;
        int res = 7;
        while (t--) {
            scanf("%d %d", &a, &b);
            if (a == 1) {
                st.push(b);
                q.push(b);
                pq.push(b);
            } else {
                if (!st.empty()) {
                    if (st.top() != b)
                        res &= 3;
                    if (pq.top() != b)
                        res &= 5;
                    if (q.front() != b)
                        res &= 6;
                    st.pop();
                    q.pop();
                    pq.pop();
                }
                else{
                    res = 0;
                }
            }
        }
        switch (res) {
            case 1:
                printf("queue\n");
                break;
            case 2:
                printf("priority queue\n");
                break;
            case 4:
                printf("stack\n");
                break;
            case 0:
                printf("impossible\n");
                break;
            default:
                printf("not sure\n");
        }
        //printf("%d\n", res);
    }
}
