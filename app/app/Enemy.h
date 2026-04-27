#pragma once
#include <string>
#include "Stats.h"

class Enemy {
public:
    std::string name;
    Stats stats;
    std::string tech;


    Enemy(std::string name, Stats stats_enemy, std::string tech);
};