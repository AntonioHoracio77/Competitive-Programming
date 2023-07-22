#include <bits/stdc++.h>
#define MAXN 100
#define MAXW 100

using namespace std;

int v[MAXN],w[MAXN],maxW,n;
vector < vector < int > > memo(MAXN,vector < int > (MAXW,-1));

