#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
typedef vector<int> vi;

int main(){
  ios_base::sync_with_stdio(false);
  int INF=2,N,L;
  while(cin>>N&&N){
    vector<vi> g(N); bool bip=1;
    queue<int> q; q.push(0);
    vi col(N,INF); col[0]=1;
    cin>>L;
    REP(l,L){
      int u,v; cin>>u>>v;
      g[u].push_back(v);
      g[v].push_back(u);}
    while(!q.empty()&&bip){
      int u=q.front(); q.pop();
      REP(i,g[u].size()){
        int v=g[u][i];
        if(col[v]==INF){ col[v]=1-col[u]; q.push(v); }
        else if(col[v]==col[u]){bip=0; break;}
      }}   
    if(bip)cout<<"BICOLORABLE.\n";
    else cout<<"NOT BICOLORABLE.\n";
  }
  return 0;
}