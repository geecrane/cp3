#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;

int main(){
  ios_base::sync_with_stdio(false);
  

  int v; VI a; a.reserve(1e6); while(cin >> v) a.push_back(v);
  uint n = a.size();

  VI l, lid; l.reserve(n); lid.reserve(n);
  VI p(n, -1); 

  int lis_end = 0; 
  for(uint i = 0; i < n; i++)
  {
    uint pos = lower_bound(l.begin(), l.end(), a[i])-l.begin(); //0 if l.empty() or l[0] >= a[i]
    
    if(pos == l.size()) { //extend
      l.push_back(a[i]); 
      lis_end = i;
    }
    else{
      l[pos] =  a[i];
    } 

    lid[pos] = i;
    if(pos) p[i] = lid[pos-1]; 
  }

  cout << l.size() << "\n-\n";

  //Reconstruct
  stack<int> s;
  while(lis_end > -1){
    s.push(a[lis_end]);
    lis_end = p[lis_end];
  }

  //print
  while(!s.empty()){
    cout << s.top() << "\n";
    s.pop();
  }
  return 0;
}