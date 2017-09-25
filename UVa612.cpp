//greater than four letters to its right
// Created by beans on 2017/9/25.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int ness[1000],ss[10000],vis[1000];
int n,m;
string data[100];


int slove(int n){
   int res = 0;
   for(int i = 0;i<data[n].size();i++){
      for(int j = i+1;j<data[n].size();j++)
          if(data[n][i]>data[n][j])
              res++;
   }
   return res;
}
int main(){
   int M;
   cin >> M;
   while(M--){
      cin >> n >> m;
      for(int i = 0;i<m;i++) {
         cin >> data[i];
          //cout << data[i] << endl;
         ness[i] = ss[i] =  slove(i);
          //cout << ss[i] << endl;
      }
      sort(ness,ness+m);
      memset(vis,0,sizeof(vis));
      for(int i = 0;i<m;i++){
         for(int j = 0;j<m;j++){
            if(ss[j]==ness[i]&&!vis[j]){
               vis[j] = 1;
               cout << data[j] << endl;
            }
         }
      }
       if(M)
           cout << endl;
   }
}