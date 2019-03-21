#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  while(T--){
    int n, p, sum=0; cin >> n >> p;
    
    vector<int> bars(p);
    for(int i = 0; i < p; i++) cin >> bars[i];

    for(int s = 0; s < (1<<p) && sum != n; s++){
      sum = 0;
      for(int i = 0; i < p; i++)if(s & (1 << i)) sum += bars[i];
    }
    if(sum == n) cout << "YES\n";
    else cout << "NO\n";
    
  }
  return 0;
}