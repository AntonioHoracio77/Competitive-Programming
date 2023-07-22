//https://codeforces.com/edu/course/2/lesson/5/2/practice/contest/279653/problem/A
#include <bits/stdc++.h>  
#include <math.h>
#define MAXN 100005
 
using namespace std;

typedef long long ll;

typedef struct{
    ll MIN,lzSum;
}node;

node seg[MAXN * 4];

void refresh(int pos,int ini, int fim){
    if(seg[pos].lzSum == 0){
        return;
    }
        
    
    ll num = seg[pos].lzSum;
    seg[pos].lzSum = 0;
    seg[pos].MIN += num;

    if(ini == fim)
        return;
    
    int e = 2 * pos + 1,d = 2 * pos + 2;
    seg[e].lzSum += num;
    seg[d].lzSum += num;
}
void updateQuery(int pos, int ini, int fim, int p, int q, ll val){
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

    seg[pos].MIN = min(seg[e].MIN,seg[d].MIN);
    seg[pos].lzSum = seg[e].lzSum + seg[d].lzSum;
}

ll query(int pos, int ini, int fim, int p, int q){
    refresh(pos,ini,fim);
    if(q < ini || p > fim)
        return INT_MAX;
    
    if(p <= ini && fim <= q)
        return seg[pos].MIN;
    
    int m = (ini + fim) / 2;
    int e = 2 * pos + 1, d = 2 * pos + 2;
    return min(query(e,ini,m,p,q),query(d,m + 1,fim,p,q));
}

int main(){
    ios_base::sync_with_stdio(false);
    int n,q,i,f,op;
    ll v;
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
