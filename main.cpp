//extra credit for cop 3530
//hashmaps vs treemaps

#include <iostream>
#include <map>
#include <unordered_map>
#include <stdlib.h>
#include <chrono>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
 ok so from what i understand here's what needs to happen:
 i have two data structures: map and unordered map
 for each ds i need to execute three operations: insert, search, and delete
 each operation needs to be executed 1k then 100k times
 then i need to plot graphs but that's a problem for later
 */

map<int, int> tree;
unordered_map<int, int> hashy;
map<string, std::chrono::high_resolution_clock> times;

void maps(int tests){
    int x;
    string title;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i=0; i<tests; i++){
        x = rand();
        tree.insert(make_pair(x, x));
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start ).count();
    title = to_string(tests) + " MAP.INSERT ";
    cout << title << ": " << duration << endl;

    start = std::chrono::high_resolution_clock::now();
    for (int i=0; i<tests; i++){
        x = rand();
        tree.find(x);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start ).count();
    title = to_string(tests) + " MAP.FIND ";
    cout << title << ": " << duration << endl;

    start = std::chrono::high_resolution_clock::now();
    for (int i=0; i<tests; i++){
        x = rand();
        tree.erase(x);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start ).count();
    title = to_string(tests) + " MAP.ERASE ";
    cout << title << ": " << duration << endl;

    start = std::chrono::high_resolution_clock::now();
    for (int i=0; i<tests; i++){
        x = rand();
        hashy.insert(make_pair(x, x));
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start ).count();
    title = to_string(tests) + " UNORDERED_MAP.INSERT ";
    cout << title << ": " << duration << endl;

    start = std::chrono::high_resolution_clock::now();
    for (int i=0; i<tests; i++){
        x = rand();
        hashy.find(x);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start ).count();
    title = to_string(tests) + " UNORDERED_MAP.FIND ";
    cout << title << ": " << duration << endl;

    start = std::chrono::high_resolution_clock::now();
    for (int i=0; i<tests; i++){
        x = rand();
        hashy.erase(x);
    }
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start ).count();
    title = to_string(tests) + " UNORDERED_MAP.ERASE ";
    cout << title << ": " << duration << endl;


    cout << endl << "success for " << tests << " test cases" << endl << endl;

}

int main() {


    maps(1000);
    maps(100000);


    return 0;
}
