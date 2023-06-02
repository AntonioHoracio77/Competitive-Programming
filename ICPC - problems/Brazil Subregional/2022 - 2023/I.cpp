#include <bits/stdc++.h>
 
 
using namespace std;
 
 
int main() {
    short bits[8];
    bool flag = true;
    for(int i = 0; i < 8; i ++){
        cin >> bits[i];
        if(bits[i] != 0 && bits[i] != 1)
            flag = false;
    }
    if(flag)
        cout << "S\n";
    else
        cout << "F\n";
    return 0;
}
 