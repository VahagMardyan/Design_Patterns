#include <iostream>
#include <cmath>

struct Point {
    private:
        Point(float x, float y) : x(x), y(y) {}

        struct PointFactory {
            private:
                PointFactory();
            public:
                static Point NewCartesian(float x, float y) {
                    return {x, y};
                }
                static Point NewPolar(float r, float theta) {
                    return {r * cosf(theta), r * sinf(theta)};
                }
        };

    public:
        float x,y;
        static PointFactory factory;
};

int main() {
    Point p1 = Point::factory.NewPolar(3.0f, 4.0f);

    std::cout << p1.x << " " << p1.y << std::endl;
    return 0;
}
