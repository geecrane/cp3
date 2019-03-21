#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;++i)

typedef vector<int> vi;
typedef priority_queue<pair<double, int>> pdi;

struct P{int x, y;};
vector<vi> AL;
pdi pq;
vi taken;
vector<P> cities;
double dist(P &a, P &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
void process(int u) { 
  taken[u] = 1;
  for (auto &v : AL[u])
    if (!taken[v])
      pq.push({-dist(cities[u], cities[v]), -v}); 
}  

int main(){
  ios_base::sync_with_stdio(false);
  int R, N, T; cin>>T;
  cities.reserve(1000);
  vi placeholder; placeholder.reserve(1000);
  REP(t,1,T+1){
    cin>>N>>R;
    cities.clear(); AL.assign(N, placeholder);
    REP(i,0,N) {int x, y; cin>>x>>y; cities.push_back({x,y});}
    REP(u,0,N)REP(v,u+1,N){
      AL[u].push_back(v);
      AL[v].push_back(u);}
    
    pq=pdi(); taken=vi(N);
    process(0);

    double w,roads=0,rails=0; int u,nstates=1,num_taken=0;      
    while (!pq.empty() && num_taken < N-1) {
      tie(w, u)=pq.top(); pq.pop();
      w=-w; u=-u;
      if (!taken[u]) {
        num_taken++;
        if(w>R){rails+= w, nstates++;}
        else roads+=w;
        process(u);}}   
    cout<<"Case #"<<t<<": "<<nstates<<" "<<(int)(roads+0.5)<<" "<<(int)(rails+0.5)<<"\n";
  }
  return 0;
}