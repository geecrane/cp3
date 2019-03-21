#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
std::map<char, std::vector<int> > states;

void doquery(std::string& query){
    int a, b;
    a = b = -1;
    int smallest = 0;
    for(unsigned i = 0; i < query.size(); ++i){
        auto it = std::lower_bound(states[query[i]].begin(),states[query[i]].end(), smallest);
        if(it == states[query[i]].end()) break;
        if(a < 0) a = *it;
        if(i == query.size() - 1) b = *it;
        smallest = *it + 1;
    }

    if(a < 0 || b < 0) std::cout << "Not matched" << "\n";
    else std::cout << "Matched " << a << " " << b << "\n";
}

void testcase(){
    std::string S; std::getline(std::cin, S);
    for(unsigned i = 0; i < S.size(); ++i) states[S[i]].push_back(i);

    unsigned Q; std::cin >> Q; std::cin.ignore();
    
    std::string pattern;
    while(std::getline(std::cin, pattern)) doquery(pattern);
}

int main(){
    testcase();
    return 0;
}
