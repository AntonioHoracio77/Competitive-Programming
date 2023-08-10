#include <bits/stdc++.h>
#include <math.h>
#define MAXN 5050

using namespace std;

vector < int > gr[MAXN];
bool visited[MAXN],cycle;

void dfs(int v,int par){
    visited[v] = true;
    for(auto to: gr[v]){
        if(!visited[to])
            dfs(to,v);
        else if(to != par && (!cycle)){
            for(auto c: gr[to]){
                if(c == par)
                    cycle = true;
                
            }
        }
    }

}