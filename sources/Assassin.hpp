//
// Created by bravo8234 on 26/04/2022.
//

#ifndef EX4_CPP_A_ASSASSIN_H
#define EX4_CPP_A_ASSASSIN_H
#include "Player.hpp"

namespace coup{
    class Assassin: public Player{


    public:
        Assassin(Game& game, std::string name);
        ~Assassin(){}
        void coup(Player &p) override;
    };
}
#endif //EX4_CPP_A_ASSASSIN_H
