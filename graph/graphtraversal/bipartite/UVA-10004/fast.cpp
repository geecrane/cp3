#include <bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  int N,L,U,V;
  while(cin>>N&&N){
    cin>>L;
    for(int i=0;i<L;++i)cin>>U>>V;
    if(N>L||(N==L&&N%2==0)) cout<<"BICOLORABLE.\n";
    else cout<<"NOT BICOLORABLE.\n";}
  return 0;
}