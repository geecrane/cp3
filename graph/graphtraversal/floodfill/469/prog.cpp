#include <bits/stdc++.h>
using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;
#define REP(i, n) for (int i = 0; i < (int)n; ++i)
int dc[] = {-1, -1, -1, 0, 0, 1,1,1};
int dr[] = {-1,  0,  1,-1, 1,-1,0,1};

vvc grid(100,vc(100));
vector<vector<int>> comp(100, vector<int>(100, -1));

int R, C, cnt;

int floodfill(int r, int c, char c1, char c2){
  if(r<0 || r>=R || c<0 || c>=C) return 0;
  if(grid[r][c]!=c1) return 0;
  grid[r][c]=c2;
  comp[r][c]=cnt;
  int ans=1;
  REP(i,8) ans+=floodfill(r+dr[i], c+dc[i], c1, c2);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  int T; cin >> T;

  string s; cin >> s;
  REP(t, T) {
    if(t) cout << "\n";
    C = s.size(),  R = 0;
    do {
      copy(s.begin(), s.end(),grid[R++].begin());
    } while (cin >> s && (s[0] == 'L' || s[0] == 'W'));

    //precompute component sizes
    vector<int> csize; cnt = 0;
    REP(i,R)REP(j,C){
      if(grid[i][j]=='W'){
        csize.push_back(floodfill(i,j, 'W', '.'));
        cnt++;
      }
    }

    do {
      int r = stoi(s); cin >> s;
      int c = stoi(s);
      cout << csize[comp[--r][--c]]<< "\n";
    } while (cin >> s && s[0] != 'L' && s[0] != 'W');
  }
  return 0;
}