#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll poly_hash(string s){
    ll hash = 0, p = 31, mod = 1e9 + 7,p_power = 1;

    for(ll i = 0; i < s.size(); i ++){
        hash += (s[i] - 'a' + 1) * p_power;
        p_power *= p;
        hash %= mod;
        p_power %= mod;
    }

    return hash;
}




