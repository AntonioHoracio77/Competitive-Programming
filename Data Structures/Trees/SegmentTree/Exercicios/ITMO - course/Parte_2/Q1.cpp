/*https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A*/

#include <bits/stdc++.h>
#include <stdlib.h>
#define MAXN 100100

using namespace std;

typedef struct{
    long long soma,maxPref,maxSuf,MAX;
}node;

node seg[MAXN * 4];

void update(int pos,int ini,int fim,int id,long val){
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



int main(){
    int n,q,idx;
    node ans;
        cin >> n >> q;
        long arr[n],v;
        for(int i = 0; i < n; i ++){
            cin >> arr[i];
            update(0,0,n - 1,i,arr[i]);
        }
        ans = query(0,0,n - 1,0,n - 1);
        if(ans.MAX <= 0)
            cout << "0\n";
        else
            cout << ans.MAX << "\n";
        while(q --){
            cin >> idx >> v;
            update(0,0,n - 1,idx,v);
            ans = query(0,0,n - 1,0, n - 1);
            if(ans.MAX <= 0)
                cout << "0\n";
            else
                cout << ans.MAX << "\n";
        }
}