/*https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A*/

#include <bits/stdc++.h>  
#define MAXN 100100
 
using namespace std;
 
typedef long long ll;
 
ll seg[4 * MAXN];
 
void update(int pos,int ini,int fim,int id,ll val){
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
    seg[pos] = seg[esq] + seg[dir];
}
 
// complexidade aproximada O(logN)
ll query(int pos,int ini,int fim,int p,int q){
    if(q < ini || p > fim)
        return 0;
    if(p <= ini && fim <= q)
        return seg[pos];
    
    int meio = (ini + fim) / 2;
    int esq = 2 * pos + 1,dir = 2 * pos + 2;
    return query(esq,ini,meio,p,q) + query(dir,meio + 1,fim,p,q);
}
 
 
 
int main(){
    ios_base::sync_with_stdio(false);
    int n,q,op;
    ll r,l;
        cin >> n >> q;
        ll arr[n];
        for(int i = 0; i < n; i ++){
            cin >> arr[i];
            update(0,0,n - 1,i,arr[i]);
        }
        while(q --){
            cin >> op >> l >> r;
            if(op == 1)
                update(0,0,n - 1,l,r);
            else{
                ll ans = query(0,0,n - 1,l,r - 1);
                cout << ans << "\n";
            }
        }
        
    return 0;
} 
 