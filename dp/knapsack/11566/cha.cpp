#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> foodPrice, foodFavor;
vector<vector<vector<int>>> DP;
int favor(int i, int w, int c){
  if(w==0 || i == K) return 0;

  int &res = DP[i][w][c];
  if(res != -1) return res;

  int f1 = favor(i+1, w, c);
  
  int f2 = 0;
  if(w >= foodPrice[i] && c <= 2*(N+1)-1) f2 = favor(i+1, w-foodPrice[i], c+1) + foodFavor[i];

  int f3 = 0;
  if(w >= 2*foodPrice[i] && c <= 2*(N+1)-2) f3 = favor(i+1, w-2*foodPrice[i], c+2) + 2*foodFavor[i];

  // cout << "f1: " << f1 << " f2: " << f2 << " f3: " << f3 << endl;
  
  res = max(f1, f2);
  res = max(res, f3);
  return res;
}

void testcase(){
  int X, T;  cin >> X >> T >> K;
  
  int foodBudget =  (N+1)*(X/1.1 + 1e-6 - T);
  foodBudget = max(0, foodBudget);
  
  DP.clear(); DP.resize(K, vector<vector<int>>(foodBudget+1, vector<int>(2*(N+1) + 1, -1)));

  foodPrice.clear(); foodPrice.resize(K);
  foodFavor.clear(); foodFavor.resize(K);
  for(int i = 0; i < K; ++i){
    cin >> foodPrice[i];
    for(int j = 0; j < N+1; ++j){
      int f; cin >> f;
      foodFavor[i] += f;
    }
  }
  // cout << "food price : " <<  foodPrice[0]  << endl;
  double res = favor(0, foodBudget, 0);
  res = res /(N+1);
  cout << res << "\n";

}

int main(){
  ios_base::sync_with_stdio(false); 
  cout << setiosflags(ios::fixed) << setprecision(2);
  while(cin >> N && N != 0) testcase();
  return 0;
}