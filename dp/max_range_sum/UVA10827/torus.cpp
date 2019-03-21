#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
#define REP(i, a, b) for(int i=(int)a; i<(int)b; i++)


void testcase(){
  int N; cin >> N;
  VVI M(N, VI(2*N));
  REP(i, 0, N)REP(j, 0, 2*N){
    if(j < N) {
      cin >> M[i][j]; 
      M[i][j+N] = M[i][j];
    }
    if(j > 0) M[i][j] += M[i][j-1];
  }

  int maxmaxsum(-100);
  REP(col1, 0, 2*N){
    REP(col2, col1, min(col1+N, 2*N)){
      int maxsum(-100), minsum(-100), total(0), summin(0), summax(0);
      REP(row, 0, N){
        int value = M[row][col2];
        if(col1 > 0) value -= M[row][col1-1];
        total += value;
        summax += value;
        summin -= value;
        maxsum = max(maxsum, summax);
        minsum = max(minsum, summin);
        if(summax < 0) summax = 0;
        if(summin < 0) summin = 0;
        
      }
      total += minsum; //>= 0;
      if(total) maxsum = max(maxsum, total);
      maxmaxsum = max(maxmaxsum, maxsum);
    }
  }

  cout << maxmaxsum << "\n";
}
int main(){
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  while(t--)testcase();
  return 0;
}