#include <bits/stdc++.h>

using namespace std;

int LIS(long v[],int n) {
    const int INF = 1e9;
    vector <int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        // busca binária retornando a posição do valor
        int l = upper_bound(d.begin(), d.end(), v[i]) - d.begin();
        if (d[l-1] < v[i] && v[i] < d[l])
            d[l] = v[i];
    }

    int ans = 0;
    for (int l = 0; l <= n; l++) {
        if (d[l] < INF)
            ans = l;
    }
    return ans;
}
