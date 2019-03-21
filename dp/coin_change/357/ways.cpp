#include <bits/stdc++.h>
using namespace std;
typedef vector<long> vi;
typedef vector<vi> vii;

vi coin = {1, 5, 10, 25, 50};
vii memo(5, vi(30001, -1));

long ways(int type, int value){
  if(value == 0) return 1;
  if(type == 5 || value < 0) return 0;
  long &res = memo[type][value];
  if(res > -1) return res;
  return res = ways(type+1, value) + ways(type, value-coin[type]);
}

int main(){
  ios_base::sync_with_stdio(false);
  int n;
  while(cin>>n){
    long w = ways(0,n);
    if(w == 1)  cout << "There is only 1 way ";
    else cout << "There are " << w << " ways ";
    cout << "to produce " << n << " cents change.\n";
  }
  return 0;
}