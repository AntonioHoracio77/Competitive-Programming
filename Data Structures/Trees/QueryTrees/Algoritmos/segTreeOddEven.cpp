#include <bits/stdc++.h>
#include <stdlib.h>
#define MAXN 1000

using namespace std;


// segment tree para sign alternation, soma alternada n1 - n2 + n3 - n4...

typedef struct{
    int sumIdEven,sumIdOdd;
}node;

node seg[4 * MAXN],nulo;
int v[MAXN];

node merge(node n1,node n2){
    node resp;
    resp.sumIdEven = n1.sumIdEven + n2.sumIdEven;
    resp.sumIdOdd = n1.sumIdOdd + n2.sumIdOdd;
    return resp;
}

void build(int pos,int ini,int fim){
    if(ini == fim){
        seg[pos].sumIdEven = seg[pos].sumIdOdd = 0;
        if(ini % 2 == 0)
            seg[pos].sumIdEven = v[ini];
        else
            seg[pos].sumIdOdd = v[ini];
        return
    }
    int meio = (ini + fim) / 2;
    int esq = 2 * pos + 1, dir = 2 * pos + 2;
    build(esq,ini,meio);
    build(dir,meio + 1,fim);
    seg[pos] = merge(seg[esq],seg[dir]);
}


void update(int pos, int ini, int fim, int id, int val){
    if(id < ini || id > fim)
        return;
    if(ini == fim){
        if(id % 2 == 0)
            seg[pos].sumIdEven = val;
        else
            seg[pos].sumIdOdd = val;
        return;
    }

    int meio = (ini + fim) / 2;
    int esq = 2 * pos + 1, dir = 2 * pos + 2;
    update(esq,ini,meio,id,val);
    update(dir,meio + 1,fim,id,val);
    seg[pos] = merge(seg[esq],seg[dir]);

    
}

node query(int pos, int ini, int fim, int p, int q){
    if(q < ini || p > fim)
        return nulo;
    if(p <= ini && fim <= q)
        return seg[pos];
    int meio = (ini + fim) / 2;
    int esq = 2 * pos + 1,dir = 2 * pos + 2;
    return merge(query(esq,ini,meio,p,q),query(dir,meio + 1,fim,p,q));
}
