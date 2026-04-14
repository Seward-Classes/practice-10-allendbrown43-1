// AI Disclaimer: This code was written without the use of AI tools.
// Any assistance received was from course materials, textbooks, or instructor guidance only.

// By: Allen Brown
// Date: 4/14/2026


#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

// Base abstract class
class Shape {
public:
    virtual double getArea() const = 0;   // Pure virtual
    virtual void display() const;         // Virtual display
    virtual ~Shape() = default;           // Virtual destructor
};

// Rectangle class
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h);
    double getArea() const override;
    void display() const override;
};

// Circle class
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r);
    double getArea() const override;
    void display() const override;
};

#endif