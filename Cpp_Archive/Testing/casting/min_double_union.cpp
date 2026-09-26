#include <iostream>
#include <cstdint>

struct Min {
    union {
        uint64_t m_n = 1;
        double number;
    };
};

int main() {
    Min min_number;
    std::cout << "The smallest double: " << min_number.number << std::endl;
    return 0;
}