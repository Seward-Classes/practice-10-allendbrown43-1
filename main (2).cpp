// AI Disclaimer: This code was written without the use of AI tools.
// Any assistance received was from course materials, textbooks, or instructor guidance only.

// By: Allen Brown
// Date: 4/14/2026


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>

// TEMP WORKAROUND
#include "Shape.cpp"

void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        shape->display();
        std::cout << "Area: " 
                  << std::fixed << std::setprecision(4) 
                  << shape->getArea() << std::endl << std::endl;
    }
}

int main() {
    std::ifstream file("shapes.txt");

    // File error handling
    if (!file) {
        std::cerr << "Error: Could not open shapes.txt" << std::endl;
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;
    int lineNumber = 0;

    while (std::getline(file, line)) {
        lineNumber++;
        std::stringstream ss(line);
        std::string type;

        ss >> type;

        try {
            if (type == "rectangle") {
                double w, h;
                if (!(ss >> w >> h)) {
                    throw std::runtime_error("Invalid rectangle data");
                }
                shapes.push_back(std::make_unique<Rectangle>(w, h));
            }
            else if (type == "circle") {
                double r;
                if (!(ss >> r)) {
                    throw std::runtime_error("Invalid circle data");
                }
                shapes.push_back(std::make_unique<Circle>(r));
            }
            else {
                throw std::runtime_error("Unknown shape type");
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error on line " << lineNumber 
                      << ": " << e.what() << std::endl;
        }
    }

    printAllAreas(shapes);

    return 0;
}