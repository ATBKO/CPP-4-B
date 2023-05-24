#include "Character.hpp"

namespace ariel {
    // Default constructor: Initializes a new Character with default values
    Character::Character() : name(""), location(Point()), hitPoints(0), inTeam_(0) {}

    // Parameterized constructor: Initializes a new Character with the specified values
    Character::Character(string name_, Point location_, int hitPoints_)
            : name(name_), location(location_), hitPoints(hitPoints_), inTeam_(0) {}

    // isAlive: Checks whether the Character is alive (has more than 0 hit points)
    bool Character::isAlive(){
        return this->hitPoints > 0;
    }

    // distance: Returns the distance between this Character's location and another Character's location
    double Character::distance(Character* other){
        return this->location.distance(other->location);
    }

    // hit: Reduces the Character's hit points by the specified number of points
    void Character::hit(int points){
        if(points > 0){
            this->hitPoints -= points;
        } else {
            throw std::invalid_argument("Points to hit must be greater than zero");
        }
    }

    // getName: Returns the Character's name
    string Character::getName(){
        return this->name;
    }

    // getLocation: Returns the Character's location
    Point &Character::getLocation(){
        return this->location;
    }

    // getHitPoints: Returns the Character's current hit points
    int Character::getHitPoints(){
        return this->hitPoints;
    }

    // inTeam: Returns a reference to the Character's team affiliation indicator
    int& Character::inTeam(){
        return this->inTeam_;
    }
}
