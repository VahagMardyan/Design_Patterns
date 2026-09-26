#include <iostream>

// // virtual function's logic without using "virtual" keyword

class Base {
    public:
        void (*fooPtr)(Base*, int); // VirtualTable
        const void* typePtr;
        static const int typeMarker;

        Base() {
            fooPtr = &Base::fooImpl;
            typePtr = &typeMarker;
        }
        static void fooImpl(Base* self, int x) {
            std::cout<<"Base: "<<x<<std::endl;
        }
        void foo(int x = 20) {
            fooPtr(this, x);
        }
};

const int Base::typeMarker = 0;

class D : public Base {
    public:
        static const int typeMarker;
        D() {
            fooPtr = &D::fooImpl;
            typePtr = &typeMarker;
        }
        static void fooImpl(Base* self, int x) {
            std::cout<<"Derived: "<<x<<std::endl;
        }
        void foo(int x = 100) {
            fooPtr(this, x);
        }
};
const int D::typeMarker = 0;

class D1 : public Base {
    public:
        static const int typeMarker;
        D1() {
            fooPtr = &D1::fooImpl;
            typePtr = &typeMarker;
        }
        static void fooImpl(Base* self, int x) {
            std::cout<<"Derived1: "<<x<<std::endl;
        }
        void foo(int x = 456) {
            fooPtr(this, x);
        }
};
const int D1::typeMarker = 0;

template <typename T>
T* dynamicCast(Base* obj, const void* expectedType) {
    if(obj->typePtr == expectedType) {
        return reinterpret_cast<T*>(obj);
    }
    return nullptr;
}

#define dynamic_cast_D(ptr) dynamicCast<D>(ptr, &D::typeMarker)
#define dynamic_cast_D1(ptr) dynamicCast<D1>(ptr, &D1::typeMarker)

int main() {
    Base *obj = new D();
    obj -> foo(); // Derived, 20
    
    D *ptr = new D();
    ptr->foo(); // Derived 100
    
    // // using cast, but this is unsafe
    Base *b = new D();
    ((D*)b)->foo(); // Derived 100

    Base *base = new Base();
    base->foo(); // Base 20

    Base *d1 = new D1();
    d1->foo(); // Derived1 20

    // // cast is UNSAFE
    Base *d11 = new D1();
    ((D1*)d11)->foo(); // Derived1 456

    Base* b1 = new D();
    Base* b2 = new D1();
    Base* b3 = new Base();

    // safe downcast
    if(auto p = dynamic_cast_D(b1)) {
        p->foo(); // Derived: 100
    }

    // wrong type -> nullptr
    if(auto p = dynamic_cast_D(b2)) {
        std::cout<<"Should not print"<<std::endl;
    } else {
        std::cout<<"dynamic_cast_D(b2)=nullptr (safe)"<<std::endl;
    }

    // cast to D1
    if(auto p = dynamic_cast_D1(b2)) {
        p->foo(); // Derived1: 456
    }

    // base object -> cast fails
    if(!dynamic_cast_D(b3)) {
        std::cout << "Cannot cast Base to D (correct)"<<std::endl;
    }

    return 0;
}

/*
Սկզբում fooPtr-ը ցույց է տալիս բազային class-ի fooImpl-ի վրա, ինչպես virtual-ում։
Հետո Ժառանգի constructor-ը փոխումա իրա fooImpl-ի վրա: Նույն բանը մյուս ժառանգնա անում

typePtr -> պահում է օբյեկտի իրական տիպի ցուցիչը։ Յուրաքանչյուր ժառանգի կոնստրուկտորում այն փոխվում է
typeMarker -> հանդիսանում է տվյալ class-ի յուրահատուկ ID
typePtr-ը ցույց է տալիս typeMarker-ի վրա
*/