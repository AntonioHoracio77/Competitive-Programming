#include <bits/stdc++.h>
#include <stdlib.h>
#define MAXN 1000


using namespace std;

typedef struct{
    int sum, lzSum;
}node;

node seg[MAXN * 4];

void refresh(int pos,int ini, int fim){
    if(seg[pos].lzSum == 0)
        return;
    
    int num = seg[pos].lzSum;
    seg[pos].lzSum = 0;
    seg[pos].sum += (fim - ini + 1) * num;

    if(ini == fim)
        return;
    
    int e = 2 * pos + 1,d = 2 * pos + 2;
    seg[e].lzSum += num;
    seg[d].lzSum += num;
}
void updateQuery(int pos, int ini, int fim, int p, int q, int val){
    refresh(pos,ini,fim);

    if(q < ini || p > fim)
        return;
    
    if(p <= ini && fim <= q){
        seg[pos].lzSum += val;
        refresh(pos,ini,fim);
        return;
    }

    int m = (ini + fim) / 2;
    int e = 2 * pos + 1, d = 2 * pos + 2;

    updateQuery(e,ini,m,p,q,val);
    updateQuery(d,m + 1,fim,p,q,val);

    seg[pos].sum = seg[e].sum + seg[d].sum;
}

int query(int pos, int ini, int fim, int p, int q){
    refresh(pos,ini,fim);
    if(q < ini || p > fim)
        return 0;
    
    if(p <= ini && fim <= q)
        return seg[pos].sum;
    
    int m = (ini + fim) / 2;
    int e = 2 * pos + 1, d = 2 * pos + 2;
    return query(e,ini,m,p,q) + query(d,m + 1,fim,p,q);
}