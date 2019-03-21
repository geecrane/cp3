#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>
const int INT_MAX = std::numeric_limits<int>::max();
std::vector< std::vector<int> > wind(10);
std::vector<int> cruise = {20, 30, 60};
int dist;
int fuel(int pos, int level){

    if(level < 0 || level > 9) return INT_MAX;
    if(level > pos && pos >= 0) return INT_MAX;
    if(level > 0 && pos <= 0) return INT_MAX;

    if(pos < 0 && level == 0) return 0;
    

    int minfuel = INT_MAX;
    for(unsigned i = 0; i < cruise.size(); ++i){
        int f = fuel(pos - 1, level + i - 1);
        if(f < INT_MAX) 
            minfuel = std::min(minfuel, f + cruise.at(i) - wind.at(level).at(pos));
    }
    return minfuel; 
}

int main(){
     std::cin >> dist;
    dist /= 100;
    
    for(int i = 9; i >= 0; --i){
        std::vector<int> tmp(dist);
        for(unsigned j = 0; j < tmp.size(); ++j) std::cin >> tmp.at(j);
        wind.at(i) = tmp;
    }
   
    std::cout << "res: " << fuel(dist - 1, 0) << std::endl;
    return 0;
}
