#include <bits/stdc++.h>
using namespace std;
#define REP(i, N) for(int i=0;i<(int)N;++i)
int a, OK, b[15];

void bt(int c, int rw, int ld, int rd) {
  if (rw == OK) {a++; return;}
  int pos = OK&(~(rw|ld|rd))&~b[c];
  while (pos) {
    int p = pos & -pos;
    pos -= p;
    bt(c+1, rw|p, (ld|p)<<1, (rd|p)>>1);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  int N, c = 0; string s;
  while (cin>>N, N){
    REP(r, N){
      cin>>s;
      REP(c,N) b[c] = (s[c]=='*') ? b[c]|(1<<r) : b[c]&~(1<<r);
    }
    a=0, OK=(1<<N)-1;
    bt(0,0,0,0), cout<<"Case "<<++c<<": "<<a<<"\n";
  }
  return 0;
}