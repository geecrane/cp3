#include <bits/stdc++.h>

long dp[30001] = {0};
int c[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};

int main(){
  dp[0]=1;
  for(int i=0;i<11;i++)for(int v=c[i];v<30001;v++)
    dp[v]+=dp[v-c[i]];

  float n;
  while(scanf("%f",&n)&&n)
    printf("%6.2f%17ld\n", n, dp[(int)(n*100+0.5)] );

  return 0;
}


