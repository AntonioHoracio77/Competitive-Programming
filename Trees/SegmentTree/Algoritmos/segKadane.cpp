#include <bits/stdc++.h>
#include <stdlib.h>
#define MAXN 1000

using namespace std;

typedef struct{
    int soma,maxPref,maxSuf,MAX;
}node;

node seg[MAXN * 4];

void update(int pos,int ini,int fim,int id,int val){
    if(id < ini || id > fim)
        return;
    if(ini == fim){
        seg[pos].soma = val;
        seg[pos].maxPref = val;
        seg[pos].maxSuf = val;
        seg[pos].MAX = val;
        return;
    }

    int meio = (ini + fim) / 2;
    int esq = 2 * pos + 1, dir = 2 * pos + 2;
    update(esq,ini,meio,id,val);
    update(dir,meio + 1,fim,id,val);

    seg[pos].soma = seg[esq].soma + seg[dir].soma;
    seg[pos].maxPref = max(seg[esq].maxPref,seg[esq].soma + seg[dir].maxPref);
    seg[pos].maxSuf = max(seg[dir].maxSuf,seg[dir].soma + seg[esq].maxSuf);
    seg[pos].MAX = max(seg[esq].maxSuf + seg[dir].maxPref, max(seg[esq].MAX,seg[dir].MAX));
}


node query(int pos, int ini, int fim, int p, int q){
    node ans;
    ans.soma = ans.maxPref = ans.maxSuf = ans.MAX = INT_MIN;

    if(p < ini || fim < q)
        return ans;
    
    if(ini <= p && fim <= q)
        return seg[pos];

    int meio = (ini + fim) / 2,esq = 2 * pos + 1,dir = 2 * pos + 2;
    node e = query(esq,ini, meio,p,q),d = query(dir,meio + 1,fim,p,q);

    ans.soma = e.soma + d.soma;
    ans.maxPref = max(e.maxPref, e.soma + d.maxPref);
    ans.maxSuf = max(d.maxSuf, d.soma + e.maxSuf);
    ans.MAX = max(ans.maxPref, max(ans.maxSuf,max(e.MAX,max(d.MAX,e.maxSuf + d.maxPref))));

    return ans;
}
