#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <string>

template <typename T>
void print_vector(std::vector<T> v, std::string text="Vector:") {
    std::cout<<text<<std::endl;
    for(auto& i : v) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

template <typename T>
void print_list(std::list<T>l, std::string text="List:") {
    std::cout<<text<<std::endl;
    for(auto& i : l) {
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
}

template <typename T>
void print_set(std::set<T>s, std::string text="Set:") {
    std::cout<<text<<std::endl;
    for (auto& i : s) {
        std::cout<< i <<" ";
    }
    std::cout<<std::endl;
}