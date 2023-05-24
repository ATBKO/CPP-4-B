#pragma once
#include "Character.hpp"

namespace ariel{
    // The Cowboy class inherits from the Character class
    class Cowboy : public Character{
        int bullets; // The number of bullets the cowboy has

    public:
        // Constructor that sets the name and location of the cowboy
        Cowboy(string, Point);

        // Method that enables the cowboy to shoot another character
        void shoot(Character*);

        // Method that checks if the cowboy has any bullets left
        bool hasboolets();

        // Method that reloads the cowboy's bullets
        void reload();

        // Overridden print method that prints the cowboy's details
        string print() override;
    };
}
