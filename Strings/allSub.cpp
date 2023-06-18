#include <bits/stdc++.h>

using namespace std;

void allSubsequences(string s){
    int n = s.size(),lastBit,j,pos;

    for(int i = 0; i < (1<<n); i ++){
        j = 0;
        pos = i;
        while(pos > 0){
            lastBit = pos & 1;
            if(lastBit)
                cout << s[j];
            pos = pos >> 1;
            j ++;
        }
        cout << "\n";
    }
}
