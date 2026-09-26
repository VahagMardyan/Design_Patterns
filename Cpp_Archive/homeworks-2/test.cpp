#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <algorithm>
#include <string>
#include "../homeworks-1/mergesort.h"
#include "printers.h"

/* 
Գրել std::sort-ի համար ֆունկցիա որը կսորտավորի սենց
1․ Զանգվածի առաջին կեսը զույգերը՝ մեծից փոքր
2․ Զանգվածի մյուս կեսը կենտերը՝ փոքրից մեծ
*/

int cnt = 0; // shows the amount of std::sort comparisons.
bool func(int a, int b) {
    cnt++;
    if( ( a >=0 && a % 2 == 0) && ( b >=0 && b % 2 == 0)) {
        return a > b;
    }
    if(a % 2 == 1 && b % 2 == 1) {
        return a < b;
    }
    return ( a >= 0 && a % 2 == 0);
}

// // STL -> Standart Template Library
int main() {
    std::vector<int> v2 {10, 2, 7, 6, 26, 34, 45, 72, 63};
    std::set<int> s2 {10, 2, 7, 9};
    std::list<int> l2 {10, 2, 7, 898};

    print_list(l2);

    s2.insert(-5);

    print_set(s2);
    
    std::sort(v2.begin() , v2.begin() + v2.size()/2); // half-sort
    print_vector(v2, "Half sorted v2:");

    std::sort(v2.rbegin() , v2.rend()); // reverse-sort
    print_vector(v2, "Reverse sorted v2:");
    
    std::sort(v2.begin(), v2.end(), func); // full-sort
    print_vector(v2, "Sorted v2 by function logic: Evens by descending order, Odds by ascending order");

    int m_cnt = 0;
    merge_sort(v2, 0, v2.size()-1, [&m_cnt](int a, int b){
        m_cnt++; // shows the amount of merge sort comparisons.
        return a > b;
    }); // lambda function
    print_vector(v2, "Descending merge sort:");
    std::cout<<"m_cnt: "<<m_cnt<<std::endl;// 19
    std::cout<<"Count: "<<cnt<<std::endl; // 31
    return 0;
}