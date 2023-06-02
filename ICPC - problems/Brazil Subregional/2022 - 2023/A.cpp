#include <bits/stdc++.h>
 
 
using namespace std;
 
 
int main() {
    int tam,size = 0,maxSize = 0;
    string str;
        cin >> tam >> str;
        for(int i = 0; i < tam; i ++){
            if(str[i] == 'a')
                size ++;
            else{
                if(size > 1)
                    maxSize += size;
                size = 0;
            }
        }
        if(size > 1)
            maxSize += size;
        cout << maxSize << "\n";
    return 0;
}
 