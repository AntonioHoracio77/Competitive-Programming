#include <bits/stdc++.h>
#include <algorithm>
 
using namespace std;


bool ODD(int v){
    return v & 1;
}

//retorna o iesimo bit
int getIthBit(int v,int pos){
    return v & (1 << pos) > 0 ? 1 : 0;
}

// seta o iesimo bit como 1
void setIthBit(int *v,int pos){
    *v = *v |(1 << pos);
}

// seta o iesimo bit como 0
void clearIthBit(int *v,int pos){
    *v = *v & (~(1 << pos));
}

// seta o iesimo bit como zero ou um
void updateIthBit(int *v,int pos,int val){
    clearIthBit(v,pos);
    *v = *v | (val << pos);
}

// limpa os ultimos i bits
void clearLastIbits(int *v,int i){
    int mask = (-1 << i);
    *v = *v & mask;
}

// limpa os bits no intevalo de i a j
void clearBitsInRange(int *v,int i,int j){
    int a = -1 << (j + 1), b = (1 << i) - 1;
    int mask = a | b;
    *v = *v & mask;
}

// set os bits de n presentes no intervalo de i a j como os bits de m
void replaceBits(int *n,int *m,int i,int j){
    clearBitsInRange(n,i,j);
    int mask = *m << i;
    *n = *n | mask;
    
}

bool powerOfTwo(int v){
    // igual a zero é potencia de 2
    return !(v & (v - 1));
}

int countingSetBits(int v){
    int count = 0;
    // count bit a bit
    while(v > 0){
        count += (v & 1);
        v = v >> 1;
    }
    return count;
}

// fast method
int countBitsHack(int v){
    int ans = 0;
    // removes last set bit from number
    while(v > 0){
        v = v & (v - 1);
        ans ++;
    }
    return ans;
}

void decToBin(int n){
    string ans = "";
    int lastBit;
    while(n > 0){
        lastBit = (n & 1);
        ans += (lastBit + 48);
        n = n >> 1;
    }
    // reverse ans
}


