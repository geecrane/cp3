#include <bits/stdc++.h>
using namespace std;
int S,D,mx,m[12];

void bt(int p){
  if(p>=5&&accumulate(m+p-5,m+p,0)>=0) return;
  if(p==12){mx=max(mx,accumulate(m,m+12,0)); return;} 
  m[p]=S; bt(p+1);
  m[p]=-D; bt(p+1);
}

int main(){
  ios_base::sync_with_stdio(false); 
  while(cin>>S>>D){
    mx=0; bt(0);
    if(mx>0) cout<<mx<<"\n";
    else cout<<"Deficit\n"; 
  }
  return 0;
}