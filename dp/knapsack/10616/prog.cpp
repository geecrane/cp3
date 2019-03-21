#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

vi A(201);
vvvi memo;
int N, D, M, Q, sets = 1;

int count(int i, int m, int sum){
  if(m==0) return !(sum);
  if(i < 0) return 0;
  int &res = memo[i][m][sum];
  if(res > -1) return res;
  return res = count(i-1,m-1,((sum+A[i]%D)%D+D)%D) + count(i-1,m,sum);
}
int main(){
  cout << -5 % 2 << endl;
  return 0;
  while(scanf("%d %d", &N, &Q) && N && Q){
    printf("SET %d:\n", sets++);
    for(int i = 0; i < N && scanf("%d", &A[i]); i++);
    for(int i = 0; i < Q && scanf("%d %d", &D, &M); i++){
      memo = vvvi(N, vvi(M+1, vi(D, -1)));
      printf("QUERY %d: %d\n", i+1, count(N-1,M,0));
    } 
    
  }
  return 0;
}