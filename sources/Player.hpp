#ifndef EX4_CPP_A_PLAYER_H
#define EX4_CPP_A_PLAYER_H
#pragma once
#include <utility>
#include "stdexcept"
#include "vector"
#include "string"
#include "Game.hpp"
namespace coup{
    class Game;
    class Player{
    public:
        //basic
        Game& game;
        std::string namePlayer;
        std::string rolePlayer;
        std::string status;
        int bank;
        //incase of blocking
        std::string lastAct;
        Player* lastVic;
        unsigned int assassinationNum;
        //const&destr
        Player(Game& game, std::string name):status(std::move("alive")),bank(0), game(game),namePlayer(std::move(name)){};
        virtual ~Player(){};
        //self-var functions
        int coins()const {return this->bank;};
        std::string name()const{return this->namePlayer;};
        std::string role()const{return this->rolePlayer;};
        //basic every-player function
        void income();
        void foreign_aid();
        virtual void coup(Player& p);
        //private functions;
        void validTurnCheck();
        static void validTarget(Player &p);
        void fixTurn();
        void onlinePlayers() const;

    };
}
#endif //EX4_CPP_A_PLAYER_H
