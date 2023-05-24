#include "Team2.hpp"
#include <algorithm>
#include <random>

namespace ariel{
    Team2::Team2(Character* leader_) : Team(leader_) {}

    void Team2::attack(Team* enemy_team){
        if(!enemy_team){
            throw std::invalid_argument("Null Pointer");
        }

        if(!stillAlive()){
            return;
        }

        if(!enemy_team->stillAlive()){
            throw std::runtime_error("Attacking a dead team is not available");
        }

        if(!getLeader()->isAlive()){
            setLeader(getClosest(getLeader(), this));
        }

        Character* victim = getClosest(getLeader(), enemy_team);
        if(!victim){
            return;
        }

        for (auto& character : getCharacters()){
            if(!character->isAlive()){
                continue;
            }

            if(auto* cowboy = dynamic_cast<Cowboy*>(character)){
                if(victim->isAlive()){
                    if(cowboy->hasboolets()){
                        cowboy->shoot(victim);
                    } else {
                        cowboy->reload();
                    }
                }

                if(!victim->isAlive()){
                    victim = getClosest(getLeader(), enemy_team);
                    if(!victim){
                        return;
                    }
                }
            } else if(auto* ninja = dynamic_cast<Ninja*>(character)){
                if(victim->isAlive()){
                    if(ninja->getLocation().distance(victim->getLocation()) < 1){
                        ninja->slash(victim);
                    } else {
                        ninja->move(victim);
                    }
                }

                if(!victim->isAlive()){
                    victim = getClosest(getLeader(), enemy_team);
                    if(!victim){
                        return;
                    }
                }
            }
        }
    }

    void Team2::print(){
        for (auto& character : getCharacters()) {
            cout << character->print() << endl;
        }
    }
}
