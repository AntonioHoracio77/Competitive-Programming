#include <bits/stdc++.h>
#define MAX 100
#define INF 112345678

using namespace std;

int gr[MAX][MAX],n;
int adj[MAX][MAX],d[MAX],pai[MAX];


void add(int u,int v,int c){
    if(adj[u][v] == 0){
        gr[u][d[u] ++] = v;
        gr[v][d[v] ++] = u;
    }
    adj[u][v] += c;
    adj[v][u] += c;
}

int bfs(int og,int dest){
    int u,v,bneck = INF;
    int dist[MAX];
    queue < int > q;
    for(u = 0; u < n; u ++)
        dist[u] = INF;
    q.push(og);
    dist[og] = 0;
    while(!q.empty()){
        u = q.front();
		q.pop();
        if(u == dest)
            break;
        for(int i = 0; i < d[u]; i ++){
            v = gr[u][i];
            if(adj[u][v] > 0 && dist[v] == INF){
                dist[v] = dist[u] + 1;
                pai[v] = u;
                q.push(v);
            }
        }
    }
    if(dist[dest] == INF)
        return 0;
    for(u = dest; u != og; u = pai[u])
        bneck = min(bneck,adj[pai[u]][u]);
    return bneck;
}

int ffek(int og,int dest){
    int f = 0,u,bneck;
    while((bneck = bfs(og,dest))){
        for(u = dest; u != og; u = pai[u]){
            adj[pai[u]][u] -= bneck;
            adj[u][pai[u]] += bneck;
        }
		f += bneck;
    }
    return f;
}




