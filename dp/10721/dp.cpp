#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(int)a;i<(int)b;++i)

long a[51][51];
int main(){
  int m,n,k;
  while(scanf("%d%d%d",&n,&k,&m)!=EOF){
    memset(a,0,sizeof(a));
    a[0][0]=1;
    REP(i,1,k+1)REP(j,i,n+1)REP(k,1,min(j,m)+1) a[j][i]+=a[j-k][i-1];
    printf("%ld\n",a[n][k]);
  } 
  return 0;
}