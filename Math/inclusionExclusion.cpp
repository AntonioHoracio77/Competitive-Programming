#include <bits/stdc++.h>

using namespace std;

// Example: total number of divisor thil n

// this values depending the n
vector < int > primes = {2,3,5,7,11,13,17,19};


int solve(int n){
    int m = primes.size();
    int ans = 0;
    // using a bits for set combinations
        for(int i = 1; i < (1 << m); i ++){
            int lcm = 1;
            for(int j = 0; j < m; j ++){
                if((i >> j) & 1){
                    lcm *= primes[j];
                }
            }
            /* counting a set bits in number
               if value is odd, include
               if value is even exclude */ 
            if(__builtin_popcount(i) % 2 == 0)
                ans -= (n / lcm);
            else
                ans += (n / lcm);
        }
    return ans;
}