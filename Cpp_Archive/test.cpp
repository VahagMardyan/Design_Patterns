/* This is code testing environment, nothing special*/
#include <iostream>
#include <cmath>
#include <limits>

template<class ...Args>
void print(Args&&... args) {
    ((std::cout << args << " "), ...) << std::endl;
}

int global;

int main() {
    const int a = 5;
    int b = 10;
    const int c = a + b;
    constexpr int d = 5;
    constexpr int e = d + 1;
    // print(e);
    enum EyeColor {
        Brown, // 0 
        Blue, // 1
        Green, // 2
        Gray, // 3
        Other // 4
    };
    EyeColor myEyeColor = Green;

    double x = 0.0;
    while(true) {
        double val = std::exp(x);
        if( std::isinf(val) ) {
            std::cout<<x<<std::endl; // 710 
            break;
        }
        x+=1.0;
    }
    int local; // 
    // char *str = "Hello"; // impossible
    const char* str = "Hello"; // possible
    print(&str);
    print(std::exp(709)); // 8.21841e+307
    print(std::exp(710)); // inf
    print(global); // 0
    print(local); // 32766, 32767, ... -> garbage
    int q = 2.5;
    print(q); // 2
    // int k {2.45};
    // print(k); // error: narrowing conversion ...
    
    /* Casts */
    // 1. Static cast
    int r = 10;
    double t = static_cast<double>(r); // int -> double
    print(sizeof(t));

    // 2. Const cast
    const int l = 10;
    int *p = const_cast<int*>(&l);
    *p = 20; // undefined behavior
    *p += 15;

    print(*p); // expected 35

    // 3. Reinterpret cast
    int m = 65;
    char *j = reinterpret_cast<char*>(&m);
    print(*j); // A

    // 4. C-style cast
    double h = (double)m;
    print(sizeof(h), h); // 8 65

    // // print function testing
    print(5, 6, "abs");
    return 0;
}