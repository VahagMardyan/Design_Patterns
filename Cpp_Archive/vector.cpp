#include <iostream>

class vector {
    private:
        int *data;
        size_t size;
        size_t capacity;

        void resize(size_t new_capacity) {
            int *new_data = new int[new_capacity];
            for(size_t i=0; i<size; i++) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }

    public:
        vector(size_t l) : data(new int[l]), capacity(l), size(0) {}
        vector() : data(nullptr), capacity(0), size(0) {}
        ~vector() {
            delete[] data;
        }

        void push_back(const int &el) {
            if(size == capacity) {
                if(capacity == 0) {
                    resize(1);
                } else if(size < 100) {
                    resize(capacity * 2);
                } else {
                    size_t new_cap = size_t(capacity * 1.6);
                    if(new_cap == capacity) new_cap++;
                    resize(new_cap); 
                }
            }
            data[size++] = el;
        }

        void pop_back() {
            if(size > 0) {
                size--;
            }
        }

        int& operator[] (size_t index) {
            if (index >= size) {
                throw std::out_of_range("Index out of range.");
            }
            return data[index];
        }

        const int& operator[] (size_t index) const {
            if (index >= size) {
                throw std::out_of_range("Index out of range.");
            }
            return data[index];
        }

        size_t length() {
            return size;
        }

        void print(size_t len) {
            for(size_t i = 0; i<len; i++) {
                std::cout<<data[i]<<" ";
            }
            std::cout<<"\n";
        }
};

int main() {
    vector v(20);
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    v.print(v.length());
    v.pop_back();

    v.print(v.length());
    return 0;
}