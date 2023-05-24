#include "Cowboy.hpp"
#include <iostream>

namespace ariel{

    // Constructor that sets the name, location and initial hit points of the cowboy. Bullets are also initialized to 6
    Cowboy::Cowboy(string name, Point location) : Character(name, location, 110), bullets(6) {}

    // The cowboy shoots an enemy character. If the cowboy is the enemy or if enemy is nullptr, an exception is thrown.
    // If either the cowboy or the enemy is not alive, an exception is also thrown.
    // If the cowboy has bullets, the enemy's hit points are reduced by 10 and the cowboy's bullets are reduced by 1.
    void Cowboy::shoot(Character* enemy){
        if (enemy == nullptr){
            throw std::invalid_argument("Enemy is null");
        }
        if(this == enemy){
            throw std::runtime_error("Cannot self harm");
        }
        if(this->isAlive() && enemy->isAlive()){
            if(this->hasboolets()){
                enemy->hit(10);
                this->bullets--;
            }
        }
        else{
            throw std::runtime_error("Either cowboy or enemy is dead!");
        }
    }

    // Returns true if the cowboy has bullets, false otherwise
    bool Cowboy::hasboolets(){
        return this->bullets > 0;
    }

    // Reloads the cowboy's bullets to 6. If the cowboy is not alive, does nothing.
    void Cowboy::reload(){
        if(this->isAlive()){
            this->bullets = 6;
        }else{
            throw std::runtime_error("Dead cowboy cannot reload");
        }
    }

    // Prints the cowboy's details. If the cowboy is alive, prints the name, hit points and location.
    // If the cowboy is not alive, prints the name and location.
    string Cowboy::print(){
        string toPrint = "Name: C " + this->getName() +
                         (this->isAlive() ? ("\nHit Points: " + std::to_string(this->getHitPoints())) : " (dead)") +
                         "\nLocation: " + this->getLocation().print();
        return toPrint;
    }
}
