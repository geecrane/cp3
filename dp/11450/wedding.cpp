#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> GP;
vector<vector<int>> DP;

//spending for the first c garments with budget m
int spending(int c, int m){
  if(c < 0) return 0;

  int &res = DP[c][m];
  if(res > -2) return res;

  int maxspending = -1;
  for(size_t i = 0; i < GP[c].size(); ++i){
    if(GP[c][i] > m) continue; 

    int tmp = spending(c-1, m-GP[c][i]);
    if(tmp == -1) continue;

    maxspending = max(maxspending, tmp + GP[c][i]);
  }
  return res = maxspending;
}

void testcase(){
  int M, C; cin >> M >> C;
  
  DP.clear();
  DP.resize(C, vector<int>(M+1, -2));

  GP.clear();
  GP.resize(C);
  for(int i = 0; i < C; ++i){
    int K; cin >> K;
    GP[i].clear();
    GP[i].resize(K);
    for(int j = 0; j < K; ++j){
      cin >> GP[i][j];
    }
  }
  //for(auto v : GP){ for(auto p : v){ cout << p << " "; } cout << endl; }

  int res = spending(C-1, M);
  if(res>-1) cout << res << "\n";
  else cout << "no solution\n";

}

int main(){
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  while(T--) testcase();
  return 0;
}