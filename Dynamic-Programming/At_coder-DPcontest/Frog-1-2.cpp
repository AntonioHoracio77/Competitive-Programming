#include <bits/stdc++.h>

using namespace std;



int jumpFrog_1(int heigth[],int n){
    int dp[n];
    
    dp[0] = 0;
    dp[1] = dp[0] + abs(heigth[1] - heigth[0]);
    for(int i = 2; i < n; i ++){
        dp[i] = min(dp[i - 1] + abs(heigth[i - 1] - heigth[i]),
                    dp[i - 2] + abs(heigth[i - 2] - heigth[i]));
    }

    return dp[n - 1];
}


int jumpFrog_2(int heigth[],int n,int k){
    int dp[n];
    
    dp[0] = 0;
    dp[1] = dp[0] + abs(heigth[1] - heigth[0]);
    for(int i = 2; i < n; i ++){
        dp[i] = INT_MAX;
        for(int j = 1; j <= k && j <= i; j ++){
            dp[i] = min(dp[i],dp[i - j] + abs(heigth[i] - heigth[i - j]));
        }
    }

    return dp[n - 1];
}
