#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)n; ++i)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef queue<int> q;

vvi g, dom;
vi r1, r2;

int main()
{
  ios_base::sync_with_stdio(false);
  int T, N;
  cin >> T;
  REP(t, T)
  {
    cin >> N;
    g = vvi(N);
    REP(u, N)
    REP(v, N)
    {
      int b;
      cin >> b;
      if (b)
        g[u].push_back(v);
    }

    r1 = vi(N, 0);
    q s;
    s.push(0);
    r1[0] = 1;
    while (!s.empty())
    {
      int u = s.front();
      s.pop();
      for (int v : g[u])
        if (!r1[v])
        {
          r1[v] = 1;
          s.push(v);
        }
    }

    dom = vvi(N, vi(N, 0));
    REP(x, N)
    {
      r2 = vi(N, 0);
      if (x != 0)
      {
        q s;
        s.push(0);
        r2[0] = 1;
        while (!s.empty())
        {
          int u = s.front();
          s.pop();
          for (int v : g[u])
            if (v != x && !r2[v])
            {
              r2[v] = 1;
              s.push(v);
            }
        }
      }
      REP(i, N)
      if (r1[i] && !r2[i]) dom[x][i] = 1;
    }

    cout << "Case " << t + 1 << ":\n";
    for (auto r : dom)
    {
      cout << "+" << setw(2 * N + 2) << setfill('-') << "+\n|";
      for (auto v : r)
        cout << ((v) ? "Y|" : "N|");
      cout << "\n";
    }
    cout << "+" << setw(2 * N + 1) << setfill('-') << "+\n";
  }
  return 0;
}