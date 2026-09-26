#include <iostream>
#include <cstdint>

struct Max {
    union {
        uint64_t m_x;
        double number;
    };
    Max() {
        uint64_t exponent = 2046ull << 52;
        uint64_t mantissa = (1ull << 52) - 1;
        m_x = mantissa | exponent;
    }
};

int main() {
    Max max_double;
    std::cout << "Max double: " << max_double.number << std::endl;
    return 0;
}