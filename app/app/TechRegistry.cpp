#include "StatsWeight.h"
#include "EnemyBuilder.h"
#include <map>
#include <string>

std::map<std::string, StatsWeight> tech_build_reg = {
    {"hook", build_hook()},
    {"kingsmove", build_kingsmove()},
    {"lowhand toproll", build_lowhand_toproll()},
    {"post toproll", build_post_toproll()},
    {"flop press", build_flop()}
};