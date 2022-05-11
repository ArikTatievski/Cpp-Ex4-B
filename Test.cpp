#include <iostream>
#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;
using namespace coup;
TEST_CASE("Good Input Testing") {
    Game g{};
    Duke duke{g, "Najeeb"};
    Assassin assassin{g, "Roi"};
    Ambassador ambassador{g, "Shirazi"};
    Captain captain{g, "Arik"};
    Contessa contessa{g, "Sabrina"};
    vector<string> player_CHECK;
    player_CHECK.push_back("Najeeb");
    player_CHECK.push_back("Roi");
    player_CHECK.push_back("Shirazi");
    player_CHECK.push_back("Arik");
    player_CHECK.push_back("Sabrina");
    vector<string> players = g.players();
    CHECK(duke.name == "Najeeb");
    CHECK(duke.role == "Duke");
    CHECK(assassin.name == "Roi");
    CHECK(assassin.role == "Assassin");
    CHECK(ambassador.name == "Shirazi");
    CHECK(ambassador.role == "Ambassador");
    CHECK(captain.name == "Arik");
    CHECK(captain.role == "Captain");
    CHECK(contessa.name == "Sabrina");
    CHECK(contessa.role == "Contessa");
    CHECK(player_CHECK == players);
    CHECK(g.turn() == "Najeeb");
    duke.income();
    CHECK(g.turn() == "Roi");
    assassin.foreign_aid();
    CHECK(g.turn() == "Shirazi");
    ambassador.transfer(captain,contessa);
    CHECK(g.turn() == "Shirazi");
}
TEST_CASE("Throwing Exception Tests"){
    Game g{};
    Duke duke{g, "Najeeb"};
    Assassin assassin{g, "Roi"};
    Ambassador ambassador{g, "Shirazi"};
    Captain captain{g, "Arik"};
    Contessa contessa{g, "Sabrina"};
    CHECK_THROWS(assassin.income());
    CHECK_THROWS(assassin.coup(captain));
    CHECK_THROWS(ambassador.foreign_aid());
    CHECK_THROWS(captain.steal(assassin));
    CHECK_THROWS(contessa.foreign_aid());
}