#include <bits/stdc++.h>
#include <algorithm>
#define MAXN 300005
 
using namespace std;

vector < int > tree[MAXN * 4];
int n;

void build(int pos,int ini,int fim,int arr[]){
    if(ini == fim){
        tree[pos].push_back(arr[ini]);
        return;
    }
    int m = (ini + fim) / 2, e = 2 * pos + 1,d = 2 * pos + 2;
    build(e,ini,m,arr);
    build(d,m + 1,fim,arr);

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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,a,p,f;
        cin >> n >> q;
        int arr[n];
        for(int i = 0; i < n; i ++)
            cin >> arr[i];
        build(0,0,n - 1,arr);
        while(q --){
            cin >> a >> p >> f;
            if(arr[a - 1] >= p)
                cout << "0\n";
            else
                cout << query(0,0,n - 1,a,a + (f - 1),p) << "\n";
        }
        
        
    return 0;
}


