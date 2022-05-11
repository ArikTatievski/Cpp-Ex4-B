#include "Duke.hpp"
const int TAXVAL = 3;
const int BLOCKVAL = 2;
const int MAXMON = 10;
namespace coup{
    Duke::Duke(Game &game, std::string name) : Player(game, std::move(name)) {
        if(game.gameFlag!=0){
            throw std::invalid_argument("Game already started!\n");
        }
        this->rolePlayer = "Duke";
        game.addPlayer(*this);
    }
    void Duke::block(Player &p) {
        validTarget(p);
        onlinePlayers();
        if(p.lastAct == "foreign_aid"){
            p.bank-=BLOCKVAL;
            p.lastAct = "";
        }
        else{
            throw std::invalid_argument("Nothing to block!\n");
        }
    }

    void Duke::tax() {
        validTurnCheck();
        onlinePlayers();
        if(this->bank >= MAXMON){
            throw std::invalid_argument("You have too many coins\n");
        }
        this->bank+=TAXVAL;
        fixTurn();
    }
}

