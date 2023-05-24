#pragma once
#include "Point.hpp"
#include <string>
using namespace std;

namespace ariel {
    class Character {
        Point location; // The current location of the character
        int hitPoints; // The character's health points
        string name; // The name of the character
        int inTeam_ = 0; // Indicates the team of the character

    public:
        // Default constructor
        Character();

        // Constructor that sets the name, location, and hit points of the character
        Character(string, Point, int);

        // Virtual destructor (using default)
        virtual ~Character() = default;

        // Delete copy constructor and copy assignment operator
        Character(const Character&) = delete;
        Character& operator=(const Character&) = delete;

        // Delete move constructor and move assignment operator
        Character(Character&&) = delete;
        Character& operator=(Character&&) = delete;

        // Checks if the character is alive (hit points > 0)
        bool isAlive();

        // Calculates the distance from this character to another character
        double distance(Character*);

        // Decreases the character's hit points by a specified amount
        void hit(int);

        // Returns the name of the character
        string getName();

        // Returns the location of the character
        Point& getLocation();

        // Returns the team of the character
        int& inTeam();

        // Returns the hit points of the character
        int getHitPoints();

        // Pure virtual function for printing the character's details, to be implemented by derived classes
        virtual string print() = 0;
    };
}
