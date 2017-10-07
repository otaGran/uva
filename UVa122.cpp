//
// Created by beans on 5/21/2017.
//
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 1000;
const int root = 1;
bool failed = false;
int l[1000],r[1000],v[1000];
int cnt;
bool have_value[1000];
/*
struct Node{
    bool have_value;
    int v;
    Node *l,*r;
    Node():have_value(false),l(NULL),r(NULL){}
};
 */

//Node *root;
//Node* newnode(){return new Node();}

void newtree(){
    
    l[root] = r[root] = 0;
    have_value[root] = false;
    cnt = root;
}
int newnode(){
    int u = ++cnt;
    l[u] = r[u] = 0;
    have_value[u] = false;
    return u;
}

void addnode(int the_v,char* s){
    int n = strlen(s);
    //Node* u = root;
    int u = root;
    for(int i = 0;i<n;i++){
        if(s[i]=='L'){
            if(l[u] == 0)
                l[u] = newnode();
            u = l[u];
        }else if(s[i]=='R'){
            if(r[u] == 0)
                r[u] = newnode();
            u = r[u];
        }

    }

    if(have_value[u])
        failed = true;
    v[u] = the_v;
    have_value[u] = true;
    //cout << u << endl;
   // cout << have_value[u] << endl;
}

bool bfs(vector<int>& ans){
    queue<int> q;
    ans.clear();
    q.push(root);
    while(!q.empty()){
        //Node* u = q.front();
        int u = q.front();
        q.pop();
        if(!have_value[u]) {
            //cout << "u: " << u << endl;
            return false;
        }
        ans.push_back(v[u]);
        if(l[u] !=0)
            q.push(l[u]);
        if(r[u] != 0)
            q.push(r[u]);

    }
    return true;
}

char s[maxn];
/*
void remove_tree(Node* u){
    if(u == NULL)
        return;
    remove_tree(l[u]);
    remove_tree(r[u]);
    delete(u);

}
*/
bool read_input(){
    failed = false;
    //remove_tree(root);
   // root = newnode();
    newtree();
    for(;;) {
        if (scanf("%s", s) != 1)
            return false;
        //cout << s <<endl;
        if (!strcmp(s, "()"))
            break;
        int v;
        sscanf(&s[1], "%d", &v);
        addnode(v, strchr(s, ',') + 1);
    }
    return  true;
}
int main(){
    vector<int> ans;
    //read_input();
    while(read_input()) {
       // cout << "hhe" << endl;
        //ans.clear();
       // cout << failed << endl;
        if (bfs(ans)&&!failed) {
            cout << *ans.begin();
            for (vector<int>::iterator i = ans.begin()+1; i != ans.end(); i++)
                cout <<" " << *i;
            cout << endl;
        } else {
            cout << "not complete" << endl;
        }
    }


}