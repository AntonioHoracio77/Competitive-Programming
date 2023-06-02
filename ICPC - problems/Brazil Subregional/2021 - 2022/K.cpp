#include <bits/stdc++.h>  
#include <math.h>
 
using namespace std;
 
typedef long long ll;
 
 
int main(){
    ios_base::sync_with_stdio(false);
    int t,d,m,maxMin = 0;
        cin >> t >> d >> m;
        if(m > 0){
            int ref[m];
            for(int i = 0; i < m; i ++){
                cin >> ref[i];
                if(i > 0)
                    maxMin = max(maxMin,ref[i] - ref[i - 1]);
            }
            maxMin = max(maxMin,ref[0]);  
            maxMin = max(maxMin,d - ref[m - 1]);
        }
        else
            maxMin = max(t,d);
        if(maxMin >= t && d >= t)  
            cout << "Y\n";
        else
            cout << "N\n";
        
 
 
    return 0;
} 
 