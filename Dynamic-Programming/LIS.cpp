#include <bits/stdc++.h>
#define ll long long

using namespace std;

int LIS(vector < int > arr) {
    int n = arr.size();
    vector < int > dp(n,1);

    int len = 1;
    for(int i = 1; i < n; i ++){
        for(int j = 0; j < i; j ++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[j] + 1,dp[i]);
                len = max(len,dp[i]);
            }
        }
    }
    return len;
}

ll numOfIncSubseqOfSizeK(int arr[], int n, int k)
{
    ll dp[k][n], sum = 0;
    memset(dp, 0, sizeof(dp));
 
    for (int i = 0; i < n; i++)
        dp[0][i] = 1;

    for (int l = 1; l < k; l++) {
        for (int i = l; i < n; i++) {
 
            dp[l][i] = 0;
            for (int j = l - 1; j < i; j++) {
                if (arr[j] < arr[i])
                    dp[l][i] += dp[l - 1][j];
            }
        }
    }
 

    for (int i = k - 1; i < n; i++)
        sum += dp[k - 1][i];

    return sum;
}

