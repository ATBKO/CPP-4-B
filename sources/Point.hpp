#pragma once
#include <stdexcept>

namespace ariel {
    // https://stackoverflow.com/questions/564877/point-and-line-class-in-c
    // The Point class represents a point in a 2-dimensional space
    class Point{
        // x and y coordinates of the point
        double x;
        double y;

    public:
        // Default constructor that initializes the point at (0,0)
        Point();
        // Overloaded constructor that initializes the point at the specified coordinates (x, y)
        Point(double, double);

        // Calculates and returns the Euclidean distance to another Point
        double distance(Point);

        // Returns a string representation of the point in the format "[x, y]"
        std::string print();

        // Getter function for the x-coordinate
        double getX();

        // Getter function for the y-coordinate
        double getY();

        // Static function that calculates and returns a new Point which is 'dist' distance closer to 'dest' from 'src'
        static Point moveTowards(Point, Point, double);
    };
}
