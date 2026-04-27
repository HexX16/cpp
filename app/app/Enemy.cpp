#include <stdexcept>
#include "Enemy.h"
#include "Stats.h"


Enemy::Enemy(std::string name, Stats stats_enemy, std::string tech)
	: name(name), stats(stats_enemy), tech(tech)
{

}