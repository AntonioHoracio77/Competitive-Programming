#include <bits/stdc++.h>

using namespace std;

void build(int arr[],int n){
    int m = sqrt(n) + 1;
    int b[m];
        for(int i = 0; i < n; i ++)
            b[i / m] += arr[i];
}

int query(int arr[],int b[],int m,int p,int q){
    int ans = 0;
        for(int i = p; i <= q;){
            if(i % m == 0 && i + m - 1 <= q){
                ans += b[i / m];
                i += m;
            }
            else{
                ans += arr[i];
                i ++;
            }
        }
    
    return ans;
}

void update(int arr[],int b[],int m,int idx,int v){
    b[idx / m] -= arr[idx] + v;
}