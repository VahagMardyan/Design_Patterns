#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <string>

int main() {
    std::vector<int> v2 {10, 2, 7, 6, 26, 34, 45, 72, 63};
    std::set<int> s2 {10, 2, 7, 9};
    std::list<int> l2 {10, 2, 7, 898};

    for (auto& i : v2) {
        std::cout<< i <<" "; // 10 2 7 9
    } 
    std::cout<<std::endl;

    for(auto i = 0; i < v2.size(); ++i) {
        std::cout<<v2[i]<<" "; // O(1)
    }
    std::cout<<std::endl;

    for(auto* ptr = &v2.front(); ptr != &v2.front() + v2.size(); ++ptr) {
        std::cout<<(*ptr)<<" "; // vector
    }
    std::cout<<std::endl;

    for(auto it = v2.begin(); it != v2.end(); ++it) {
        std::cout<<*it<<" "; // vector
    }
    std::cout<<std::endl;

    return 0;
}