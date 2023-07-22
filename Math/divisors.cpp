#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int countingDivisors(int n){
    int divisors = 1;
    for(int i = 2; i * i <= n; i ++){
        if(n % i == 0){
            int pot = 0;
            while(n % i == 0){
                n /= i;
                pot ++;
            }
            divisors *= (pot + 1);
        }
    }
    if(n != 1)
        divisors *= 2;
    
    return divisors;
}

int sumOfDivisors(int n){
    int sumDivisors = 1;
    for(int i = 2; i * i <= n; i ++){
        if(n % i == 0){
            int pot = 0;
            while(n % i == 0){
                n /= i;
                pot ++;
            }
            sumDivisors *= ((pow(i,pot + 1) - 1) / (i - 1));
        }
    }
    if(n != 1)
        sumDivisors *= ((pow(n,2) - 1) / (n - 1));
    
    return sumDivisors;
}

