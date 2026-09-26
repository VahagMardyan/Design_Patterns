#include <iostream>
#include <vector>

class Base {
    public:
        Base() {}
        virtual ~Base() {}
        virtual void foo(int t=20) {
            std::cout<<t<<std::endl;
        }
};

class D : public Base {
    public:
        virtual void foo(int t=100) {
            std::cout<<t<<std::endl;
        }
};

int main() {
    Base *obj = new D();
    obj -> foo(); // 20, even when default value of t for D is 100.
    
    D *ptr = new D();
    ptr->foo(); // 100
    
    // using cast, but this is unsafe
    Base *b = new D();
    ((D*)b)->foo(); // 100

    Base* base = new Base();
    base->foo(); // 20

    std::vector<Base> v; // -> copy/paste std::vector class for "Base" type
    std::vector<double> d; // -> copy/paste std::vector class for "double" type

    return 0;
}