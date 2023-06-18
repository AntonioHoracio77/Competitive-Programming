#include <bits/stdc++.h>
#define MAXN 2

using namespace std;

// ans = a^b
int binaryExp(int a,int b){
    int ans = 1;
    while(b){
        if(b & 1)
            ans *= a;
        a *= a;
        b  = (b >> 1);
    }
    return ans;
}

// ans = a x b
int binaryMultiplication(int a,int b){
    int ans = 1;
    while(b){
        if(b & 1)
            ans += a;
        a *= 2;
        b  = (b >> 1);
    }
    return ans;
}

