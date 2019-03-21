#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define sz(a) (int)a.size()

vvi grid;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};
char ch[] = {'W', 'A', 'K', 'J', 'S', 'D'};
int inf = 999;

int ff(int r, int c, int c1, int c2, int c3) {
  if (r < 0 || r >= sz(grid) || c < 0 || c >= sz(grid[0])) return 0;
  if (grid[r][c] != c1 && grid[r][c] != c3) return 0;
  int holes = 0;
  if (grid[r][c] == c3) {
    ff(r, c, c3, c2, inf);
    return 1;
  } else {
    grid[r][c] = c2;
    REP(i, 4) holes += ff(r + dr[i], c + dc[i], c1, c2, c3);
  }
  return holes;
}

int main() {
  ios_base::sync_with_stdio(false);
  int H, W, c = 1;
  string l;
  while (cin >> H >> W && H + W) {
    int W4 = W << 2;
    multiset<char> res;
    grid = vvi(H, vi(W4, 0));

    REP(h, H) {
      cin >> l;
      REP(w, W) {
        if (l[w] >= '0' && l[w] <= '9')
          REP(o, 4) if ((l[w] - '0') & (1 << o)) grid[h][(w << 2) + 3 - o] = 1;
        if (l[w] >= 'a' && l[w] <= 'f') 
          REP(o, 4) if ((l[w] - 'a' + 10) & (1 << o)) grid[h][(w << 2) + 3 - o] = 1;
      }
    }

    REP(h, H) {
      if (!grid[h][0]) ff(h, 0, 0, -1, inf);
      if (!grid[h][W4 - 1]) ff(h, W4 - 1, 0, -1, inf);
    }

    REP(w, W4) {
      if (!grid[0][w]) ff(0, w, 0, -1, inf);
      if (!grid[H - 1][w]) ff(H - 1, w, 0, -1, inf);
    }

    REP(i, H) REP(j, W4) {
      if (grid[i][j] == 1) {
        int idx = ff(i, j, 1, -1, 0);
        res.insert(ch[idx]);
      }
    }

    cout << "Case " << c++ << ": ";
    for (char v : res) cout << v;
    cout << "\n";
  }
  return 0;
}