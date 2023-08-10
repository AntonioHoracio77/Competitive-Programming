#include <bits/stdc++.h>
#define N 100


using namespace std;


vector < int > gr[N],order;
bool visited[N];

void dfs(int v){
    visited[v] = true;
    for(auto to: gr[v]){
        if(!visited[to])
            dfs(to);
    }
    order.push_back(v);
    return;
}

void topologicalSort(){
    for(int i = 1; i < N; i ++)
        if(!visited[i])
            dfs(i);
    
    reverse(order.begin(),order.end());
}
