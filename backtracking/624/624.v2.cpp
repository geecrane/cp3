#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> best_tracks;
std::vector<int> temp_tracks;
std::vector<int> total_tracks;
int min_left; 
int tape_size;

void print(){
    for(int el : best_tracks) std::cout << el << " ";

    int sum = std::accumulate(best_tracks.begin(), best_tracks.end(), 0);
    std::cout << "sum:" << sum << std::endl;
}
void filltape(size_t ind, int time_left){
    if(time_left < 0 ) return; //prune and base
    if(time_left < min_left){
        min_left = time_left;
        best_tracks = temp_tracks;
    }
    if(ind == total_tracks.size()) return;

    filltape(ind+1, time_left); //exclude;

    //include
    temp_tracks.push_back(total_tracks.at(ind));
    filltape(ind + 1, time_left - total_tracks.at(ind));
    temp_tracks.pop_back();//back track
}
void testcase(){
    best_tracks.clear();
    temp_tracks.clear();
    total_tracks.clear();

    int tracks; std::cin >> tracks;
    for(int i = 0; i < tracks; ++i){
        int t; std::cin >> t;
        total_tracks.push_back(t);
    }

    min_left = tape_size;
    filltape(0, tape_size);
    print();
}
int main() {
    
    while(std::cin >> tape_size) testcase();
    return 0;
}
