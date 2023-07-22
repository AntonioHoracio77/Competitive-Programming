#include <bits/stdc++.h>

using namespace std;

int coinChange(int blocos[],int n,int k){
    int dp[k + 1];
        memset(dp,INT_MAX,sizeof(dp));
        dp[0] = 0;
        for(int i = 0; i < n; i ++){
            for(int j = blocos[i]; j <= k; j ++){
                dp[j] = min(dp[j],dp[j - blocos[i]] + 1);
            }
                
        }
        return dp[k];
}



int coinChange2(int moedas[],int n,int k){
    int dp[k + 1];
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= k; i ++){
            dp[i] = i;
            for(int j = 1; j < n; j ++){
                dp[i] = min(dp[i],(i / moedas[j]) + dp[i % moedas[j]]);
            }
                
        }
        return dp[k];
}
