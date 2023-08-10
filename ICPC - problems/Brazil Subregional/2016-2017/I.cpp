#include <bits/stdc++.h>
#define MAXN 50100

using namespace std;

int n;
int rec[MAXN];

int dp(int blocks[]){
   if(n <= 2)
      return 1;
   int h = 0,ans = 0;
      for(int i = 0; i < n; i ++){
         if(blocks[i] > h)
            h ++;
         else if(blocks[i] < h)
            h  = blocks[i];
         rec[i] = h;
      }


      h = 0;
      for(int i = n - 1; i >= 1; i --){
         if(blocks[i] > h)
            h ++;
         else if(blocks[i] < h)
            h = blocks[i];
         if(h + 1 == rec[i - 1])
            ans = max(ans,rec[i - 1]);
         else
            ans = max(ans,min(h,rec[i - 1]));

      }

      return ans;
}

int main() {
   cin >> n;
   int arr[n];
   for(int i = 0; i < n; i ++)
      cin >> arr[i];
   
   cout << dp(arr) << "\n";
 
    return 0;
}