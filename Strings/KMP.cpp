#include <bits/stdc++.h>

using namespace std;

vector < int > pi(string s){
    vector < int > p(s.size());
    for(int i = 1, j = 0; i < s.size(); i ++){
        while(j > 0 && s[j] != s[i])
            j = p[j - 1];
        if(s[j] == s[i])
            j ++;
        p[i] = j;
    }
    return p;
}

vector<int> KMP(string& t,string &s) {
    vector<int> p = pi(s + '$'),match;
    for (int i = 0,j = 0; i < t.size(); i++) {
        while(j > 0 && s[j] != t[i])
            j = p[j - 1];
        if(s[j] == t[i])
            j ++;
        if(j == s.size())
            match.push_back(i - j + 1);
        
    }
    return match;
}