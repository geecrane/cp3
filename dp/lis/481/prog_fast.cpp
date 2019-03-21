#include <bits/stdc++.h>
using namespace std;
//Longest Increasing Subsequence
//Output-sensitive algorithm nlogk

#define MAX         1000000
#define all(a)      a.begin(), a.end()
#define pb          push_back
#define rs          reserve
#define sz(a)       ((int)(a.size()))
#define lb          lower_bound        

typedef vector<int> VI;

void print(int end, VI &P, VI &A){
  if(end < 0) return;
  print(P[end], P, A);
  cout << A[end] << "\n";
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  VI A, M, M_id, P;
  A.rs(MAX); M.rs(MAX); M_id.rs(MAX); P.rs(MAX);

  int L_end = 0, v;
  for(int i = 0; (cin >> v); i++){
    A.pb(v);
    int pos = lb(all(M), A[i]) - M.begin(); 
    if(pos == sz(M)) M.pb(A[i]), L_end = i;
    else M[pos] =  A[i];
    M_id[pos] = i;  
    if(pos > 0) P.pb(M_id[pos-1]);
    else P.pb(-1); 
  }

  cout << sz(M) << "\n-\n";
  print(L_end, P, A);

  return 0;
}