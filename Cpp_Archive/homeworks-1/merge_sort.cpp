#include <iostream>
#include <vector>
#include "mergesort.h"

bool foo(int a, int b) {
    return a > b; // descending sort
}

int main() {
    std::vector<int>x = {1,2,3,0,8,9};
    int n = x.size();
    merge_sort(x, 0, n-1);
    for(size_t i=0;i<n;i++) {
        std::cout<<x[i]<<" ";
    }
    std::cout<<'\n';
    return 0;
}