#include <stdexcept>
#include "Player.h"
#include "Stats.h"

Player::Player(std::string name, Stats stats_player, std::string tech)
	: name(name), stats(stats_player), tech(tech)
{

}