/*https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/C*/

#include <bits/stdc++.h>  
#define MAXN 100100
 
using namespace std;
 
typedef long ll;
 
typedef struct{
    ll v;
    int qtd;
}node;
 
node seg[4 * MAXN];
 
void update(int pos,int ini,int fim,int id,ll val){
    if(id < ini || id > fim)
        return;
    if(ini == fim){
        seg[pos].v = val;
        seg[pos].qtd = 1;
        return;
    }
    int meio = (ini + fim) / 2;
    int esq = 2 * pos + 1, dir = 2 * pos + 2;
 
    update(esq,ini,meio,id,val);
    update(dir,meio + 1,fim,id,val);
    ll ans = min(seg[esq].v,seg[dir].v);
    if(ans == seg[esq].v && ans == seg[dir].v)
        seg[pos].qtd = seg[esq].qtd + seg[dir].qtd;
    else if(ans == seg[esq].v)
        seg[pos].qtd = seg[esq].qtd;
    else if(ans == seg[dir].v)
        seg[pos].qtd = seg[dir].qtd;
 
    seg[pos].v = ans;
}
 
 
node query(int pos,int ini,int fim,int p,int q){
    node nulo;
    if(q < ini || p > fim){
        nulo.v = INT_MAX;
        nulo.qtd = 0;
        return nulo;
    }
    if(p <= ini && fim <= q){
        return seg[pos];
    }
    
    
    int meio = (ini + fim) / 2;
    int esq = 2 * pos + 1,dir = 2 * pos + 2;
    node e,d,ans;
    e = query(esq,ini,meio,p,q);
    d = query(dir,meio + 1,fim,p,q);
    if(e.v < d.v){
        ans = e;
    }
    else if(d.v < e.v){
        ans = d;
    }
    else{
        ans.v = e.v;
        ans.qtd = d.qtd + e.qtd;
    }
    return ans;
}
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    int n,q,op;
    ll r,l,v;
        cin >> n >> q;
        for(int i = 0; i < n; i ++){
            cin >> v;
            update(0,0,n - 1,i,v);
        }
        while(q --){
            cin >> op >> l >> r;
            if(op == 1)
                update(0,0,n - 1,l,r);
            else{
                node ans = query(0,0,n - 1,l,r - 1);
                cout << ans.v << " " << ans.qtd << "\n";
            }
        }
        
    return 0;
} 