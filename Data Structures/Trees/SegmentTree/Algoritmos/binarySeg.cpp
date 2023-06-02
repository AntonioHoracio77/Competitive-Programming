#include <bits/stdc++.h>
#include <stdlib.h>
#define MAXN 1000

using namespace std;

// Posso aplicar com qualquer tipo de seg

typedef struct{
    int sum,max;
}node;

node seg[MAXN * 4];

// retorna o primeiro indice cuja soma de prefixos é >= s
int binarySeg(int pos, int ini, int fim, int s){
    if(ini == fim)
        return ini;
    
    int m = (ini + fim) / 2;
    int e = 2 * pos + 1,d = 2 * pos + 2;

    if(seg[e].sum >= s)
        return binarySeg(e,ini,m,s);
    else
        return binarySeg(d,m + 1,fim, s - seg[e].sum);
}

// retorna o primeiro indice j >= i cujo v[j] >= h

int binarySeg2(int pos, int ini, int fim, int i, int h){
    if(seg[pos].max < h)
        return -1;
    
    if(ini == fim)
        return ini;
    
    int m = (fim + ini) / 2;
    int e = 2 * pos + 1, d = 2 * pos + 2;

    if(i > m)
        return binarySeg2(d,m + 1,fim,i,h);
    
    int tmp = binarySeg2(e,ini,m,i,h);

    if(tmp != -1)
        return tmp;
    
    return binarySeg2(d,m + 1,fim,m + 1,h);

}