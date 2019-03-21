#include <bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define sz(a) (int)(a.size())
#define pb push_back

struct node{int i;char c;};
typedef vector<int> vi;
typedef vector<vector<node>> vvn;

vector<node> top; 
vector<char> i2c; 
vvn adj;
vi vis,in; 
int c,f;

void bt(){
  if(sz(top)==c){
    REP(i,0,c)cout<<(i?" ":"")<<top[i].c;
    cout<<"\n";f=1;return;
  }
  REP(i,0,c)if(!vis[i]&&!in[i]){
    vis[i]=1;top.pb({i,i2c[i]});
    REP(j,0,sz(adj[i]))in[adj[i][j].i]--;
    bt();
    vis[i]=0;top.pop_back();
    REP(j,0,sz(adj[i]))in[adj[i][j].i]++;
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  int T; cin>>T;
  string s; cin>>s;
  REP(t,0,T){
    map<char,int> c2i;
    c=f=0;i2c.clear();
    do{i2c.pb(s[0]);c2i[s[0]]=c++;}while(cin>>s&&sz(s)==1);

    adj=vvn(c); in=vis=vi(c); f=0;
    do{
      char u=s[0], v=s[2];
      adj[c2i[u]].pb({c2i[v], v});
      in[c2i[v]]++;
    }while(cin>>s&&sz(s)==3);

    if(t)cout<<"\n";
    bt();
    if(!f)cout<<"NO\n";
  }
  return 0;
}