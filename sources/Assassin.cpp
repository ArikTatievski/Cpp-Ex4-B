#include "Assassin.hpp"
const int REALCOUP = 7;
const int LOWCOUP = 3;
namespace coup{
    Assassin::Assassin(Game &game, std::string name) : Player(game, std::move(name)) {
        if(game.gameFlag!=0){
            throw std::invalid_argument("Game already started!\n");
        }
        this->rolePlayer = "Assassin";
        game.addPlayer(*this);
    }
    void Assassin::coup(Player &p) {
        validTurnCheck();
        validTarget(p);
        onlinePlayers();
        if(this->bank<LOWCOUP){
            throw std::invalid_argument("Not enough money to coup\n");
        }
        if(this->bank>=REALCOUP){
            p.status="dead";
            this->bank-=REALCOUP;
        }
        else{
            p.status="dead";
            this->bank-=LOWCOUP;
            this->lastAct = "assassinate";
            this->lastVic = &p;
        }
        fixTurn();
    }
}