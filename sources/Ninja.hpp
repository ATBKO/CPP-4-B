#pragma once
#include "Character.hpp"

namespace ariel{

    // The Ninja class inherits from the Character class
    class Ninja : public Character{
        int velocity;  // The speed at which the ninja moves

    public:
        // Constructor for the Ninja class that takes a name, location, hitPoints, and velocity
        Ninja(string, Point, int, int);

        // Moves the ninja towards a specific character
        void move(Character*);

        // Allows the ninja to attack a specific character
        void slash(Character*);

        // Prints the ninja's details
        string print() override;
    };

    // The OldNinja class inherits from the Ninja class
    class OldNinja : public Ninja{
    public:
        // Constructor for the OldNinja class that takes a name and location
        OldNinja(string, Point);
    };

    // The YoungNinja class inherits from the Ninja class
    class YoungNinja : public Ninja{
    public:
        // Constructor for the YoungNinja class that takes a name and location
        YoungNinja(string, Point);
    };

    // The TrainedNinja class inherits from the Ninja class
    class TrainedNinja : public Ninja{
    public:
        // Constructor for the TrainedNinja class that takes a name and location
        TrainedNinja(string, Point);
    };
}
