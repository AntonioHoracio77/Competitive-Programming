#include <bits/stdc++.h>
#define maxn 4

using namespace std;

// travelling salesman problem(problema do caixeiro viajante)
// using bitwise operation

vector < vector < int > > dp(1 << maxn, vector < int > (maxn,-1));

int tsp(vector < vector < int > > dist,int setOfcities,int city,int n){
    // base case, setofcities == 2^n - 1, reached the end of the path
    if(setOfcities == (1 << n) - 1)
        // return dist from initial city
        return dist[city][0];
    if(dp[setOfcities][city] != -1)
        return dp[setOfcities][city];
    // otherwise try all possible options
    int ans = INT_MAX;
    for(int choice = 0; choice < n; choice ++){
        // need to check if city is visited or not
        if(setOfcities & (1 << choice) == 0){
            int subProb = dist[city][choice] + tsp(dist,setOfcities | (1 << choice),choice,n);
            ans = min(ans,subProb);
        }
    }

    return dp[setOfcities][city] = ans;
}

