#include "Team.hpp"

namespace ariel {

    // Constructor: Create a new Team with a specified leader
    Team::Team(Character* leader) : leader(leader) {
        // Check if the leader is already in a team
        if (leader->inTeam()) {
            throw std::runtime_error("The character is already in a team");
        }
        // Add the leader to the team
        add(leader);
    }

    // Add a new character to the team
    void Team::add(Character* character) {
        // Check if the character is already in a team
        if (character->inTeam()) {
            throw std::runtime_error("The character is already in a team");
        }
        // Check if the team is already full
        if (team.size() >= 10) {
            throw std::runtime_error("The team is already full");
        }
        // Add the character to the team
        team.push_back(character);
        character->inTeam() = true;
    }

    // Return the characters in the team
    std::vector<Character*> Team::getCharacters() {
        return team;
    }

    // The team attacks an enemy team
    void Team::attack(Team* enemy_team) {
        // Check if the enemy team pointer is null
        if (!enemy_team) {
            throw std::invalid_argument("Null pointer");
        }
        // Check if this team is not alive
        if (!stillAlive()) {
            return;
        }
        // Check if the enemy team is not alive
        if (!enemy_team->stillAlive()) {
            throw std::runtime_error("Attacking a dead team is not available");
        }
        // Check if the team leader is not alive, and replace them
        if (!leader->isAlive()) {
            setLeader(getClosest(leader, this));
        }
        // Get the closest enemy character
        Character* victim = getClosest(leader, enemy_team);
        if (!victim) {
            return;
        }
        // Attack the enemy team
        for (auto character : team) {
            // Skip characters that are not alive
            if (!character->isAlive()) {
                continue;
            }
            // Check if the character is a Cowboy
            if (auto* cowboy = dynamic_cast<Cowboy*>(character)) {
                if (victim->isAlive()) {
                    // Shoot or reload based on ammo availability
                    if (cowboy->hasboolets()) {
                        cowboy->shoot(victim);
                    } else {
                        cowboy->reload();
                    }
                }
                if (!victim->isAlive()) {
                    // Get the new closest enemy character
                    victim = getClosest(leader, enemy_team);
                    if (!victim) {
                        return;
                    }
                }
            }
                // Check if the character is a Ninja
            else if (auto* ninja = dynamic_cast<Ninja*>(character)) {
                if (victim->isAlive()) {
                    // Slash or move towards the enemy based on distance
                    if (ninja->distance(victim) < 1) {
                        ninja->slash(victim);
                    } else {
                        ninja->move(victim);
                    }
                }
                if (!victim->isAlive()) {
                    // Get the new closest enemy character
                    victim = getClosest(leader, enemy_team);
                    if (!victim) {
                        return;
                    }
                }
            }
        }
    }

    // Print the details of the characters in the team
    void Team::print() {
        for (auto character : team) {
            std::cout << character->print() << std::endl;
        }
    }

    // Destructor: Delete all the characters in the team and set the leader to nullptr
    Team::~Team() {
        leader = nullptr;
        for (auto character : team) {
            delete character;
        }
    }

}
