#include <bits/stdc++.h>
using namespace std;

#define REP(i,N) for(int i=0;i<(int)N;++i)
#define sz(a) (int)(a.size())
int dr[] = {-1,1,0,0};
int dc[] = {0, 0,-1,1};
vector<string> grid;

int ff(int r, int c, char c1, char c2){
  if(r<0 || r >= sz(grid) || c<0 || c>=sz(grid[0])) return 0;
  if(grid[r][c] != c1) return 0;
  grid[r][c] = c2;
  int ans = 1;
  REP(i,4)ans+=ff(r+dr[i], c+dc[i], c1,c2);
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  int T; cin >> T; 
  REP(t,T){
    if(t) cout << "\n";
    int r, c; cin >> r >> c;
    string l;getline(cin, l); getline(cin,l);

    grid.clear();
    do{
      grid.push_back(l);
    }while(getline(cin,l) && !l.empty());
    cout << ff(--r,--c,'0','.') << "\n";

  }
  return 0;
}