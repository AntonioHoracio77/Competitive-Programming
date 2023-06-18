#include <bits/stdc++.h>

using namespace std;

void multiply(vector < int > &ans,int no, int *sz){
    int carry = 0,product;
    for(int i = 0; i < *sz; i ++){
        product = ans[i] * no + carry;
        ans[i] = product % 10;
        carry = product / 10;
    }
    while(carry){
        ans[*sz] = carry % 10;
        carry /= 10;
        *sz = *sz + 1;
    }
}

void bigFactorial(int n){
    vector < int > ans(1000,0);
    int sz = 1;
    ans[0] = 1;

    for(int i = 2; i <= n; i ++){
        multiply(ans,i,&sz);
    }

    for(int i = sz - 1; i >= 0; i --)
        cout << ans[i];
    cout << "\n";
}
