//https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/B
#include <bits/stdc++.h>  
#include <math.h>
#define MAXN 100005
#define MOD  1000000007
 
using namespace std;

typedef long long ll;

typedef struct{
    ll sum,lzSum;
}node;

vector < node > seg(MAXN * 4);

void refresh(int pos,int ini, int fim){
    ll num = seg[pos].lzSum;
    seg[pos].lzSum = 1;
    if(seg[pos].sum == 1)
        seg[pos].sum = ((fim - ini + 1) * num) % MOD;
    else
        seg[pos].sum = (seg[pos].sum * num) % MOD;

    if(ini == fim)
        return;
    
    int e = 2 * pos + 1,d = 2 * pos + 2;
    seg[e].lzSum = (seg[e].lzSum * num) % MOD;
    seg[d].lzSum = (seg[d].lzSum * num) % MOD;
}
void updateQuery(int pos, int ini, int fim, int p, int q, ll val){
    refresh(pos,ini,fim);

    if(q < ini || p > fim)
        return;
    
    if(p <= ini && fim <= q){
        seg[pos].lzSum = (seg[pos].lzSum * val) % MOD;
        refresh(pos,ini,fim);
        return;
    }

    int m = (ini + fim) / 2;
    int e = 2 * pos + 1, d = 2 * pos + 2;

    updateQuery(e,ini,m,p,q,val);
    updateQuery(d,m + 1,fim,p,q,val);
    seg[pos].sum = (seg[e].sum + seg[d].sum) % MOD;
}

ll query(int pos, int ini, int fim, int p, int q){
    refresh(pos,ini,fim);
    if(q < ini || p > fim)
        return 0;
    
    if(p <= ini && fim <= q){
        return seg[pos].sum;
    }
        
    
    int m = (ini + fim) / 2;
    int e = 2 * pos + 1, d = 2 * pos + 2;
    return (query(e,ini,m,p,q) + query(d,m + 1,fim,p,q)) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    int n,q,i,f,op;
    ll v;
        seg.assign(MAXN * 4,{1,1});
        cin >> n >> q;
        while(q --){
            cin >> op;
            if(op == 1){
                cin >> i >> f >> v;
                updateQuery(0,0,n - 1,i,f - 1,v);
            }
            else{
                cin >> i >> f;
                cout << query(0,0,n - 1,i,f - 1) << "\n";
            }
        }
            
    return 0;
} 


