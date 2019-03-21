#include <iostream>
#include <vector>

std::vector<int> total_tracks;
int best_tracks;
int temp_tracks;
int tape_size;
size_t tracks;
int min_left; 

void print(){
    for(unsigned i = 0; i < tracks; ++i){
       if(best_tracks & (1 << i)) std::cout << total_tracks.at(i) << " ";
    }
    std::cout << "sum:" << tape_size - min_left << std::endl;
}
void filltape(size_t ind, int time_left){
    if(time_left < min_left){
        min_left = time_left;
        best_tracks = temp_tracks;
    }

    for(size_t i = ind; i < tracks; ++i){
        //prune: add track if enough space
        if(time_left - total_tracks.at(i) >= 0){
            temp_tracks |= (1 << i);
            filltape(i + 1, time_left - total_tracks.at(i));
            temp_tracks &= ~(1 << i);//back track
        }
    }
}
void testcase(){
    best_tracks = 0;
    temp_tracks = 0;
    total_tracks.clear();

    std::cin >> tracks;
    for(unsigned i = 0; i < tracks; ++i){
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
