#include <iostream>

class Singleton {
    private:
        Singleton() {
            std::cout << "Singleton instance created: " << std::endl;
        }
        ~Singleton() = default;
    
    public:
        Singleton(const Singleton&) = delete;
        Singleton &operator=(const Singleton&) = delete;

        static Singleton& getInstance() {
            static Singleton instance;
            return instance;
        }
        void sayHi() {
            std::cout << "Hi!" << std::endl;
        }
};

int main() {
    Singleton& s1 = Singleton::getInstance();
    s1.sayHi();

    Singleton& s2 = Singleton::getInstance();
    std::cout << &s1 << " " << &s2 << std::endl;
    return 0;
}

