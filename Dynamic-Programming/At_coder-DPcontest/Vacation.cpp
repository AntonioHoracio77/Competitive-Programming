#include <bits/stdc++.h>
#define MAXN 100

using namespace std;

int days[MAXN][3],dp[MAXN][3];

int vacationBottomUp(int n){
    dp[0][0] = days[0][0];
    dp[0][1] = days[0][1];
    dp[0][2] = days[0][2];
    for(int i = 1; i < n; i ++){
        for(int j = 0; j < 3; j ++){
            for(int k = 0; k < 3; k ++){
                if(j != k)
                    dp[i][j] = max(dp[i][j],dp[i - 1][k] + days[i][j]);
            }
        }
    }

    return max(dp[n - 1][0],max(dp[n - 1][1],dp[n - 1][2]));
}