#include "Game.hpp"
const int MAXPLAYERS = 6;
const int MINPLAYERS = 1;

namespace coup{

    std::vector<std::string> Game::players() {
        std::vector<std::string> names;
        for(auto & gamePlayer : this->gamePlayers)
        {
            if(gamePlayer->status == "alive"){names.push_back(gamePlayer->namePlayer);}
        }
        return names;
    }

    Player* Game::turn() {
        if (numOfPlayers == 0){
            throw std::invalid_argument("No players are in the game\n");
        }
        return this->gamePlayers.at(currNum);
    }

    Game &Game::operator=(const Game& other) {
        for(const auto & gamePlayer : other.gamePlayers)
        {
            this->gamePlayers.push_back(gamePlayer);
        }
        this->currNum = other.currNum;
        this->numOfPlayers = other.numOfPlayers;
        return *this;
    }

    std::string Game::winner() {
        if(this->players().size() == MINPLAYERS && numOfPlayers!= MINPLAYERS){
            return (this->players().at(0));
        }
        throw std::invalid_argument("No winner yet!\n");
    }
    void Game::addPlayer(Player &p) {
        if (this->numOfPlayers == MAXPLAYERS){
            throw std::invalid_argument("Too many online players\n");
        }
        this->numOfPlayers++;
        this->gamePlayers.push_back(&p);
    }
}