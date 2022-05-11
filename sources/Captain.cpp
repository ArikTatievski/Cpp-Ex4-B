#include "Captain.hpp"

#include <utility>
const int STEALVAL = 2;
namespace coup {
    Captain::Captain(Game &game, std::string name) : Player(game, std::move(name)) {
        if(game.gameFlag!=0){
            throw std::invalid_argument("Game already started!\n");
        }
        this->rolePlayer = "Captain";
        game.addPlayer(*this);
    }
    void Captain::block(Player &p) {
        validTurnCheck();
        validTarget(p);
        onlinePlayers();
        if(p.lastAct == "foreign_aid"){
            p.bank-=STEALVAL;
            p.lastAct = "";
        }
        else if(p.lastAct == "steal"){
            p.bank-=STEALVAL;
            p.lastVic->bank+=STEALVAL;
            p.lastAct = "";
        }
        else{
            throw std::invalid_argument("Nothing to block!\n");
        }
    }

    void Captain::steal(Player &p) {
        validTurnCheck();
        validTarget(p);
        onlinePlayers();
        if(p.bank<STEALVAL){
            this->bank+=p.bank;
            p.bank=0;
            this->lastVic =&p;
            this->lastAct = "steal";
        }
        else{
            p.bank-=STEALVAL;
            this->bank+=STEALVAL;
            this->lastVic =&p;
            this->lastAct = "steal";
        }
        fixTurn();
    }
}