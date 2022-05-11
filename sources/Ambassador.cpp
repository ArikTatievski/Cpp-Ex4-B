#include "Ambassador.hpp"

#include <utility>
const int STEALVAL = 2;
const int MAXMON = 10;
namespace coup{
    Ambassador::Ambassador(Game &game, std::string name) : Player(game, std::move(name)) {
        if(game.gameFlag!=0){
            throw std::invalid_argument("Game already started!\n");
        }
        this->rolePlayer = "Ambassador";
        game.addPlayer(*this);
    }
    void Ambassador::transfer(Player &from, Player &to) {
        validTurnCheck();
        onlinePlayers();
        validTarget(from);
        validTarget(to);
        if(from.bank==0 || to.bank==MAXMON){
            throw std::invalid_argument("Either victim/target has too much/not enough money\n");
        }
        from.bank--;
        to.bank++;
        fixTurn();
    }
    void Ambassador::block(Player &p) {
        validTarget(p);
        onlinePlayers();
        if(p.lastAct == "steal"){
            p.bank-=STEALVAL;
            p.lastVic->bank+=STEALVAL;
            p.lastAct = "";
        }
        else{
            throw std::invalid_argument("Nothing to block!\n");
        }
    }
}
