#include <iostream>
#include <vector>
#include <numeric>
int n, m;
std::vector<int> c;

bool simulate(int max){
    int cc = 0;
    int cv = 0;
    while(cc < m && cv < n){
        int cm = max;
        while(cv < n && cm >= c.at(cv)) cm -= c.at(cv++);
        cc++;
    }
    return (cv == n);
}
void bsearch(){
   int t = std::accumulate(c.begin(), c.end(), 0); 
   int lo = 0, hi = t, ans;
   while(lo <= hi){
       int mid = (lo + hi)/2;
       if(simulate(mid)){
           hi = mid - 1;
           ans = mid;
       }else 
           lo = mid + 1;
   }
   std::cout << ans << std::endl;
}

void testcase(){
    std::cin >> m;
    c.clear(); c.resize(n);
    for(int i = 0; i < n; ++i) std::cin >> c.at(i);
    bsearch();
}

int main(){
    while(std::cin >> n){testcase();}
    return 0;
}
