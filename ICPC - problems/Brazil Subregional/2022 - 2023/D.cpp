#include <bits/stdc++.h>  
#include <math.h>
 
 
using namespace std;
 
 
int main(){
    int n,x,y,quadrado = 0;
        cin >> n >> x >> y; 
        while(x % 2 == 0 && y % 2 == 0){
            quadrado ++;
            x /= 2;
            y /= 2;
        }
        cout << (n - 1) - quadrado << "\n";
        
        
    return 0;
} 
 