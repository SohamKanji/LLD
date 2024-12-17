#include <cmath>

struct Point {
    float x, y;
    
    Point(const float x, const float y) : x(x), y(y) {}
    
    static Point NewCartesian(const float x, const float y) {
        return {x, y};
    }
    
    static Point NewPolar(const float rho, const float theta) {
        return {rho * cos(theta), rho * sin(theta)};
    }
};

namespace PointFactoryExample
{
    void run()
    {
        /**
         * This is one way to create a point object.
         * We can also have a separate factory class that creates Point objects.
         */
        auto p = Point::NewPolar(5, M_PI_4);
    }
}

struct PointFactory {
    static Point NewCartesian(const float x, const float y) {
        return {x, y};
    }
    
    static Point NewPolar(const float rho, const float theta) {
        return {rho * cos(theta), rho * sin(theta)};
    }
};

namespace PointFactoryExample2
{
    void run()
    {
        auto p = PointFactory::NewCartesian(5, 5);
    }
}

