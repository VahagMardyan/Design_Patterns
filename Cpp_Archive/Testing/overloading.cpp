#include <iostream>
#include <cmath>

// Այս ամենը կլիներ նաև class-ով, ուղղակի պետք է ավելացնեինք "public:"

struct Vector {
    float x,y;
    Vector() {}
    Vector(float x1, float y1) : x(x1), y(y1) {}
    
    float distance(const Vector& v) const {
        return std::sqrt((x - v.x) * (x-v.x) + (y-v.y) * (y-v.y));
    }

    Vector operator+(const Vector& other) const {
        return Vector(this->x + other.x, this->y + other.y);
        // return Vector(x + other.x, y + other.y);
    }

    Vector operator*(const Vector& other) const {
        return Vector(this->x * other.x, this->y * other.y);
    }
    
    bool operator==(const Vector& other) const {
        return this->x == other.x && this->y == other.y;
    }

    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }
};

std::istream& operator>>(std::istream& stream, Vector& vector) {
    std::cout << "Input (x,y): ";
    stream >> vector.x >> vector.y;
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Vector& vector) {
    std::cout << "Output (x,y): ";
    stream << vector.x << "," << vector.y;
    return stream;
}

int main() {
    Vector a;
    std::cin >> a;
    Vector b(4,5);
    Vector c = a*b + a;
    std::cout<<c<<std::endl;
    float d = c.distance(a);
    std::cout<<"d(a,c)="<<d<<std::endl;
    if(a == Vector(2,3)) {
        std::cout<<"a = b"<<std::endl;
    }
    if(a != c) {
        std::cout<<"a != c"<<std::endl;
    }
    return 0;
}