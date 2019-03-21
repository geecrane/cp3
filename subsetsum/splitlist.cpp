#include <bits/stdc++.h>
using namespace std;

inline void subset(vector<int> &S, const vector<int> &b, const int n){
  S.reserve(1<<b.size());
  for(int s = 0; s < (1<<b.size()); s++){
    int sum = 0;
    for(size_t i = 0; i < b.size(); i++)if(s & (1 << i)) sum += b[i];
    S.push_back(sum);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  int T; cin >> T;
  while(T--){
    int n, p; cin >> n >> p;

    vector<int> b1(p/2), b2(p-b1.size());
    for(size_t i = 0; i < b1.size(); i++) cin >> b1[i];
    for(size_t i = 0; i < b2.size(); i++) cin >> b2[i];

    vector<int> S1; subset(S1, b1, n);
    vector<int> S2; subset(S2, b2, n);
    
    sort(S2.begin(), S2.end());

    size_t i;
    for(i=0; i < S1.size(); i++){
      auto it = lower_bound(S2.begin(), S2.end(), n-S1[i]);
      if(it != S2.end() && *it == n - S1[i]) {
        cout << "YES\n"; break;
      }
    }
    
    if(i==S1.size()) cout << "NO\n";
    
  }
  return 0;
}