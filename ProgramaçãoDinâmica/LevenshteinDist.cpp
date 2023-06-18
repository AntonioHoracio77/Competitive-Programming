#include <bits/stdc++.h>
#include <iomanip>
 
using namespace std;

int levenshteinDistance(const string& string1, const string& string2) {
    int m = string1.length();
    int n = string2.length();

    vector<vector<int>> distance(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        distance[i][0] = i;
    }

    for (int j = 0; j <= n; j++) {
        distance[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int cost = (string1[i - 1] == string2[j - 1]) ? 0 : 1;

            distance[i][j] = min({ distance[i - 1][j] + 1, distance[i][j - 1] + 1, distance[i - 1][j - 1] + cost });
        }
    }

    return distance[m][n];
}