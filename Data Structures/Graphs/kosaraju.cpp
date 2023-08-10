#include <bits/stdc++.h>
#define N 100


using namespace std;

vector < int > gr[N],order,grReverse[N],components[N];
int visited[N],col[N];

void dfs(int v){
    visited[v] = 1;
    for(auto to: gr[v]){
        if(!visited[to])
            dfs(to);
    }
    order.push_back(v);
    return;
}

void dfs2(int v,int comp){
    visited[v] = 1;
    col[v] = comp;
    components[comp].push_back(v);
    for(auto to: grReverse[v]){
        if(!visited[to])
            dfs2(to,comp);
    }
}


int kosaraju(){
    for(int i = 1; i <= N; i ++)
        if(!visited[i])
            dfs(i);
    
    reverse(order.begin(),order.end());
    memset(visited,0,sizeof(visited));
    int comp = 0;
    for(auto x: order){
        if(!visited[x])
            dfs2(x,comp ++);
    }

    // total strongly components
    return comp;
}
