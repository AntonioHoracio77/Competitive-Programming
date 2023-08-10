#include <bits/stdc++.h>
#define N 100

using namespace std;

int parent[N],Size[N],Rank[N];

void make_set(int v) {
    parent[v] = v;
    Size[v] = 1;
    Rank[v] = 0;
}


int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if(Size[a] < Size[b])
            swap(a, b);
        parent[b] = a;
        Size[a] += Size[b];


        if (Rank[a] < Rank[b])
            swap(a, b);
        parent[b] = a;
        if (Rank[a] == Rank[b])
            Rank[a]++;
    }
}