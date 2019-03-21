#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  int N, n, k; cin >> N;
  while(N--) {
    cin >> n >> k;
    cout << (k ^ (k>>1)) << "\n";
  }
  return 0;
}