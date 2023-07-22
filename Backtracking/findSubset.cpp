#include <bits/stdc++.h>

using namespace std;

void findSubsets(char input[],char output[],int i,int j){   
    // base case
    if(input[i] == '\0'){
        output[j] = '\0';
        cout << output << "\n";
        return;
    }

    output[j] = input[i];
    findSubsets(input,output,i + 1,j + 1);
    output[j] = '\0';
    findSubsets(input,output,i + 1,j);
}


