#include <bits/stdc++.h>
using namespace std;
typedef vector<long> vl;
typedef vector<vl> vvl;
vvl memo;
long bc(int n,int k, int m){
  if(n==0&&k==0)return 1;
  if(n<=0||k<=0) return 0;
  long &sum=memo[n][k];
  if(sum>-1)return sum;sum=0;
  for(int i=1;i<=m;++i)sum+=bc(n-i,k-1,m);
  return sum;
}
int main(){
  int m,n,k;
  while(scanf("%d%d%d",&n,&k,&m)!=EOF){
    memo=vvl(n+1,vl(k+1,-1));
    printf("%ld\n",bc(n,k,m));
  } 
  return 0;
}