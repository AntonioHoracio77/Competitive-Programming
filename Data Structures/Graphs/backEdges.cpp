#include <bits/stdc++.h>
#define MAXN 100

using namespace std;

vector < int > gr[MAXN];
bool visited[MAXN],cycle;

void dfs(int v,int par){
    visited[v] = true;
    for(auto to: gr[v]){
        if(!visited[to]){
            dfs(to,v);
        }
        else if(to != par){
            cycle = true;
        }
    }
}