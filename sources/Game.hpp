#ifndef EX4_CPP_A_GAME_H
#define EX4_CPP_A_GAME_H
#pragma once
#include "iostream"
#include "vector"
#include "Player.hpp"

namespace coup{
    class Player;
    class Game{
    public:
        std::vector<Player*> gamePlayers;
        unsigned int numOfPlayers;
        unsigned int currNum;
        std::string champ;
        int gameFlag;
        Game(){
            this->champ = "-1";
            this->numOfPlayers = 0;
            this->currNum = 0;
            this->gameFlag = 0;
        };
        ~Game(){};
        std::vector<std::string> players();
        Player* turn();
        std::string winner();
        void addPlayer(Player& p);
        Game& operator=(const Game& other);
    };
}
#endif //EX4_CPP_A_GAME_H
