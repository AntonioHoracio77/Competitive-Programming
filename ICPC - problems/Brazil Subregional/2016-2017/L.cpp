#include <bits/stdc++.h>
#define MAX 210
 
using namespace std;
int n,l,minV;
int tab[MAX][MAX],dx[4] = {1,-1,0,0},dy[4] = {0,0,1,-1};

bool inGrid(int i,int j,int op){
   if(i < 0 || i >= n  || j < 0 || j >= l)
      return 0;
   return tab[i][j] == op;
}

void dfs(int i,int j,int op){
   tab[i][j] = -1;

   for(int k = 0; k < 4; k ++){
      if(inGrid(i + dx[k],j + dy[k],op)){
         dfs(i + dx[k], j + dy[k],op);
         minV ++;
      }
        

   }

   
}

int main() {
   int MIN = INT_MAX;
    cin >> n >> l;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < l; j ++){
            cin >> tab[i][j];
        }
    }
    
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < l; j ++){
           if(tab[i][j] != -1){
               minV = 1;
               dfs(i,j,tab[i][j]);
               MIN = min(MIN,minV);
           }
        }
    }
    cout << MIN << "\n";
 
    return 0;
}