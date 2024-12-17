#include <cmath>

struct Point {
  float x, y;

  /**
   * This is constructor for polar coordinates.
  */
  Point(const float x, const float y) : x(x), y(y) {}

  // What if i want a constructor with cartesian coordinates?
  // This won't work in C++. We can't have two constructors with the same signature.
  Point(const float rho, const float theta) : x(rho * cos(theta)), y(rho * sin(theta)) {}
};

/**
 * This is where factory pattern comes into play.
 * We can have a factory method that returns a Point object.
*/