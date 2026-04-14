// AI Disclaimer: This code was written without the use of AI tools.
// Any assistance received was from course materials, textbooks, or instructor guidance only.

// By: Allen Brown
// Date: 4/14/2026


#include "Shape.h"
#include <iomanip>
#include <cmath>

// Base display
void Shape::display() const {
    std::cout << "Generic Shape" << std::endl;
}

// Rectangle implementation
Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

double Rectangle::getArea() const {
    return width * height;
}

void Rectangle::display() const {
    std::cout << "Rectangle (" << width << " x " << height << ")" << std::endl;
}

// Circle implementation
Circle::Circle(double r) : radius(r) {}

double Circle::getArea() const {
    return M_PI * radius * radius;
}

void Circle::display() const {
    std::cout << "Circle (radius: " << radius << ")" << std::endl;
}