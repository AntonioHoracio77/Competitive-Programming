#include <bits/stdc++.h>

using namespace std;

typedef struct tn{
    tn *alp[26];
    bool isLast;
    int ct;
}trieNode;


trieNode *getNode(){
    trieNode *node = new trieNode;
    node->isLast = false;
    node->ct = 0;
    for(int i = 0; i < 26; i ++){
        node->alp[i] = NULL;
    }
    return node;
}

void insert(trieNode *root,string w){
    trieNode *node = root;
    int idx;
        for(int i = 0; i < w.size(); i ++){
            idx = w[i] - 'a';
            if(!node->alp[idx])
                node->alp[idx] = getNode();
            node = node->alp[idx];
            node->ct ++;
                
        }

}

bool search(trieNode *root,string s){
    if(root == NULL)
        return false;
    trieNode *node = root;
    int idx,tam = s.size();
    for(int i = 0; i < tam; i ++){
        idx = s[i] - 'a';
        if(!node->alp[idx])
            return false;

        node = node->alp[idx];
    }
    return true;

    
}

