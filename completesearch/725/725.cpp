#include <bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  int N; cin >> N;

  while(true){
    bool found = false;
    for(int fghij = 1234; fghij <= 98765/N; fghij++)
    {
      int abcde = N * fghij;
      int used = (fghij < 10000);
      for(int tmp = abcde; tmp!=0; tmp/=10) used |= 1 << (tmp%10);
      for(int tmp = fghij; tmp!=0; tmp/=10) used |= 1 << (tmp%10);
      if(used == (1<<10) - 1 && (found=true))
        cout << abcde << " / " << setw(5) << setfill('0') << fghij << " = " << N << "\n";
    }
    if(!found) cout << "There are no solutions for " << N << ".\n"; 
    
    if(cin >> N && N != 0)  cout << "\n";
    else break;
  }
  return 0;
}