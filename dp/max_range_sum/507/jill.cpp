#include <bits/stdc++.h>
using namespace std;

void testcase(int count){
  int S; cin >> S;
  vector<int> niceness(S); //niceness[0] not used;
  for(int i=1; i < S; ++i){
    cin >> niceness[i];//niceness of stop i and i+1
  }

  vector<int> dp(S+1); //dp[0];
  
  int maxsum;
  dp[1] = maxsum = 0;
  int beststart=1, bestend=1, start=1;

  for(int i = 2; i <= S; i++){
    int with = dp[i-1] + niceness[i-1];
    if(with < 0) {
      dp[i] = 0;
      start=i;
      continue;
    }

    dp[i] = with;
    if(with > maxsum){
      beststart = start;
      bestend = i;
      maxsum = with;
    }
    else if(with == maxsum){
      if(i - start > bestend - beststart){
        beststart = start; 
        bestend = i;
      }
    }
  }

  if(bestend == 1) cout << "Route " << count << " has no nice parts\n";
  else cout << "The nicest part of route " << count << " is between stops " << beststart << " and " << bestend << "\n"; 




}

int main(){
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  int count = 1;
  while(T--) testcase(count++);
  return 0;
}