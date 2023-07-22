#include <bits/stdc++.h>
#define MAXN 100
#define MAXW 100

using namespace std;

int v[MAXN],w[MAXN],maxW,n;
vector < vector < int > > memo(MAXN,vector < int > (MAXW,-1));


int knapsack(int i,int weight){
    if(i >= n)
        return 0;
    int &ans = memo[i][weight];
    if(ans != -1)
        return ans;
    ans = knapsack(i + 1,weight);
    if(w[i] + weight <= maxW)
        ans = max(ans,v[i] + knapsack(i + 1,w[i] + weight));
    return ans;
}


int knapsackBottomUp(){
    int dp[n + 1][maxW + 1];
        memset(dp,0,sizeof(dp));
        for(int i = 1; i <= maxW; i ++){
            for(int j = 1; j <= n; j ++){
                int s = dp[j - 1][i];
                if(w[j - 1] <= i)
                    s = max(s,dp[j - 1][i - w[j - 1]] + v[j - 1]);
                dp[j][i] = s;
            }
        }

        return dp[n][maxW];
}
