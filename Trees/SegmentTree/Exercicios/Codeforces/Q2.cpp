/*https://codeforces.com/group/btcK4I5D5f/contest/295070/problem/J*/
#include <bits/stdc++.h>  
#include <math.h>
#define MAXN 100100
 
using namespace std;

typedef struct{
    long diaD,diaE,viagens;
}node;

node seg[4 * MAXN];


void update(int pos,int ini,int fim,int id,long val){
    if(id < ini || id > fim)
        return;
    if(ini == fim){
        seg[pos].diaD = seg[pos].diaE = val;
        seg[pos].viagens = 0;
        return;
    }
    int meio = (ini + fim) / 2;
    int esq = 2 * pos + 1, dir = 2 * pos + 2;

    update(esq,ini,meio,id,val);
    update(dir,meio + 1,fim,id,val);
    if(seg[esq].diaD != seg[dir].diaE)
        seg[pos].viagens = seg[esq].viagens + seg[dir].viagens + 1;
    else
        seg[pos].viagens = seg[esq].viagens + seg[dir].viagens;
    seg[pos].diaD = seg[dir].diaD;
    seg[pos].diaE = seg[esq].diaE;
    
        

}

// complexidade aproximada O(logN)
node query(int pos,int ini,int fim,int p,int q){
    node ans;
    ans.diaD = ans.diaE = 0;
    ans.viagens = -1;
    if(q < ini || p > fim)
        return ans;
    if(p <= ini && fim <= q)
        return seg[pos];
    
    int meio = (ini + fim) / 2;
    int esq = 2 * pos + 1,dir = 2 * pos + 2;
    node e = query(esq,ini,meio,p,q),d = query(dir,meio + 1,fim,p,q);

    if(e.viagens == -1 && d.viagens == -1){
        ans.diaD = ans.diaE = 0;
        ans.viagens = -1;
    }
    else if(e.viagens == -1){
        ans.viagens = d.viagens;
        ans.diaD = d.diaD;
        ans.diaE = d.diaE;
    }
    else if(d.viagens == -1){
        ans.viagens = e.viagens;
        ans.diaD = e.diaD;
        ans.diaE = e.diaE;
    }
    else if(e.diaD == d.diaE){
        ans.viagens = e.viagens + d.viagens;
        ans.diaD = d.diaD;
        ans.diaE = e.diaE;
    }
    else{
        ans.viagens = e.viagens + d.viagens + 1;
        ans.diaD = d.diaD;
        ans.diaE = e.diaE;
    }
    
    

    return ans;
    
}



int main(){
    ios_base::sync_with_stdio(false);
    int n,q,op;
    long l,r;
        cin >> n >> q;
        long dia[n];
        for(int i = 0; i < n; i ++){
            cin >> dia[i];
            update(0,0,n - 1,i,dia[i]);
        }
        while(q --){
            cin >> op >> l >> r;
            if(op == 1){
                node ans = query(0,0,n - 1,l - 1,r - 1);
                cout << ans.viagens << "\n";
            }
            else{
                update(0,0,n - 1, l - 1, r);
            }
        }
    return 0;
} 

