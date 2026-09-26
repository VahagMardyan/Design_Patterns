#include <iostream>
#include <cstring>

class String {
private:
    char* m_buffer;
    size_t m_size;
public:
    String(const char* str) {
        m_size = std::strlen(str);
        m_buffer = new char[m_size + 1];
        std::memcpy(m_buffer, str, m_size + 1);
        m_buffer[m_size] = 0;
    }

    String(const String& other) : m_size(other.m_size) {
        m_buffer = new char[m_size + 1];
        std::memcpy(m_buffer, other.m_buffer, m_size + 1);
    }

    ~String() {
        delete[] m_buffer;
    }

    char& operator[](unsigned int index) {
        return m_buffer[index];
    }

    // friend std::istream& operator>>(std::istream& stream, String& str);
    friend std::ostream& operator<<(std::ostream& stream, const String& str);
};

// Can't do since C++20
// std::istream& operator>>(std::istream& stream, String& str) { 
//     stream >> str.m_buffer;
//     return stream;
// }

std::ostream& operator<<(std::ostream& stream, const String& str) {
    stream << str.m_buffer;
    return stream;
}

int main() {
    String string = "Vahag";
    String second = string;
    second[2] = 'x';
    std::cout << string << std::endl;
    std::cout << second << std::endl;

    // std::cin.get();
    return 0;
}