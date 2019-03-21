#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cmath>
#include <utility>
#include <string>

const int INT_MAX = std::numeric_limits<int>::max();

std::vector< std::vector<int> > dpTable;
std::vector< std::vector<int> > wind;
std::vector<int> cruise = {20, 30, 60};
int dist;

int fuel(int level, int pos){

    if(level < 0 || level > 9) return INT_MAX;
    if(level + pos > dist) return INT_MAX; // prune(cannot land in time)
    if(pos == dist) return 0; //landed
    
    //memo
    if( dpTable.at(level).at(pos) != -1) return dpTable.at(level).at(pos);
    

    int minfuel = INT_MAX;
    for(unsigned i = 0; i < cruise.size(); ++i){
        int f = fuel(level + i - 1, pos + 1);
        if(f < INT_MAX)
            minfuel = std::min(minfuel, f + cruise.at(i) - wind.at(level).at(pos));
    }

    dpTable.at(level).at(pos) = minfuel;
    return minfuel; 
}

void testcase(){
    wind.clear(); wind.resize(10);
    dpTable.clear(); dpTable.resize(10, std::vector<int>(dist + 1, -1));
    for(int i = 9; i >= 0; --i){
        std::vector<int> tmp(dist);
        for(unsigned j = 0; j < tmp.size(); ++j) std::cin >> tmp.at(j);
        wind.at(i) = tmp;
    }
   
    std::cout <<  fuel(0, 0) << "\n\n";
}


int main(){
    int T; std::cin >> T; 
    for(int i = 0; i < T; ++i){
        std::cin.ignore();
        std::string ss; std::getline(std::cin, ss);
        while(ss.empty()) std::getline(std::cin, ss);

        dist = std::stoi(ss);
        dist /= 100;
        testcase();
        std::cin.ignore();
    }
        return 0;
}
