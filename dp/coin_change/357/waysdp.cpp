#include <bits/stdc++.h>
using namespace std;
// https://stackoverflow.com/questions/27880842/space-optimized-solution-for-coin-change
// dp[c][v] = dp[c-1][v] + dp[c][v-coin[c]];
// let d[v] = dp[c-1][v] at beginning of iteration c;
//  then d[v] += dp[c][v-coin[c]] at the end of iteration c;
// finish: d[v] = d[4][v]
int main(){
  int MAX = 30001; vector<int> c = {1, 5, 10, 25, 50}; vector<long> dp(MAX, 0); 

  dp[0] = 1;
  for(int i = 0; i < 5; i++)
    for(int v = c[i]; v < MAX; v++)
      dp[v] += dp[v-c[i]];
  
  int n;
  while(scanf("%d", &n)){
    if(dp[n] == 1) printf("There is only 1 way to produce %d cents change.\n", n);
    else printf("There are %ld ways to produce %d cents change.\n", dp[n], n);
  }
  return 0;
}