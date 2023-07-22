#include <bits/stdc++.h>
 
using namespace std;

int SUB(string s,string sub,int n,int m){
    if(m == 1 && n == 1)
        return s[0] == sub[0];
    if(n == 0)
        return 0;
    if(m == 0)
        return 1;
    
    return ((s[n - 1] == sub[m - 1]) ? SUB(s,sub,n - 1,m - 1) : 0) + 
    SUB(s,sub,n - 1,m);
}
