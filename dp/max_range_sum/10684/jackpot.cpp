#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  int N, m, s, a;
  while (cin >> N && N != 0)
  {
    m = s = 0;
    while (N-- && cin >> a)
    { 
      s += a;
      if (s > m) m = s;
      if (s < 0) s = 0;
    }
    if (m > 0) cout << "The maximum winning streak is " << m << ".\n";
    else cout << "Losing streak.\n";
  }
  return 0;
}