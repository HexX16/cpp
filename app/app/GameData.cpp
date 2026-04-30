#include <map>
#include <vector>
#include <string>
#include "GameData.h"

std::map<std::string, int> get_default_params()
{
    std::map<std::string, int> power_params = {
        {"backpress", 0},
        {"biceps", 0},
        {"fingers", 0},
        {"high_wrist", 0},
        {"low_wrist", 0},
        {"pronation", 0},
        {"rise", 0},
        {"sidepress", 0},
        {"supination", 0},
        {"triceps", 0}
    };
    return power_params;
}

const std::vector<std::string> get_techs()
{
    const std::vector<std::string> techs = {
        "defense hook",
        "hook",
        "kingsmove",
        "lowhand toproll",
        "post toproll",
        "flop press"
    };
    return techs;
}
