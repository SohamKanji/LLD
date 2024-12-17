#pragma once
#include <cmath>


/**
 * We are using an inner factory class here.
*/
class Point 
{
public:
    
    class PointFactory
    {
    public:
        static Point NewCartesian(const float x, const float y) {
            return {x, y};
        }
        
        static Point NewPolar(const float rho, const float theta) {
            return {rho * cos(theta), rho * sin(theta)};
        }
    };

private:
    int x, y;
    Point(const float x, const float y) : x(x), y(y) {}
};

namespace Factory
{
    void run()
    {
        auto p = Point::PointFactory::NewCartesian(5, 5);
    }
}