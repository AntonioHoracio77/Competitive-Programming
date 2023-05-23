#include <bits/stdc++.h>
 
using namespace std;

long gcd (long a, long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

long lcm (long a, long b) {
    return a / gcd(a, b) * b;
}
 