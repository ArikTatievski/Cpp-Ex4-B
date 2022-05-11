#include "Player.hpp"
const int MAXMONEY = 10;
const int COUPPRICE = 7;
const int FOREIGNVAL = 2;
namespace coup{
    //PRIVATE FUNCTIONS
    void Player::fixTurn(){
        this->game.gameFlag = 1;
        this->game.currNum++;
        this->game.currNum = (this->game.currNum)%(this->game.numOfPlayers);
        while (this->game.turn()->status == "dead"){
            this->game.currNum++;
            this->game.currNum = (this->game.currNum)%(this->game.numOfPlayers);
        }
        if(this->game.numOfPlayers == 1){
            this->game.champ = this->game.gamePlayers.at(0)->namePlayer;
        }
    }
    void Player::validTarget(Player &p){
        if(p.status == "dead"){
            throw std::invalid_argument("Already dead!\n");
        }
    }
    void Player::validTurnCheck(){
        if(this->game.turn()->namePlayer != this->name()){
            throw std::invalid_argument("Not your turn!\n");
        }
        this->lastAct = "";
        this->lastVic = NULL;
    }
    void Player::onlinePlayers() const{
        if(this->game.numOfPlayers<=1){
            throw std::invalid_argument("Not enough players!\n");
        }
    }
    //BASIC EVERY-PLAYER FUNCTIONS
    void Player::coup(Player &p) {
        validTurnCheck();
        onlinePlayers();
        validTarget(p);
        if(this->bank<COUPPRICE){
            throw std::invalid_argument("Not enough money to coup\n");
        }
        p.status="dead";
        this->bank-=COUPPRICE;
        fixTurn();
    }

    void Player::foreign_aid() {
        validTurnCheck();
        onlinePlayers();
        if(this->bank >= MAXMONEY){
            throw std::invalid_argument("You have 9-10 coins MUST use coup() or income()\n");
        }
        this->bank+=FOREIGNVAL;
        this->lastAct = "foreign_aid";
        fixTurn();
    }

    void Player::income() {
        this->validTurnCheck();
        onlinePlayers();
        if(this->bank >= MAXMONEY){
            throw std::invalid_argument("You have 10 coins MUST use coup()\n");
        }

        this->bank++;
        fixTurn();
    }
}