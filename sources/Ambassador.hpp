//
// Created by bravo8234 on 26/04/2022.
//

#ifndef EX4_CPP_A_AMBASSADOR_H
#define EX4_CPP_A_AMBASSADOR_H
#include "Player.hpp"
namespace coup{
    class Ambassador : public Player{


    public:
        Ambassador(Game & game, std::string name);
        ~Ambassador(){};
        void block(Player& p);
        void transfer(Player& from, Player& to);
    };
}


#endif //EX4_CPP_A_AMBASSADOR_H
