#include "Ninja.hpp"
#include "Point.hpp"
#include <iostream>
#include <sstream>

namespace ariel{

    // Constructor that sets the name, location, hit points, and velocity of the ninja
    Ninja::Ninja(string name, Point location, int hitPoints_, int velocity_) : Character(name, location, hitPoints_){
        this->velocity = velocity_;
    }

    // The ninja moves towards an enemy character. The new location of the ninja is calculated
    // using the moveTowards function of the Point class.
    void Ninja::move(Character* enemy){
        this->getLocation() = Point::moveTowards(this->getLocation(), enemy->getLocation(), this->velocity);
    }

    // The ninja slashes an enemy character. If the ninja is the enemy, an exception is thrown.
    // If either the ninja or the enemy is not alive, an exception is also thrown.
    // If the distance between the ninja and the enemy is less than 1, the enemy's hit points are reduced by 40.
    void Ninja::slash(Character* enemy){
        if(this == enemy){
            throw std::runtime_error("A ninja cannot harm themselves.");
        }
        if(!this->isAlive()){
            throw std::runtime_error("Cannot slash; this ninja is dead!");
        }
        if(!enemy->isAlive()){
            throw std::runtime_error("Cannot slash; the enemy is already dead!");
        }
        if(this->getLocation().distance(enemy->getLocation()) < 1){
            enemy->hit(40);
        }
    }

    // Prints the ninja's details. If the ninja is alive, prints the name, hit points, and location.
    // If the ninja is not alive, prints the name and location.
    string Ninja::print(){
        std::ostringstream ss;
        ss << "Name: " << this->getName();
        if(this->isAlive()){
            ss << "\nHit Points: " << this->getHitPoints();
        } else {
            ss << " (dead)";
        }
        ss << "\nLocation: " << this->getLocation().print();
        return ss.str();
    }

    // OldNinja, YoungNinja, and TrainedNinja are all subclasses of Ninja, with different initial hit points and velocity.
    // OldNinja starts with 150 hit points and velocity of 8.
    OldNinja::OldNinja(string name, Point location) : Ninja(name, location, 150, 8){}

    // YoungNinja starts with 100 hit points and velocity of 14.
    YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location, 100, 14){}

    // TrainedNinja starts with 120 hit points and velocity of 12.
    TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location, 120, 12){}

}
