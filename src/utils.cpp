#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <utils.h>

// Generate a vector containing integers from 0 to x-1
std::vector<int> utils::til(int x){
    std::vector<int> l;
    for (int i=0; i<x; i++){
        l.push_back(i);
    };
    return l;
};

// Generate a vector containing integers from 0 to x-1 and shuffle them
std::vector<int> utils::til_shuffle(int x){
    std::vector<int> l = til(x);

    // Create a random number generator with a seed based on the current time
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 rng(seed);

    // Shuffle the elements using std::shuffle
    std::shuffle(l.begin(), l.end(), rng); 

    return l;
};