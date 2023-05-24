#pragma once
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <vector>
#include <iostream>
#include <limits>
#include <algorithm> // for count_if
using namespace std;

namespace ariel{
    class Team {
        std::vector<Character*> team;
        Character* leader;

    public:

        Team(Character*);
        virtual ~Team();

        void add(Character*);
        virtual void attack(Team*);
        virtual void print();
        vector<Character*> getCharacters();
        Team(const Team&) = delete;
        Team& operator=(const Team&) = default;
        Team(Team&&) = delete;
        Team& operator=(Team&&) = default;

        static Character* getClosest(Character* leader, Team* enemy_team){
            vector<Character*> team = enemy_team->getCharacters();
            Character* min = nullptr;
            double minDist = std::numeric_limits<double>::max();

            for (auto& character : team) {
                double dist = leader->distance(character);
                if(dist < minDist && character->isAlive()){
                    minDist = dist;
                    min = character;
                }
            }
            return min;
        }

        Character* getLeader(){
            return leader;
        }

        void setLeader(Character* newLeader){
            leader = newLeader;
        }

        int stillAlive(){
            return static_cast<int>(std::count_if(team.begin(), team.end(), [](Character* character) {
                return character->isAlive();
            }));
        }
    };
}
