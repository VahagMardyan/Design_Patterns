#include <iostream>
#include <cstdint>

int main() {
    uint64_t m_n = 1; // 000000000000000000000000000..001

    double* min_double = reinterpret_cast<double*>(&m_n); // 2^(-1074)

    std::cout<<"The smallest double: "<<*min_double<<std::endl;
    return 0;
}