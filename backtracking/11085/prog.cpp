#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define REP(i,n) for(int i=0;i<(int)n;++i)

int ok = (1<<8)-1;
map<int, int> d;
vvi s;
vi v;

void bt(int rw, int ld, int rd){
  if(rw==ok){s.push_back(v); return;}
  int pos=ok&~(rw|ld|rd);
  while(pos){
    int p=pos&-pos;
    pos-=p;
    v.push_back(d[p]+1);
    bt(rw|p,(ld|p)<<1,(rd|p)>>1);
    v.pop_back();
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  REP(i,9) d[1<<i] = i;
  bt(0,0,0);
  
  vi q(8); int ans, c=0;
  while(c++,ans=8,cin>>q[0]){
    REP(i,7)cin>>q[i+1];
    REP(i,s.size()){
      int sum=8;
      REP(j,8)sum-=(s[i][j]==q[j]);
      ans=min(ans,sum);
    }
    cout<<"Case "<<c<<": "<<ans<<"\n";
  }
  return 0;
}