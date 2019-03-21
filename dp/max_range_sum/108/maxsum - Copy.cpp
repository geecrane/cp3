#include <bits/stdc++.h>

using namespace std;

void testcase(int N){
  vector<vector<int>> M(N, vector<int>(N));
  for(int i = 0; i < N; ++i) for(int j=0; j < N; ++j) cin >> M[i][j];

  
  // cout << "Input Matrix\n";
  // for(auto r : M){for(auto e: r){ cout << e << " ";} cout<<endl;}
  // cout << "##########################################################" << endl;

  vector<vector<int>> P(N, vector<int>(N));
  for(int i = 0; i < N; ++i){
    for(int j=0; j < N; ++j){
      P[i][j] = M[i][j];
      if(j > 0) P[i][j] += P[i][j-1];
      if(i > 0) P[i][j] += P[i-1][j];
      if(i > 0 && j > 0) P[i][j] -= P[i-1][j-1];
    }
  }

  // cout << "PartialSum Matrix\n";
  // for(auto r : P){for(auto e: r){ cout << e << " ";} cout<<endl;}
  // cout << "##########################################################" << endl;
  

  int maxsum = INT_MIN;
  for(int i = 0; i < N; ++i){
    for(int j=0; j < N; ++j){
      for(int k = i; k < N; ++k){
        for(int l = j; l < N; ++l){
          int sum = P[k][l];
          if(j>0) sum -= P[k][j-1];
          if(i>0) sum -= P[i-1][l];
          if(i>0 && j > 0) sum += P[i-1][j-1];
          //cout << "Sum[" << i << "," << j << "][" << k << ", " << l << "] = " << sum << endl;
          maxsum = max(maxsum, sum);
        }
      } 
    }
  }
  // cout << "***************************************************************************************" << endl;
  // return;
  cout << maxsum << "\n";

}

int main(){
  ios_base::sync_with_stdio(false);
  int N; 
  while(cin >> N) testcase(N);
  return 0;
}