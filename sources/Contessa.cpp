#include "Contessa.hpp"
namespace coup
{
    Contessa::Contessa(Game &game, std::string name) : Player(game, std::move(name)) {
        if(game.gameFlag!=0){
            throw std::invalid_argument("Game already started!\n");
        }
        this->rolePlayer = "Contessa";
        game.addPlayer(*this);
    }
    void Contessa::block(Player &p) {
        validTarget(p);
        onlinePlayers();
        if(p.lastAct == "assassinate") {
            p.lastVic->status = "alive";
            p.lastAct = "";
        }
        else{
            throw std::invalid_argument("Nothing to block!\n");
        }
    }
}
