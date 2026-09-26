#include <iostream>
#include <cstring>
#include <stdexcept>

class String {
    private:
        static const size_t SSO_CAP=15; // Small String Optimisation Capacity
        size_t size_;
        size_t capacity_;
        bool heap;
        char* data_;
        char small_[SSO_CAP + 1];
        char* data() {
            return heap ? data_ : small_;
        } 
        const char* data() const {
            return heap ? data_ : small_;
        }
        void enable_heap(size_t newcap) {
            char* newdata = new char[newcap];
            std::memcpy(newdata, data(), size_ + 1);
            if(heap) delete[] data_;
            data_ = newdata;
            capacity_ = newcap;
            heap = true;
        }
        void ensure_capacity(size_t newsize) {
            if(!heap && newsize <= SSO_CAP) return;
            if(!heap) {
                enable_heap(newsize + 1);
            } else if(newsize + 1 > capacity_ ) {
                enable_heap((newsize + 1) * 2);
            }
        }

    public:
        
        String() : size_(0), capacity_(SSO_CAP), heap(false), data_(nullptr) {
            small_[0] = '\0';
        }

        String(const char* s) {
            size_ = std::strlen(s);
            if(size_ <= SSO_CAP) {
                heap = false;
                capacity_ = SSO_CAP;
                std::memcpy(small_, s, size_ + 1);
                data_ = nullptr;
            } else {
                heap = true;
                capacity_ = size_ + 1;
                data_ = new char[capacity_];
                std::memcpy(data_, s, size_ + 1);
            }
        }

        // // Copy constructor
        String(const String& other) {
            size_ = other.size_;
            if(!other.heap) {
                heap = false;
                capacity_ = SSO_CAP;
                std::memcpy(small_, other.small_, size_ + 1);
                data_ = nullptr;
            } else {
                heap = true;
                capacity_ = other.capacity_;
                data_ = new char[capacity_];
                std::memcpy(data_, other.data_, size_ + 1);
            }
        }

        // // Move constructor
        String(String&& other) noexcept : size_(other.size_), 
            capacity_(other.capacity_), heap(other.heap), data_(other.data_) {
                if(!other.heap) {
                    std::memcpy(small_, other.small_, size_ + 1);
                    data_ = nullptr;
                }
                other.size_ = 0;
                other.heap = false;
                other.small_[0] = '\0';
                other.data_ = nullptr;
                other.capacity_ = SSO_CAP;
        }

        // // Destructor
        ~String() {
            if(heap) {
                delete[] data_;
            }
        }

        String& operator=(const String& other) {
            if(this == &other) return *this;
            if(heap) delete[] data_;
            size_ = other.size_;
            if(!other.heap) {
                heap = false;
                capacity_ = SSO_CAP;
                std::memcpy(small_, other.small_, size_ + 1);
                data_ = nullptr;
            } else {
                heap = true;
                capacity_ = other.capacity_;
                data_ = new char[capacity_];
                std::memcpy(data_, other.data_, size_ + 1);
            }
            return *this;
        }

        String& operator=(String&& other) noexcept {
            if(this == &other) return *this;
            if(heap) delete[] data_;
            size_ = other.size_;
            capacity_ = other.capacity_;
            heap = other.heap;
            if(!other.heap) {
                std::memcpy(small_, other.small_, size_ + 1);
                data_ = nullptr;
            } else {
                data_ = other.data_;
            }
            other.size_ = 0;
            other.heap = false;
            other.small_[0] = '\0';
            other.data_ = nullptr;
            other.capacity_ = SSO_CAP;
            return *this;
        }

        bool operator==(const String& other) const {
            if (size_ != other.size_) return false;
            return std::memcmp(data(), other.data(), size_) == 0;
        }

        bool operator !=(const String& other) const {
            return !( *this == other );
        }

        bool empty() {
            return size_ == 0;
        }

        size_t size() const {
            return size_;
        }

        const char* c_str() const {
            return data();
        }

        char& operator[](size_t index) {
            return data()[index];
        }

