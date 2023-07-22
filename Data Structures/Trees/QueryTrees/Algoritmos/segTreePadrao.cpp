#include <bits/stdc++.h>
#include <stdlib.h>
#define MAXN 1000

using namespace std;

int seg[4 * MAXN];

// segment tree para range minimun query
// complexidade aproximada O(logN)
void update(int pos,int ini,int fim,int id,int val){
    if(id < ini || id > fim)
        return;
    if(ini == fim){
        seg[pos] = val;
        return;
    }
    int meio = (ini + fim) / 2;
    int esq = 2 * pos + 1, dir = 2 * pos + 2;

    update(esq,ini,meio,id,val);
    update(dir,meio + 1,fim,id,val);
    // para soma em intervalo seg[pos] = seg[esq] + seg[dir];
    seg[pos] = min(seg[esq],seg[dir]);
}

// complexidade aproximada O(logN)
int query(int pos,int ini,int fim,int p,int q){
    if(q < ini || p > fim)
        return INT_MAX;
    if(p <= ini && fim <= q)
        return seg[pos];
    
    int meio = (ini + fim) / 2;
    int esq = 2 * pos + 1,dir = 2 * pos + 2;
    // para soma em intervalo return query(esq,ini,meio,p,q) + query(dir,meio + 1,fim,p,q);
    return min(query(esq,ini,meio,p,q),query(dir,meio + 1,fim,p,q));
}


