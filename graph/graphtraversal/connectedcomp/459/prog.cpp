#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)n; ++i)

typedef vector<int> vi;
typedef vector<vi> vvi;

vi d;
vvi g;

void dfs(int u) {
  d[u] = 1;
  for (int v : g[u])
    if (!d[v]) dfs(v);
}

int main() {
  ios_base::sync_with_stdio(false);
  int t, off = 'A';
  cin >> t;
  
  string s;
  cin >> s;
  REP(i, t) {
    if (i > 0) cout << "\n";
    int N = s[0] - off + 1;

    g = vvi(N);
    d = vi(N, 0);
    while (cin >> s && s.size() == 2) {
      g[s[0] - off].push_back(s[1] - off);
      g[s[1] - off].push_back(s[0] - off);
    }
    int c = 0;
    REP(u, N)
    if (!d[u]) {
      c++;
      dfs(u);
    }
    cout << c << "\n";
  }
  return 0;
}