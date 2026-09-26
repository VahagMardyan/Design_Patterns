#include "inline.h"

void print_1();
void print_2();
void print_3();

void print() {
    get_x() = 151;
    std::cout<<get_x()<<std::endl;
}

void print_x() {
    std::cout<<get_x()<<std::endl;
}

int main() {
    print_1(); // 100
    print_2(); // 200
    print_3(); // 300
    print(); // 151
    get_x() = -1500;
    print_x(); // -1500
    return 0;
}