#include <iostream>
#include <cstdint>
// #include <bitset>

int main() {
    uint64_t exponent = 2046ull << 52; 
    uint64_t mantissa = (1ull << 52) -1; 
    uint64_t m_x = exponent | mantissa;

    double* max_double = reinterpret_cast<double*>(&m_x);
    std::cout<<"The largest double: "<<*max_double<<std::endl;
    return 0;
}

/*
    // 2046ull = 000000000...011111111110 (53 pcs 0 + 11 bits) 
    exponent -> // 0111111111100000..00
    // 1ull = 0000000000000000000000..01
    // 1ull << 52 = 00000000000100000000...00
    // (1ull << 52) - 1 = 000000000000111...11 -> Mantissa

    // std::bitset<64> e(exponent);
    // std::cout<< "Exponent: " <<e<<std::endl; // 0111111111100000000000000000000000000000000000000000000000000000
    // std::bitset<64> m(mantissa);
    // std::cout<< "Mantissa: " <<m<<std::endl; // 0000000000001111111111111111111111111111111111111111111111111111

    // std::bitset<64> NUMBER(m_x); 
    // std::cout<< "Number:   " <<NUMBER<<std::endl; // 0111111111101111111111111111111111111111111111111111111111111111
*/