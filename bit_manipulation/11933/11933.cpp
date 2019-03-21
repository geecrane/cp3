#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int N, count, a;
  while(cin >> N && N != 0){
    count = a = 0;
    for(int i = 0; i < 31; i++)
      if(N & 1 << i && ++count % 2) a |= 1 << i;
    cout << a << " " << (N^a) << "\n";
  }
}