        const char& operator[](size_t index) const {
            return data()[index];
        }

        char at(size_t index) const {
            if(index >= size_) {
                throw std::out_of_range("Index out of range");
            }
            return data()[index];
        }

        void append(const String& s) {
            size_t newsize = size_ + s.size_;
            ensure_capacity(newsize);
            std::memcpy(data() + size_, s.data(), s.size_ + 1);
            size_ = newsize;
        }

        void append(char c) {
            ensure_capacity(size_ + 1);
            data()[size_] = c;
            size_ ++;
            data()[size_] = '\0';
        }

        String& operator+=(const String& s) {
            append(s);
            return *this;
        }
        String& operator+=(char c) {
            append(c);
            return *this;
        }

        String operator+(const String& other) const {
            String out;
            out.size_ = size_ + other.size_;
            if(out.size_ <= SSO_CAP) {
                out.heap = false;
                out.capacity_ = SSO_CAP;
                std::memcpy(out.small_, data(), size_);
                std::memcpy(out.small_ + size_, other.data(), other.size_ + 1);
            } else {
                out.heap = true;
                out.capacity_ = out.size_ + 1;
                out.data_ = new char[out.capacity_];
                std::memcpy(out.data_, data(), size_);
                std::memcpy(out.data_ + size_, other.data(), other.size_ + 1);
            }
            return out;
        }

        int find(char c) const {
            for(int i=0;i<size_; ++i) {
                if(data()[i] == c) return i;
            }
            return -1;
        }

        int find(const String& sub) const {
            if(sub.size_ == 0) return 0;
            if(sub.size_ > size_) return -1;
            for(int i=0; i <= size_ - sub.size_; ++i) {
                if(std::memcmp(data() + i, sub.data(), sub.size_) == 0) {
                    return i;
                }
            }
            return -1;
        }

        void insert(const String& s, int pos) {
            if(pos > size_) pos = size_;
            size_t newsize = size_ + s.size_;
            ensure_capacity(newsize);
            char* d = data();
            std::memmove(d + pos + s.size_, d + pos, size_ - pos);
            std::memcpy(d + pos, s.data(), s.size_);
            size_ = newsize;
            d[size_] = '\0';
        }

        void erase(size_t start, size_t end) {
            if(start >= size_ || start > end) return;
            if(end >= size_) end = size_ - 1;
            size_t count = end - start + 1;
            char* d = data();
            std::memmove(d + start, d + start + count, size_ - (end + count));
            size_ -= count;
            d[size_] = '\0';
        }

        void reverse() {
            char *d = data();
            for(size_t i=0; i < size_ / 2; ++i) {
                std::swap(d[i], d[size_ - 1 - i]);
            }
        }

        void clear() {
            if(heap) {
                delete[] data_;
                heap = false;
                capacity_ = SSO_CAP;
            }
            size_ = 0;
            small_[0] = '\0';
            data_ = nullptr;
        }

        void input(size_t n) {
            size_t oldsize = size_;
            size_ = n;

            if(size_ > SSO_CAP) {
                if(!heap || capacity_ < size_ + 1) {
                    enable_heap(size_ + 1);
                }
            }

            std::cout<<"Input String: "<<std::endl;
            for(int i=0;i<size_;++i) {
                std::cin>>data()[i];
            }
            data()[size_] = '\0';
        }

        void print() const {
            std::cout<<data()<<std::endl;
        }
};

int main() {
    String abc;
    abc.input(26);
    abc.reverse();
    abc.print();

    String x = "Hello World, I am Vahag";
    x.append(" !!!");
    size_t s = x.size();
    x+='A';
    x+="BCD";
    x.erase(2,5);
    x.print();
    x = "ABCDQ";
    String y = "ABCDW";
    bool equal = (x == y);
    bool inequal = (x != y);
    std::cout<< "x==y ? " <<equal<<std::endl; // 0
    std::cout<<"x != y ? " <<inequal<<std::endl; // 1
    x.print();
    x.reverse();
    x.clear();
    x.print();
    return 0;
}

