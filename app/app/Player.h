#pragma once
#include <string>
#include "Stats.h"

class Player
{
public:
    std::string name;
    Stats stats;
    std::string tech;

    Player(std::string name, Stats stats_player, std::string tech);
};

