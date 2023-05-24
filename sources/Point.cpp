#include "Point.hpp"
#include <iostream>
#include <cmath>
using namespace std;

// https://stackoverflow.com/questions/564877/point-and-line-class-in-c

namespace ariel{
    // Default constructor, sets x and y coordinates to zero
    Point::Point(){
        this->x = 0;
        this->y = 0;
    }

    // Constructor that sets x and y coordinates
    Point::Point(double x_, double y_){
        this->x = x_;
        this->y = y_;
    }

    // Returns the Euclidean distance between this point and another point p
    double Point::distance(Point p){
        return (sqrt(pow((this->x - p.x), 2)+pow((this->y - p.y), 2)));
    }

    // Returns a string representation of the point in the format "[x, y]"
    string Point::print(){
        return "[" + std::to_string(x) + ", " + std::to_string(y) +"]";
    }

    // Getter for the x coordinate
    double Point::getX(){
        return this->x;
    }

    // Getter for the y coordinate
    double Point::getY(){
        return this->y;
    }

    // Returns a new Point object that is dist distance from src towards dest.
    // If dist is less than zero, an exception is thrown.
    // If the distance from src to dest is less than or equal to dist, dest is returned.
    Point Point::moveTowards(Point src, Point dest, double dist) {
        if(dist < 0){
            throw std::invalid_argument("distance must be greater than zero");
        }
        double d = src.distance(dest);

        if (d <= dist) {
            return dest;
        }

        double ratio = dist / d;

        // Compute new x and y coordinates
        double newX = src.getX() + (dest.getX() - src.getX()) * ratio;
        double newY = src.getY() + (dest.getY() - src.getY()) * ratio;

        return Point(newX, newY);
    }
}
