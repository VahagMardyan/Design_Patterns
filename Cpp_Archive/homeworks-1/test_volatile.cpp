#include <iostream>
#include <chrono>

/*  Compile and run using
    g++ -O0 -std=c++17 test_volatile.cpp -o test_volatile.exe && ./test_volatile.exe
*/

int main() {
    volatile int x = 0;
    auto start = std::chrono::high_resolution_clock::now();
    while(x<=1000000000) {
        x+=1;
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout<<"x: "<<x<<std::endl;
    std::cout<<"Time (with volatile): "<<duration.count()<<"microseconds"<<std::endl; // 685570 microseconds

    int y = 0;
    auto start1 = std::chrono::high_resolution_clock::now();
    while(y<=1000000000) {
        y+=1;
    }
    auto end1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
    std::cout<<"y: "<<y<<std::endl;
    std::cout<<"Time (without volatile): "<<duration1.count()<<"microseconds"<<std::endl; // ≈567431 microseconds
    
    return 0;
}