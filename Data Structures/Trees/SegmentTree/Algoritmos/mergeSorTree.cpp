#include <bits/stdc++.h>
#include <algorithm>
#define MAXN 300005
 
using namespace std;

vector < int > tree[MAXN * 4];
int arr[MAXN];

void build(int pos,int ini,int fim){
    if(ini == fim){
        tree[pos].push_back(arr[ini]);
        return;
    }
    int m = (ini + fim) / 2, e = 2 * pos + 1,d = 2 * pos + 2;
    build(e,ini,m);
    build(d,m + 1,fim);

    merge(tree[e].begin(),tree[e].end(),tree[d].begin(),tree[d].end(),back_inserter(tree[pos]));

    
}

// valores maiores ou iguais a um numero v
int query(int pos, int ini, int fim, int p, int q, int v){
    if(q < ini || p > fim)
        return 0;
    if(p <= ini && fim <= q){
        int ans = tree[pos].end() - lower_bound(tree[pos].begin(),tree[pos].end(), v );
        return ans;
    }
    int m = (ini + fim) / 2;
    int e = 2 * pos  + 1,d = 2 * pos + 2;
    return query(e,ini,m,p,q,v) + query(d,m + 1,fim,p,q,v);
}

