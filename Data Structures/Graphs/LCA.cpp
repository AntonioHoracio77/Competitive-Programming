#include <bits/stdc++.h>
#define N 100
#define M 20


using namespace std;


vector < int > gr[N];
int dep[N],Par[N][M];


void dfs(int v,int par){
    dep[v] = dep[par] + 1;
    Par[v][0] = par;

    for(int j = 1; j < M; j ++){
        Par[v][j] = Par[Par[v][j - 1]][j - 1];
    }

    for(auto to: gr[v]){
        if(to != par)
            dfs(to,v);
    }
}

int LCA(int u,int v){
    if(u == v)
        return u;
    if(dep[u] < dep[v])
        swap(u,v);
    
    int diff = dep[u] - dep[v];

    for(int j = M - 1; j >= 0; j --){
        if((diff >> j) & 1){
            //j-ith bit is set
            u = Par[u][j];
        }
    }
    // u and v are on the same level
    for(int j = M - 1; j >= 0; j --){
        if(Par[u][j] != Par[v][j]){
            u = Par[u][j];
            v = Par[v][j];
        }
    }

    return Par[u][0];

}