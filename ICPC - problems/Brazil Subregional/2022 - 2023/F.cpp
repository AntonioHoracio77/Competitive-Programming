#include <bits/stdc++.h>

using namespace std;

typedef struct tn{
    tn *alp[26];
    bool isLast;
    int ct;
}trieNode;

string ans;
int maxCoincd;

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
            if(w[i] == '*'){
                trieNode *aux;
                for(int j = 0; j < 26; j ++){
                    aux = node;
                    if(!aux->alp[j]){
                        aux->alp[j] = getNode();
                    }
                    aux = aux->alp[j];
                    aux->ct ++;
                    for(int k = i + 1; k < w.size(); k ++){
                        idx = w[k] - 'a';
                        if(!aux->alp[idx])
                            aux->alp[idx] = getNode();
                        aux = aux->alp[idx];
                        aux->ct ++;
                    }
                    aux->isLast = true;
                }
                break;
            }
            idx = w[i] - 'a';
            if(!node->alp[idx])
                node->alp[idx] = getNode();
            node = node->alp[idx];
            node->ct ++;
                
        }

}

void multidimensionalHang(trieNode *root,string s,int alpID){
    trieNode *node = root;
    int idx,MAX = 0,MIN = INT_MAX,tam = s.size();
    string st = "";
    for(int i = 0; i < tam; i ++){
        if(s[i] == '*'){
            idx = alpID;
            MAX = node->alp[idx]->ct;
        }
        else{
            idx = s[i] - 'a';
        }
        MIN = min(MIN,node->alp[idx]->ct);
        st += (idx + 'a');
        node = node->alp[idx];
    }
    
    if(MIN > maxCoincd){
        maxCoincd = MIN;
        ans = st;
    }
    else if(MIN == maxCoincd){
        if(st < ans){
            maxCoincd = MIN;
            ans = st;
        }
    }

    
}

int main(){
    int n,t;
    trieNode *root = getNode();
        cin >> n >> t;
        string s[n];
        for(int i = 0; i < n; i ++){
            cin >> s[i];
            insert(root,s[i]);
        }
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < 26; j ++)
                multidimensionalHang(root,s[i],j);
        }
        cout << ans << " " << maxCoincd << "\n";
    return 0;
}