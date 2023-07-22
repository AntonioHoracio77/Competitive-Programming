#include <bits/stdc++.h>  
#define MAXN 100100

/*https://www.spoj.com/problems/NICEDAY/*/
using namespace std;

typedef long long ll;

typedef struct{
    int a,b,c;
}jogador;

int seg[MAXN * 4];

bool crescente(const jogador &a, const jogador &b){
    return a.a < b.a;
}

void update(int pos, int ini, int fim,int id,int c){
    if(id < ini || id > fim)
        return;
    if(ini == fim){
        seg[pos] = c;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    int n;
    vector < jogador > j(n);
        for(int i = 0; i < n; i ++)
            cin >> j[i].a >> j[i].b >> j[i].c;

        sort(j.begin(),j.end(),crescente);

        for(int i = 0; i < n; i ++){

        }

    return 0;
} 
