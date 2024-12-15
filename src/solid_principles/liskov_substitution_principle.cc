#include "liskov_substitution_principle.h"
#include <iostream>

Rectangle::Rectangle(int width, int height) : m_width(width), m_height(height)
{

}

void Rectangle::set_width(int width) {
    m_width = width;
}

void Rectangle::set_height(int height) {
    m_height = height;
}

Square::Square(int side) : Rectangle(side, side)
{

}

/**
 * We need to reimplement this methods because if some client is using set_width and set_height on rectangle interface, and the concrete object
 * is actually just a square then setting just width or height would violate geometrical property of a square.
*/
void Square::set_width(int width) {
    m_width = m_height = width;
}

void Square::set_height(int height) {
    m_height = m_width = height;
}

static void process(Rectangle& r) {
    int w = r.get_width();
    r.set_height(10);
    std::cout << "Exp area: " << 10*w << std::endl;
    std::cout << "Actual area: " << r.get_area() << std::endl;
}

void LiskovSubstitutionPrinciple::run() {
    Rectangle r{ 5,5 };
    process(r);

    Square s{ 5 };
    process(s);
}