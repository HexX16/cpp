#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include "Stats.h"

void input_stats(std::map <std::string, int>& , int);
Stats build_stats(const std::map <std::string, int>&);

int main()
{
    int limit = 100;
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
    std::vector<std::string>techs{ "post toproll", "lowhand toproll", "open toproll", "kingsmove", "hook", "side", "defense hook" };

    //std::cout << "Choose your technique" << std::endl;


    std::cout << "Enter your power points from 0 to 100, the limit is 100 points" << std::endl;

    input_stats(power_params, limit);
    Stats stats_player = build_stats(power_params);

    Player player("You", stats_player, "toproll");
    std::cout << player.stats.backpress;



}

void input_stats(std::map <std::string, int>& params, int lim) {
    int limit = lim;
    for (auto& param : params) {
        std::cout << limit << " power points left " << "\n" << std::endl;
        std::cout << param.first << " = ";
        std::cin >> param.second;
        limit -= param.second;
        if (limit < 0) {
            std::cout << "The limit of power points is exhausted" << std::endl;
            return;
        }
    }
}

Stats build_stats(const std::map <std::string, int>& params) {
    Stats stats;
    
    stats.backpress = params.at("backpress");
    stats.biceps = params.at("biceps");
    stats.fingers = params.at("fingers");
    stats.high_wrist = params.at("high_wrist");
    stats.low_wrist = params.at("low_wrist");
    stats.pronation = params.at("pronation");
    stats.rise = params.at("rise");
    stats.sidepress = params.at("sidepress");
    stats.supination = params.at("supination");
    stats.triceps = params.at("triceps");

    return stats;
}
