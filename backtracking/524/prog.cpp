#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
typedef vector<int> vi;

int pr[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1};
int d[1<<15];
int ok; vi t(1,1);

void bt(int rw){
  int l=t.back();
  if(rw==ok){
    if(!pr[l+1]) return;
    REP(j,t.size()) cout<<((j)?" ":"")<<t[j];
    cout<<"\n";
    return;
  }
  int pos=ok&~rw;
  while(pos){
    int p=pos&-pos;
    pos-=p;
    int n=d[p];
    if(!pr[l+n]) continue;
    t.push_back(n);
    bt(rw|p);
    t.pop_back();
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  REP(i,16)d[1<<i]=i+1;
  int n,c=0;
  while(cin>>n){
    if(c)cout<<"\n";
    cout<<"Case "<<++c<<":\n"; 
    ok=(1<<n)-1, bt(1);
  }
  return 0;
}