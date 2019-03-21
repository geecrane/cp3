#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<(int)b;++i)

struct P{int x, y;};
class UnionFind {                                              // OOP style
private:
  vector<int> p, rank;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
      int x = findSet(i), y = findSet(j);
      // rank is used to keep the tree short
      if (rank[x] > rank[y]) { p[y] = x; }
      else                   { p[x] = y; 
                               if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
};

double dist(P &a, P &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
int main(){
  ios_base::sync_with_stdio(false);
  int R, N, T; cin>>T;
  vector<tuple<double,int,int>> edges; edges.reserve(1e6);
  vector<P> cities; cities.reserve(1000);
  REP(t,1,T+1){
    cin>>N>>R;
    cities.clear();
    REP(i,0,N) {int x, y; cin>>x>>y; cities.push_back({x,y});}
    
    edges.clear();
    REP(i,0,N)REP(j,i+1,N) edges.emplace_back(dist(cities[i], cities[j]),i,j);
    sort(edges.begin(), edges.end());

    double roads=0,rails=0;
    int num_taken=0, nstates=1;    
    UnionFind UF(N);
    REP(i,0,edges.size()){ 
      double w; int u, v; tie(w, u, v) = edges[i];
      if (!UF.isSameSet(u, v)) {
        num_taken++;
        if(w<=R)roads += w;
        else rails += w, nstates++;
        UF.unionSet(u, v);
      }
      if(num_taken == N-1) break;}

    cout<<"Case #"<<t<<": "<<nstates<<" "<<(int)(roads+0.5)<<" "<<(int)(rails+0.5)<<"\n";
  }
  return 0;
}