#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;

int main(){
  ios_base::sync_with_stdio(false);
  int n, count = 0;
  VI seq; seq.reserve(1e3);
  while(cin >> n && n > -1){
    seq.clear(); seq.push_back(n);
    while(cin >> n && n > -1) seq.push_back(n);

    VI L(seq.size(), 1);
    for(uint i = 1; i < seq.size(); i++)
      for(int j=i-1; j >= 0; j--)
        if(seq[j] >= seq[i]) L[i] = max(L[i], L[j] + 1);


    auto it = max_element(L.begin(), L.end());
    if(count) cout << "\n";
    cout << "Test #" << ++count << ":\n  maximum possible interceptions: " << *it << "\n";
  }
  return 0;
}