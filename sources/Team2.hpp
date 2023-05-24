#pragma once
#include "Team.hpp"

namespace ariel {
    /**
     * @brief Represents Team2, a subclass of Team.
     *
     * This class inherits from the base Team class and provides additional functionality specific to Team2.
     */
    class Team2 : public Team {
    public:
        /**
         * @brief Constructor for Team2.
         *
         * @param leader The leader character of the team.
         */
        Team2(Character* leader);

        /**
         * @brief Attack the enemy team.
         *
         * Overrides the base attack() method in Team class.
         * Performs the attack actions specific to Team2, targeting the enemy team.
         *
         * @param enemy_team Pointer to the enemy team to attack.
         */
        void attack(Team* enemy_team) override;

        /**
         * @brief Print the characters in the team.
         *
         * Overrides the base print() method in Team class.
         * Prints the details of the characters in Team2.
         */
        void print() override;
    };
}
