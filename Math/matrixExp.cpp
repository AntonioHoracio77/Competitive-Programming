#include <bits/stdc++.h>
#define MAXN 2

using namespace std;

struct mat{
    int m[MAXN][MAXN];
    mat(){
        memset(m,0,sizeof(MAXN));
    }
    void identity(){
        for(int i = 0; i < MAXN; i ++){
            m[i][i] = 1;
        }
    }

    mat operator* (mat a){
        mat ans;
        for(int i = 0; i < MAXN; i ++){
            for(int j = 0; j < MAXN; j ++){
                for(int k = 0; k < MAXN; k ++){
                    ans.m[i][j] += m[i][k] * a.m[k][j];
                }
            }
        }
        return ans;
    }
};


int matrixExp(int n){
    mat ans;
    ans.identity();
    mat t;
    t.m[0][0] = t.m[0][1] = t.m[1][0] = 1;
    if(n < 2)
        return 1;
    
    n -= 2;
    while(n){
        if(n&1)
            ans = ans * t;
        t = t * t;
        n = n >> 1;
    }
    return ans.m[0][0] + ans.m[0][1];
}