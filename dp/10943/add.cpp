#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> Memo;

int ways(int N, int K){
  if(K==1) return 1;

  int &count = Memo[N][K];
  if(count != 0) return count;

  for(int i = 0; i <= N; i++) count += ways(N-i, K-1) % 1000000;
  return count;
}

int main(){
  ios_base::sync_with_stdio(false);
  
  int N, K;
  while(cin >> N >> K && (N+K)) {
    Memo.clear(); Memo.resize(N+1, vector<int>(K+1));
    cout << ways(N, K) % 1000000 << "\n";
  }
    
  return 0;
}