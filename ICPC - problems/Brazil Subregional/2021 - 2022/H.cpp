#include <bits/stdc++.h>
 
 
using namespace std;
 
typedef struct{
    int v,pos;
}bloco;
 
bool crescente (const bloco &a, const bloco &b){
    return a.v < b.v;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    int n,k;
    bool ans = true;
        cin >> n >> k;
        vector < bloco > b(n),aux(n);
        for(int i = 0; i < n; i ++)
            cin >> b[i].v >> b[i].pos;
        aux = b;
        sort(b.begin(),b.end(),crescente);
        for(int i = 0; i < n; i ++){
            if(b[i].pos != aux[i].pos){
                ans = false;
                break;
            }
        }
        if(ans)
            cout << "Y\n";
        else
            cout << "N\n";
    return 0;
} 
 