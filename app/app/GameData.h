#pragma once
#include <map>
#include <vector>
#include <string>

std::map<std::string, int> get_default_params();
const std::vector<std::string> get_techs();
enum Tech {
    HOOK = 0,
    KINGSMOVE,
    LHTR,
    PTR,
    FLOP,
    TECH_COUNT
}; 
extern float matchup[TECH_COUNT][TECH_COUNT];
struct Weights{
    float backpress;
    float biceps;
    float fingers;
    float high_wrist;
    float low_wrist;
    float pronation;
    float rise;
    float sidepress;
    float supination;
    float triceps;
};

void init_weights(Weights(&out)[TECH_COUNT][TECH_COUNT]);