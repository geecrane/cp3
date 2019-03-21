#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;

int dp(size_t pos, int s, VI &b, VVI &memo){
  if(s == 0) return 1;
  if(s < 0 || pos == b.size()) return 0;

  int &res = memo[pos][s];
  if(res > - 1) return res;

  return (res = dp(pos+1, s-b[pos], b, memo) || dp(pos+1, s, b, memo));
}

int main(){
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  while(T--){
    int n, p; cin >> n >> p;

    VI b(p);
    for(int i = 0; i < p; i++) cin >> b[i];

    VVI memo(p, VI(n+1, -1));
    if(dp(0, n, b, memo)) cout << "YES\n";
    else cout << "NO\n";    
  }
  return 0;
}