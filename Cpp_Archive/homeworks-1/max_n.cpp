#include <iostream>
#include <cstdint>
#include <bitset>
#include <variant>

union FloatToBits {
    float f;
    uint32_t u;
};

union DoubleToBits {
    double d;
    uint64_t u;  
};

union IntToBits {
    int i;
    uint32_t u;
};

void printFloatBits(float f_val) {
    FloatToBits converter;
    converter.f = f_val;
    std::cout<<"Float: "<<f_val<<std::endl;
    std::cout<<"Bits: "<<std::bitset<32>(converter.u)<<std::endl;
}

void printDoubleBits(double d_val) {
    DoubleToBits converter;
    converter.d = d_val;
    std::cout<<"Double: "<<d_val<<std::endl;
    std::cout<<"Bits: "<<std::bitset<32>(converter.u)<<std::endl;
}

void printIntBits(int i_val) {
    IntToBits converter;
    converter.i = i_val;
    std::cout<<"Int: "<<i_val<<std::endl;
    std::cout<<"Bits: "<<std::bitset<32>(converter.u)<<std::endl;
}

int main() {
    FloatToBits fb;
    fb.f = 1.0f;

    while(true) {
        FloatToBits next;
        next.u = fb.u + 1;
        float diff = next.f - fb.f;
        if(diff > 1.0f) {
            std::cout<<"Float: "<<fb.f<<std::endl; // // 2^24
            break;
        }
        fb.f *= 2;
    }

    DoubleToBits db;
    db.d = 1.0;
    while(true) {
        DoubleToBits next;
        next.u = db.u + 1;
        double diff = next.d - db.d;
        if(diff > 1.0) {
            std::cout<<"Double: "<<db.d<<std::endl; // // 2^53
            break;
        }
        db.d *= 2;
    }
    return 0;
}