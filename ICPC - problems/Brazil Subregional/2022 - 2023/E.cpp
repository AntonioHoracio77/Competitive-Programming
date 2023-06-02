#include <bits/stdc++.h>  
 
 
using namespace std;
 
int qtd[1000100];
 
int main(){
    int n,arrows = 0,v;
        cin >> n;
        for(int i = 0; i < n; i ++){
            cin >> v;
            if(!qtd[v])
                arrows ++;
            else
                qtd[v] --;    
            qtd[v - 1] ++; 
 
        }
 
        cout << arrows << "\n";
    return 0;
} 