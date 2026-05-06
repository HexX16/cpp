#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <random>
#include <cctype>
#include "Enemy.h"
#include "Player.h"
#include "Stats.h"
#include "GameData.h"
#include "EnemyBuilder.h"
#include "TechRegistry.h"

std::string choose_tech(const std::vector<std::string>&);
void input_stats(std::map <std::string, int>& , int);
Stats build_stats(const std::map <std::string, int>&);
Player create_player();
Enemy create_enemy();
Stats build_stats_from_weight(const StatsWeight&, int);
bool fight(Player, Enemy);
Tech to_tech(std::string&);


int main()
{
    Enemy enemy = create_enemy();
    std::cout << "\n========== ENEMY ==========\n";
    std::cout << enemy.name << ": tech - " << enemy.tech << "\n";
    std::cout << "backpress   : " << enemy.stats.backpress << "\n";
    std::cout << "biceps      : " << enemy.stats.biceps << "\n";
    std::cout << "fingers     : " << enemy.stats.fingers << "\n";
    std::cout << "high_wrist  : " << enemy.stats.high_wrist << "\n";
    std::cout << "low_wrist   : " << enemy.stats.low_wrist << "\n";
    std::cout << "pronation   : " << enemy.stats.pronation << "\n";
    std::cout << "rise        : " << enemy.stats.rise << "\n";
    std::cout << "sidepress   : " << enemy.stats.sidepress << "\n";
    std::cout << "supination  : " << enemy.stats.supination << "\n";
    std::cout << "triceps     : " << enemy.stats.triceps << "\n";


    Player player = create_player();
    std::cout << "\n========== PLAYER ==========\n";
    std::cout << player.name << ": tech - " << player.tech << "\n";
    std::cout << "backpress   : " << player.stats.backpress << "\n";
    std::cout << "biceps      : " << player.stats.biceps << "\n";
    std::cout << "fingers     : " << player.stats.fingers << "\n";
    std::cout << "high_wrist  : " << player.stats.high_wrist << "\n";
    std::cout << "low_wrist   : " << player.stats.low_wrist << "\n";
    std::cout << "pronation   : " << player.stats.pronation << "\n";
    std::cout << "rise        : " << player.stats.rise << "\n";
    std::cout << "sidepress   : " << player.stats.sidepress << "\n";
    std::cout << "supination  : " << player.stats.supination << "\n";
    std::cout << "triceps     : " << player.stats.triceps << "\n";

    bool result = fight(player, enemy);
    return 0;
}

std::string choose_tech(const std::vector<std::string>& techs) {
    std::cout << "Choose your technique:" << std::endl;
    int choice = 0;
    for (size_t i = 0; i < techs.size(); i++){
        std::cout << i + 1 << ") " << techs[i] << "\n";
    }
    while (true) {
        std::cin >> choice;
        if (choice >= 1 && choice <= techs.size()) {
            std::cout << "Your technique: " << techs[choice - 1] << std::endl;
            return techs[choice - 1];
        }
        std::cout << "Invalid choice, try again: ";
    }
}

void input_stats(std::map <std::string, int>& params, int lim) {
    std::cout << "Enter your power points from 0 to 100, the limit is 100 points" << std::endl;
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

Player create_player() {
    int limit = 100;

    std::map<std::string, int> power_params = get_default_params();
    std::vector<std::string> techs = get_techs();

    std::string tech = choose_tech(techs);
    input_stats(power_params, limit);
    
    Stats stats = build_stats(power_params);

    return Player("You", stats, tech);
}

Enemy create_enemy() {
    int limit = 100;
    
    std::map<std::string, int> power_params = get_default_params();
    std::vector<std::string> techs = get_techs();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> tech_dist(0, static_cast<int>(techs.size() - 1));
    int tech_index = tech_dist(gen);
    std::string tech = techs[tech_index];
    const StatsWeight stats_weight = tech_build_reg[tech];
    Stats stats = build_stats_from_weight(stats_weight, limit);
    return Enemy("Enemy", stats, tech);
}

Stats build_stats_from_weight(const StatsWeight& stats_weight, int limit) 
{
    Stats stats;

    int total = stats_weight.backpress + stats_weight.biceps + stats_weight.fingers +
        stats_weight.high_wrist + stats_weight.low_wrist +
        stats_weight.pronation + stats_weight.rise +
        stats_weight.sidepress + stats_weight.supination +
        stats_weight.triceps;

    if (total == 0)
        return stats;

    auto distribute = [&](int weight) {
        return (limit * weight) / total;
        };

    stats.backpress = distribute(stats_weight.backpress);
    stats.biceps = distribute(stats_weight.biceps);
    stats.fingers = distribute(stats_weight.fingers);
    stats.high_wrist = distribute(stats_weight.high_wrist);
    stats.low_wrist = distribute(stats_weight.low_wrist);
    stats.pronation = distribute(stats_weight.pronation);
    stats.rise = distribute(stats_weight.rise);
    stats.sidepress = distribute(stats_weight.sidepress);
    stats.supination = distribute(stats_weight.supination);
    stats.triceps = distribute(stats_weight.triceps);

    return stats;
}

Tech to_tech(std::string& s) {
    if (s == "hook") return HOOK;
    if (s == "kingsmove") return KINGSMOVE;
    if (s == "lowhand toproll") return LHTR;
    if (s == "post toproll") return PTR;
    if (s == "flop press") return FLOP;

    return HOOK; // fallback
}

bool fight(Player player, Enemy enemy) {
    Tech tech_player = to_tech(player.tech);
    Tech tech_enemy = to_tech(enemy.tech);

    Weights fight_weights[TECH_COUNT][TECH_COUNT];
    init_weights(fight_weights);

    float matchup_coef = matchup[tech_player][tech_enemy];
    Weights matchup_weights = fight_weights[tech_player][tech_enemy];
    player.stats.backpress *= matchup_weights.backpress;
    player.stats.biceps *= matchup_weights.biceps;
    player.stats.fingers *= matchup_weights.fingers;
    player.stats.high_wrist *= matchup_weights.high_wrist;
    player.stats.low_wrist *= matchup_weights.low_wrist;
    player.stats.pronation *= matchup_weights.pronation;
    player.stats.rise *= matchup_weights.rise;
    player.stats.sidepress *= matchup_weights.sidepress;
    player.stats.supination *= matchup_weights.supination;
    player.stats.triceps *= matchup_weights.triceps;

    float score_player = matchup_coef * (player.stats.backpress + player.stats.biceps + player.stats.fingers + player.stats.high_wrist + player.stats.low_wrist
        + player.stats.pronation + player.stats.rise + player.stats.sidepress + player.stats.supination + player.stats.triceps);
    float score_enemy = enemy.stats.backpress + enemy.stats.biceps + enemy.stats.fingers + enemy.stats.high_wrist + enemy.stats.low_wrist
        + enemy.stats.pronation + enemy.stats.rise + enemy.stats.sidepress + enemy.stats.supination + enemy.stats.triceps;

    float result = score_player / score_enemy;

    if (result >= 1)
    {
        std::cout << "You win" << std::endl;
        return true;
    }

    else
    {
        std::cout << "You lose" << std::endl;
        return false;
    }
}