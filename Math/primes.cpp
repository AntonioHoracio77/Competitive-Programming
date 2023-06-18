#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

typedef long long ll;

vector < int > primes(MAXN,1);

void sieveOfErasthostenes(int n){
    primes[0] = primes[1] = 0;
    for(ll i = 2; i <= n; i ++){
        if(primes[i] == 1){
            for(ll j = i * i; j <= n; j += i)
                primes[i] = 0;
        }
    }
}

bool isPrime(int n){
    if(n == 1 || n == 0)
        return false;

    for(int i = 2; i <= sqrt(n); i ++){
        if(n % i == 0)
            return false;
    }
    return true;
}

// O(sqrt(n))
vector < int > factorization(int n){
    vector < int > factors;
    for(int i = 2; i * i <= n; i ++){
        if(n % i == 0){
            factors.push_back(i);
            while(n % i == 0)
                n /= i;
        }
    }
    if(n != 1)
        factors.push_back(n);
    
    return factors;
}


// O(NloglogN) prime sieve
void primeSieve(vector<int> &sieve){

	for(int i=1; i<= MAXN; i++){
		sieve[i] = i;
	}
	//start from 2 to N
	for(ll i=2; i<=MAXN; i++){
		//whether a no is prime 
		if(sieve[i]==i){

			for(ll j= i*i; j<=MAXN; j = j + i){
				//mark of them if they are already not marked with the value i
				if(sieve[j]==j){
					sieve[j] = i;
				}
			}
		}
	}

}

// O(logN) factorization
vector<int> getFactorisation(int number, vector<int> &sieve){
	vector<int> factors;
	while(number!=1){
        // divide the value by the prime referent
		factors.push_back(sieve[number]);
		number = number/sieve[number];
	}
	return factors;
}
