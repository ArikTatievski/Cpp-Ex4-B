#ifndef EX4_CPP_A_DUKE_H
#define EX4_CPP_A_DUKE_H
#include "Player.hpp"
namespace coup{
    class Duke: public Player{


    public:
        Duke(Game& game, std::string name);
        ~Duke(){};
        void block(Player& p);
        void tax();
    };
}
#endif //EX4_CPP_A_DUKE_H
